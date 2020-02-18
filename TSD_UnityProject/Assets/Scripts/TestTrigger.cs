using System.Collections;
using System.Collections.Generic;
using AK.Wwise;
using UnityEngine;

public class TestTrigger : MonoBehaviour
{
	public AK.Wwise.Event DialogEvent;

	private void OnTriggerEnter(Collider other)
	{
		var room = other.gameObject.GetComponent<AkRoom>();
		
		if (room != null)
		{
			
		}
	}
}
