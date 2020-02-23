using System.Collections;
using System.Collections.Generic;
using Cinemachine;
using UnityEngine;

public class CeilingDetector : MonoBehaviour
{
	private RaycastHit hit;
	private bool isActive;
	private Camera mainCam;
	private GameObject virtualCamera;

	private void Start()
	{
		mainCam = Camera.main;
	}

	private void Update()
	{
		// There's probably a better way of doing this.
		if (mainCam != null)
		{
			try
			{
				virtualCamera = mainCam.gameObject.GetComponent<CinemachineBrain>().ActiveVirtualCamera
					.VirtualCameraGameObject;
			}
			catch
			{
				return;
			}

			if (virtualCamera != null)
			{
				gameObject.transform.position = virtualCamera.transform.position;
			}
		}

		if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.up), out hit, 100f))
		{
			if (!isActive && hit.transform.gameObject != gameObject && hit.transform.gameObject != mainCam.transform.gameObject)
			{
				Debug.Log("<color=green>Detected a ceiling!</color>");
				AkSoundEngine.SetState("CeilingState", "Active");
				Debug.Log("<color=green>Ceiling state: True</color>");
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
