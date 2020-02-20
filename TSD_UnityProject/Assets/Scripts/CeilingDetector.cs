using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CeilingDetector : MonoBehaviour
{
	private RaycastHit hit;
	private bool isActive;

	private void Update()
	{
		// There's probably a better way of doing this.
		if (Camera.main != null)
		{
			gameObject.transform.position = Camera.main.transform.position;
		}

		if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.up), out hit, 100f))
		{
			if (!isActive)
			{
				Debug.Log("<color=green>Detected a ceiling!</color>");
				AkSoundEngine.SetState("CeilingState", "Active");
				isActive = true;
			}
		}
		else
		{
			AkSoundEngine.SetState("CeilingState", "Inactive");
			isActive = false;
		}
	}
}
