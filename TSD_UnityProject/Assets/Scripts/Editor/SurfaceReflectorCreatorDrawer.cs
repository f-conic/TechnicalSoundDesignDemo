using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

[CustomEditor(typeof(SurfaceReflectorCreator))]
public class SurfaceReflectorCreatorDrawer : Editor
{
	public override void OnInspectorGUI()
	{
		SurfaceReflectorCreator surfaceCreator = (SurfaceReflectorCreator) target;
		DrawDefaultInspector();

		if (GUILayout.Button("Make Surface Reflector"))
		{
			surfaceCreator.CreateSurfaceReflector();
		}
	}
}