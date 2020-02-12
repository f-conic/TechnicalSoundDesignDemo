using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grenade : MonoBehaviour
{
	public float radius;

	private void Awake()
	{
		AkSoundEngine.RegisterEmitter(gameObject, new AkEmitterSettings());
		AkSoundEngine.SetObjectPosition(gameObject, transform);
	}

	private void CheckIncidental(Vector3 center, float radius)
	{
		Collider[] hitColliders = Physics.OverlapSphere(center, radius);

		int i = 0;

		while (i < hitColliders.Length)
		{
			hitColliders[i].SendMessage("AddDamage");
			i++;
		}
	}

	private void LateUpdate()
	{
		if (Input.GetKeyDown(KeyCode.G))
		{		
			AkSoundEngine.PostEvent("Grenade_Explosion", gameObject);
			CheckIncidental(gameObject.transform.position, radius);
		}
	}
}
