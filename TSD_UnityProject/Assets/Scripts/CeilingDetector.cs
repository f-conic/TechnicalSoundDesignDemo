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
				gameObject.transform.eulerAngles = new Vector3(0, virtualCamera.transform.eulerAngles.y, 0);
			}
		}

		// Up
		if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.up), out hit, 10f))
		{
			Debug.Log("Up");
			AddCeilingReverb(true);
		}
		else
		{
			AddCeilingReverb(false);
		}

		// Left
		if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.left), out hit, 10f))
		{
			Debug.Log("Left");
		}

		// Right
		if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.right), out hit, 10f))
		{
			Debug.Log("Right");
		}

		DrawRays();
	}

	private void DrawRays()
	{
		Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.forward) * 50, Color.blue);
		Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.back) * 50, Color.blue);
		Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.up) * 50, Color.green);
		Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.right) * 50, Color.red);
		Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.left) * 50, Color.red);
	}

	private void AddCeilingReverb(bool isCeiling)
	{
		if (isCeiling)
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
