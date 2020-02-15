using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grenade : MonoBehaviour
{
	public float SphereOverlapRadius;
	public float ExplosionForce = 1000f;
	public LayerMask Layer;
	private bool isExploding;

	private void Awake()
	{
		AkSoundEngine.RegisterEmitter(gameObject, new AkEmitterSettings());
		AkSoundEngine.SetObjectPosition(gameObject, transform);
	}

	private Collider[] CheckIncidental(Vector3 center, float radius)
	{
		Collider[] hitColliders = Physics.OverlapSphere(center, radius, Layer.value);

		return hitColliders;
	}

	private void Update()
	{
		if (Input.GetKeyDown(KeyCode.G))
		{
			PlayGrenadeExplosion(gameObject);
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
		AkSoundEngine.RegisterGameObj(i.gameObject);
		AkSoundEngine.SetRTPCValue("RTPC_Incidental_Delay", GetIncidentalDifference(i.gameObject).Item1, i.gameObject);
		AkSoundEngine.SetRTPCValue("RTPC_Incidental", 1.0f - (force / SphereOverlapRadius), i.gameObject);

		AkSoundEngine.PostEvent("Play_Incidental", i.gameObject);
	}

	private float GetBlastForce(Collider i)
	{
		var force = (i.gameObject.transform.position - gameObject.transform.position).magnitude;
		return force;
	}

	private void PlayGrenadeExplosion(GameObject go)
	{
		var explosionDistanceToCamera = Vector3.Distance(go.transform.position, Camera.main.transform.position);

		AkSoundEngine.SetRTPCValue("RTPC_Grenade_Explosion_Distance", explosionDistanceToCamera, go);
		AkSoundEngine.PostEvent("grenade_explosion", go);

		isExploding = true;
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

	IEnumerator SphereDrawCooldown()
	{
		if (isExploding)
		{
			Gizmos.color = Color.cyan;
			Gizmos.DrawWireSphere(transform.position, SphereOverlapRadius);
		}

		yield return new WaitForSeconds(2f);

		isExploding = false;
	}
}
