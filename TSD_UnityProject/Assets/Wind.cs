using Cinemachine;
using UnityEngine;

public class Wind : MonoBehaviour
{
	private Transform cam;
	public float radians;
	public float distance;

	void Start()
	{
		cam = gameObject.GetComponentInParent<CinemachineVirtualCamera>().transform;
	}

	void LateUpdate()
	{
		transform.position = new Vector3(cam.position.x + distance * Mathf.Cos(Mathf.Deg2Rad * radians), cam.transform.position.y,
			cam.position.z + distance *Mathf.Sin(Mathf.Deg2Rad * radians));
		transform.LookAt(cam);
	}
}
