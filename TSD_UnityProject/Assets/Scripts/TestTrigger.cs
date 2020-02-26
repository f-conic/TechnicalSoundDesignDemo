using System.Collections;
using System.Collections.Generic;
using AK.Wwise;
using Cinemachine;
using UnityEngine;

public class TestTrigger : MonoBehaviour
{
	private Camera mainCam;
	private GameObject virtualCamera;

	void Start()
	{
		mainCam = Camera.main;
	}

	void Update()
	{
		GetObstructionState();
	}

	private bool GetObstructionState()
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
				return false;
			}
		}

		if (Physics.Linecast(transform.position, virtualCamera.transform.position, out var hit))
		{
			// This is horrible. But we're just testing right now.
			//if (hit.transform.gameObject.layer != laye)
			//{
			//	return true;
			//}
		}

		return false;
	}
}
