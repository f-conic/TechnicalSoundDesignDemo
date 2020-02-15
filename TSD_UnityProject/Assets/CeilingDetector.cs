using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CeilingDetector : MonoBehaviour
{
	private RaycastHit hit;
	private int lastGameObjectId;

	private void LateUpdate()
	{
		// There's probably a better way of doing this.
		if (Camera.main != null)
		{
			gameObject.transform.position = Camera.main.transform.position;
		}

		if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.up), out hit, 100f))
		{
			var gameObjectId = hit.transform.gameObject.GetInstanceID();
			if (lastGameObjectId != gameObjectId)
			{
				if (hit.transform.GetComponent<BoxCollider>() == null)
				{
					CreateCollider(hit);
				}

				lastGameObjectId = gameObjectId;
			}
		}
	}

	private void CreateCollider(RaycastHit hitObject)
	{
		var room = new GameObject("Room");
		room.gameObject.transform.SetParent(hitObject.transform, false);
		
		var roomCollider = room.AddComponent<BoxCollider>();
		var distanceToFloor = GetDistanceToFloor(hitObject);

		roomCollider.size = new Vector3(1f, 1f, distanceToFloor);
		roomCollider.center = new Vector3(0f, 0f, hitObject.transform.position.y - distanceToFloor/2f);

		Debug.Log("<color=green>Found ceiling! Creating room.</color>");
	}

	private float GetDistanceToFloor(RaycastHit ceiling)
	{
		// This is fine, we only do it once.
		var floor = GameObject.FindWithTag("Floor");

		if (floor != null)
		{
			var distance = Vector3.Distance(floor.transform.position, ceiling.transform.position);
			return distance;
		}

		return 0f;
	}
}
