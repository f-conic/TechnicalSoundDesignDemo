using Boo.Lang;
using Cinemachine;
using UnityEngine;

public class CeilingDetector : MonoBehaviour
{
	private RaycastHit hit;
	private bool isActive;
	private Camera mainCam;
	private GameObject virtualCamera;
	private Transform hitTransform;

	private void Start()
	{
		mainCam = Camera.main;
	}

	private Vector3 GetGeometryData(Vector3 pos, Color color)
	{
		// Do raycasting only when needed.
		if (Physics.Raycast(transform.position, pos, out hit, 50f))
		{
			hitTransform = hit.transform;
			return pos;
		}

		return new Vector3(0,0,0);
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

		var rayCasts = new List<Vector3>()
		{
			GetGeometryData(transform.TransformDirection(Vector3.up), Color.green),
			GetGeometryData(transform.TransformDirection(Vector3.forward), Color.blue),
			GetGeometryData(transform.TransformDirection(Vector3.back), Color.cyan),
			GetGeometryData(transform.TransformDirection(Vector3.left), Color.yellow),
			GetGeometryData(transform.TransformDirection(Vector3.right), Color.red),
		};

		ProcessRaycastData(rayCasts);
	}

	private void ProcessRaycastData(List<Vector3> rays)
	{
		foreach (var ray in rays)
		{
			if (ray != Vector3.zero)
			{
				Debug.DrawRay(transform.position, ray * 50, Color.blue);

				if (ray == Vector3.up)
				{
					AddCeilingReverb(true, hitTransform);
				}
				else
				{
					AddCeilingReverb(false, null);
				}
			}
		}
	}

	private void AddCeilingReverb(bool isCeiling, Transform hitTransform)
	{
		if (isCeiling && hitTransform != null)
		{
			if (!isActive && hitTransform.transform.gameObject != gameObject && 
			    hitTransform.transform.gameObject != mainCam.transform.gameObject)
			{
				Debug.Log("<color=green>Detected a ceiling!</color>");
				AkSoundEngine.SetState("CeilingState", "Active");
				Debug.Log("<color=green>Ceiling state: True</color>");
				isActive = true;
			}
		}
		else if (!isCeiling)
		{
			AkSoundEngine.SetState("CeilingState", "Inactive");
			isActive = false;
		}
	}
}
