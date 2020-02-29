using Cinemachine;
using UnityEngine;

public class Wind : MonoBehaviour
{
	private Transform cam;
	public float radians;
	public float distance;
	public AK.Wwise.Event WindEvent;
	public AK.Wwise.RTPC DirectionalWindVol;

	public GameObject GroundObject;
	public float vol;

	void Start()
	{
		WindEvent.Post(gameObject);
		cam = gameObject.GetComponentInParent<CinemachineVirtualCamera>().transform;
	}

	void LateUpdate()
	{
		transform.position = new Vector3(cam.position.x + distance * Mathf.Cos(Mathf.Deg2Rad * radians), cam.transform.position.y,
			cam.position.z + distance *Mathf.Sin(Mathf.Deg2Rad * radians));
		transform.LookAt(cam);


		if (Physics.Linecast(transform.position, cam.transform.position, out var hit))
		{
			if (hit.transform.gameObject != gameObject && hit.transform.gameObject != cam.transform.gameObject && hit.transform.name != "CinemachineBrain")
			{
				Debug.Log(hit.transform.name);
				DirectionalWindVol.SetValue(gameObject, 80f);
				Debug.DrawLine(transform.position, cam.transform.position, Color.magenta);
			}
		}
		else
		{
			DirectionalWindVol.SetValue(gameObject, 0);
		}
	}
}
