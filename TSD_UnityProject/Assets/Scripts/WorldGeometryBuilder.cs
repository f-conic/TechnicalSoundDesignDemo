using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WorldGeometryBuilder : MonoBehaviour
{
	private GameObject cube;
	private List<GameObject> cubeList = new List<GameObject>();

	void Update()
    {
	    if (Input.GetKeyDown(KeyCode.B))
	    {
		    cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
			cube.transform.position = transform.position + (transform.forward * 20);
		    var surfaceReflector = cube.AddComponent<AkSurfaceReflector>();
		    var aKGameObject = cube.AddComponent<AkGameObj>();
		    cube.AddComponent<Rigidbody>();
			cubeList.Add(cube);
	    }

	    if (cube != null)
	    {
		    var mouseAxis = Input.GetAxis("Mouse ScrollWheel");
		    cube.transform.localScale = cube.transform.localScale + new Vector3(mouseAxis, mouseAxis, mouseAxis);
	    }

	    if (Input.GetKeyDown(KeyCode.Q))
	    {
		    foreach (var cube in cubeList)
		    {
				Destroy(cube);
		    }

			cubeList.Clear();
	    }
	}
}
