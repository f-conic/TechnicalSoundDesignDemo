using System.Collections;
using System.Collections.Generic;
using Cinemachine;
using UnityEngine;

public class CameraSwitcher : MonoBehaviour
{
	public GameObject DollyCam;
	public GameObject FreeLookCam;
	private bool isActive;

	private void Start()
	{
		DollyCam.SetActive(false);
		FreeLookCam.SetActive(true);
	}

	void Update()
    {
	    if (Input.GetKeyDown(KeyCode.H))
	    {
		    if (!isActive)
		    {
			    DollyCam.SetActive(false);
			    FreeLookCam.SetActive(true);

			    isActive = true;
			}
		    else
		    {
				DollyCam.SetActive(true);
				FreeLookCam.SetActive(false);
			    isActive = false;
		    }
	    }       
    }
}
