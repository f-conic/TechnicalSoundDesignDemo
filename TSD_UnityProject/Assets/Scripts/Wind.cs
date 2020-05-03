using System.Collections;
using Cinemachine;
using UnityEngine;
using Random = UnityEngine.Random;

public class Wind : MonoBehaviour
{
	private Transform cam;
	private Renderer meshRenderer;

	public float radians;
	public float distance;
	public AK.Wwise.Event WindEvent;
	public AK.Wwise.RTPC DirectionalWindVol;
	public bool showWindDirection;

	[Header("Procedural Wind")]
	[Range(0f, 100f)]
	public float masterVolume;
	[Range(0f, 100f)]
	public float windIntensity;
	[Range(0f, 100f)]
	public float branchesVolume;
	[Range(0f, 100f)]
	public float branchesWhistleQ;
	[Range(0f, 100f)]
	public float buildingsVolume;
	[Range(0f, 100f)]
	public float leavesVolume;

	void Start()
	{
		WindEvent.Post(gameObject);
		cam = gameObject.GetComponentInParent<CinemachineVirtualCamera>().transform;
		meshRenderer = GetComponent<Renderer>();

		StartCoroutine(SetNewWindPosition(3));
	}

	private void Update()
	{
		AkSoundEngine.SetRTPCValue("RTPC_pWind_Master_Vol", masterVolume, gameObject);
		AkSoundEngine.SetRTPCValue("RTPC_pWind_Wind_Intensity", windIntensity, gameObject);
		AkSoundEngine.SetRTPCValue("RTPC_pWind_Branches_Vol", branchesVolume, gameObject);
		AkSoundEngine.SetRTPCValue("RTPC_pWind_Branches_Whistle_Q", branchesWhistleQ, gameObject);
		AkSoundEngine.SetRTPCValue("RTPC_pWind_Buildings_Vol", buildingsVolume, gameObject);
		AkSoundEngine.SetRTPCValue("RTPC_pWind_Leaves_Vol", leavesVolume, gameObject);
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