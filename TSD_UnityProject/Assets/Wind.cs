using System.Collections;
using Cinemachine;
using UnityEngine;

public class Wind : MonoBehaviour
{
	private Transform cam;
	private Renderer meshRenderer;

	public float radians;
	public float distance;
	public AK.Wwise.Event WindEvent;
	public AK.Wwise.RTPC DirectionalWindVol;
	public GameObject GroundObject;
	public bool showWindDirection;

	void Start()
	{
		WindEvent.Post(gameObject);
		cam = gameObject.GetComponentInParent<CinemachineVirtualCamera>().transform;
		meshRenderer = GetComponent<Renderer>();

		StartCoroutine(SetNewWindPosition(3));
	}

	void LateUpdate()
	{
		transform.position = new Vector3(cam.position.x + distance * Mathf.Cos(Mathf.Deg2Rad * radians),
			cam.transform.position.y,
			cam.position.z + distance * Mathf.Sin(Mathf.Deg2Rad * radians));

		transform.LookAt(cam);


		if (Physics.Linecast(transform.position, cam.transform.position, out var hit))
		{
			if (hit.transform.gameObject != gameObject && hit.transform.gameObject != cam.transform.gameObject &&
			    hit.transform.name != "CinemachineBrain")
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

		meshRenderer.enabled = showWindDirection;
	}

	private bool isRunning;
	private IEnumerator SetNewWindPosition(float duration)
	{
		while (true)
		{
			if (isRunning)
			{
				// Don't change value if we're in the middle of a change. Bail out.
				yield break;
			}

			isRunning = true;
			
			var newPos = Random.Range(0, 360);

			// Pick a random time until next wind change.
			var waitForNextPos = Random.Range(10, 20);

			var counter = 0f;
			var startPos = radians;
			var endPos = radians + newPos;

			while (counter < duration)
			{
				counter += Time.deltaTime;
				radians = Mathf.Lerp(startPos, endPos, counter / duration);
				yield return null;
			}

			yield return new WaitForSeconds(waitForNextPos);
			isRunning = false;
		}
	}
}