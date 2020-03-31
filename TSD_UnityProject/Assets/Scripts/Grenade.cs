using System.Collections;
using System.Collections.Generic;
using System.Linq;
using Cinemachine;
using UnityEngine;
using UnityEngine.LowLevel;

public class Grenade : MonoBehaviour
{
	public float SphereOverlapRadius;
	public float ExplosionForce = 1000f;
	public LayerMask Layer;
	public GameObject GrenadeVFX;
	public GameObject[] objectsToIgnore;

	[Header("Camera Shaker")]
	public float ShakeAmplitude;
	public float ShakeFrequency;
	public float ShakeDuration;
	private float ShakeElapsedTime;

	private List<GameObject> instantiatedGrenadesVFX = new List<GameObject>();
	private GameObject virtualCamera;
	private bool isExploding;
	private CinemachineBasicMultiChannelPerlin virtualCameraNoise;

	private Collider[] CheckIncidental(Vector3 center, float radius)
	{
		Collider[] hitColliders = Physics.OverlapSphere(center, radius, Layer.value);

		return hitColliders;
	}

	private void Update()
	{
		if (Input.GetKeyDown(KeyCode.G))
		{
			// Get the active virtual camera because of Cinemachine.
			virtualCamera = Camera.main.gameObject.GetComponent<CinemachineBrain>().ActiveVirtualCamera
				.VirtualCameraGameObject;

			if (virtualCamera != null)
			{
				var cinemachineVirtualCamera = virtualCamera.GetComponent<CinemachineVirtualCamera>();
				virtualCameraNoise = cinemachineVirtualCamera.GetCinemachineComponent<CinemachineBasicMultiChannelPerlin>();
			}

			var obstructionState = GetObstructionState();

			PlayGrenadeExplosion(gameObject, obstructionState);

			var incidentalObjects = CheckIncidental(transform.position, SphereOverlapRadius);

			foreach (var i in incidentalObjects)
			{
				var rb = i.GetComponent<Rigidbody>();

				if (rb != null)
				{
					rb.AddExplosionForce(ExplosionForce, transform.position, SphereOverlapRadius);

					// Linearly assume the force on an object. Ie. closer to the edge of the radius = less force.
					var force = GetBlastForce(i);
					PlayIncidental(force, i);
				}
			}
		}
	}

	private void PlayIncidental(float force, Collider i)
	{
		var incidentalEventRef = (IncidentalAudio)i.gameObject.GetComponent(typeof(IncidentalAudio));

		if (incidentalEventRef != null)
		{
			AkSoundEngine.RegisterGameObj(i.gameObject);
			AkSoundEngine.SetRTPCValue("RTPC_Incidental_Delay", GetIncidentalDifference(i.gameObject).Item1, i.gameObject);
			AkSoundEngine.SetRTPCValue("RTPC_Incidental", 1.0f - (force / SphereOverlapRadius), i.gameObject);

			AkSoundEngine.PostEvent(incidentalEventRef.EventName, i.gameObject);
		}
	}

	private float GetBlastForce(Collider i)
	{
		var force = (i.gameObject.transform.position - gameObject.transform.position).magnitude;
		return force;
	}

	private void PlayGrenadeExplosion(GameObject go, bool isObstructed)
	{
        instantiatedGrenadesVFX.Add(Instantiate(GrenadeVFX, transform.position, transform.rotation));
		var explosionDistanceToCamera = Vector3.Distance(go.transform.position, virtualCamera.transform.position);

		// Only shake when we're close to the explosion.
		if (explosionDistanceToCamera < 20f)
		{
			StartCoroutine(ShakeCamera(ShakeDuration));
		}

		if (!isObstructed)
        {
	        AkSoundEngine.SetRTPCValue("RTPC_Grenade_Explosion_Distance", explosionDistanceToCamera, go);
	        AkSoundEngine.PostEvent("grenade_explosion", go, (uint)AkCallbackType.AK_EndOfEvent, OnCallback, null);
		}
        else
        {
	        AkSoundEngine.SetRTPCValue("RTPC_Grenade_Explosion_Distance", 50f, go);
	        AkSoundEngine.PostEvent("grenade_explosion", go, (uint)AkCallbackType.AK_EndOfEvent, OnCallback, null);
		}

		isExploding = true;
	}

    private void OnCallback(object in_cookie, AkCallbackType cb, object in_info)
    {
        // Destroy VFX when event finishes.
        foreach(var g in instantiatedGrenadesVFX)
        {
            Destroy(g);
        }
    }

	private (float, float) GetIncidentalDifference(GameObject incidentalObject)
	{
		// We can calculate the time it takes for the sound to reach the object by
		// using the formula t = d/s where we assume that s is a constant of 345m/s. 
		// Note that this isn't completely accurate as the sync will be dependent on the main thread. Ie. FPS.
		
		float incidentalDistanceToExplosion = Vector3.Distance(incidentalObject.transform.position, gameObject.transform.position);
		float time = incidentalDistanceToExplosion / 345;

		return (time, incidentalDistanceToExplosion);
	}

	private void OnDrawGizmos()
	{
		if (isExploding)
		{
			StartCoroutine(SphereDrawCooldown());
		}
	}

	IEnumerator ShakeCamera(float shakeDuration)
	{
		virtualCameraNoise.m_AmplitudeGain = ShakeAmplitude;
		virtualCameraNoise.m_FrequencyGain = ShakeFrequency;

		yield return new WaitForSeconds(shakeDuration);

		virtualCameraNoise.m_AmplitudeGain = 0f;
		ShakeElapsedTime = 0f;
	}

	public Color DebugSphereColor;
	IEnumerator SphereDrawCooldown()
	{
		var rend = GetComponent<Renderer>();

		if (isExploding)
		{
			rend.enabled = false;

			Gizmos.color = DebugSphereColor;
			Gizmos.DrawSphere(transform.position, SphereOverlapRadius);
		}

		yield return new WaitForSeconds(4f);

		rend.enabled = true;
		isExploding = false;
	}

	private bool GetObstructionState()
	{
		if (Physics.Linecast(transform.position, virtualCamera.transform.position, out var hit))
		{
			// Horrible check. But temporary testing.
			if (objectsToIgnore.Contains(hit.transform.gameObject))
			{
				return false;
			}
			return true;
		}
		return false;
	}
}
