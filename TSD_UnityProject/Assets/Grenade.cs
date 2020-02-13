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

	private void LateUpdate()
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
					AkSoundEngine.PostEvent("Play_Incidental", i.gameObject);
					rb.AddExplosionForce(ExplosionForce, Vector3.forward, ExplosionRadius);
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
}
