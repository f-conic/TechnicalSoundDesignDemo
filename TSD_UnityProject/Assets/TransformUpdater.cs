using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TransformUpdater : MonoBehaviour
{
	void Start()
	{
		var pos = gameObject.transform.position;

		gameObject.transform.position = new Vector3(pos.x + 1f, pos.y, pos.z);
	}
}
