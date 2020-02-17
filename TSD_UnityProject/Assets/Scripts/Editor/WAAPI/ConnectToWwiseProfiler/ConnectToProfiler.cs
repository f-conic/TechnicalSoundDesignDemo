using System;
using System.Diagnostics;
using UnityEngine;

public class ConnectToProfiler
{
	public static void Connect()
	{
		try
		{
			var dataPath = Application.dataPath + @"/Scripts/Editor/WAAPI/ConnectToWwiseProfiler/ConnectToProfiler.bat";
			var process = new Process();
			process.StartInfo.FileName = dataPath;
			process.Start();
		}
		catch (Exception e)
		{
			UnityEngine.Debug.LogError(e);
		}
	} 
}
