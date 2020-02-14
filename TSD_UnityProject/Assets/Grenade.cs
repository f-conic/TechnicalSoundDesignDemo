using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grenade : MonoBehaviour
{
	public float SphereOverlapRadius;
	public float ExplosionForce = 1000f;
	public float ExplosionRadius = 1000f;
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
			isExploding = true;
			AkSoundEngine.PostEvent("Grenade_Explosion", gameObject);
			var incidentalObjects = CheckIncidental(transform.position, SphereOverlapRadius);

			foreach (var i in incidentalObjects)
			{
				var rb = i.GetComponent<Rigidbody>();

				if (rb != null)
				{
					AkSoundEngine.RegisterGameObj(i.gameObject);
					AkSoundEngine.SetRTPCValue("RTPC_Incidental_Delay", GetTimeDifference(i.gameObject), i.gameObject);

					rb.AddExplosionForce(ExplosionForce, Vector3.forward, ExplosionRadius);

					AkSoundEngine.PostEvent("Play_Incidental", i.gameObject);

					isExploding = false;
				}
			}
		}
	}

	private void OnDrawGizmos()
	{
		if (isExploding)
		{
			Gizmos.color = Color.cyan;
			Gizmos.DrawWireSphere(transform.position, SphereOverlapRadius);
		}
	}

	private float GetTimeDifference(GameObject incidentalObject)
	{
		// We can calculate the time it takes for the sound to reach the object by
		// using the formula t = d/s where we assume that s is a constant of 345m/s. 
		// Note that this isn't completely accurate as the sync will be dependent on the main thread. Ie. FPS.
		
		float distance = Vector3.Distance(incidentalObject.transform.position, gameObject.transform.position);
		float time = distance / 345;

		return time;
	}
}
