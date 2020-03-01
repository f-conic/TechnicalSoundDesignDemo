using System;
using UnityEngine;

public class SoundEmitter : MonoBehaviour
{
	public AK.Wwise.Event[] SoundEvent;

	public bool drawFirstOrderReflections;
	public bool drawSecondOrderReflections;
	public bool drawHigherOrderReflections;
	public bool drawDiffractionPaths;
	public float RtpcData;

	private void Start()
	{
		try
		{
			SoundEvent[1].Post(gameObject);
		}
		catch (IndexOutOfRangeException)
		{
			Debug.LogError($"Couldn't find any events on: [{gameObject.transform.name}] " +
			               "\n Make sure you populate the list with at least one event.");
		}
	}

	void Update()
	{
		var query = (int) AkQueryRTPCValue.RTPCValue_GameObject;
		foreach (var e in SoundEvent)
		{
			AkSoundEngine.GetRTPCValue("RTPC_SpectrumData", gameObject, e.Id, out RtpcData, ref query);
		}

		// Used for demo.
		if (Input.GetKeyDown(KeyCode.Keypad1))
		{
			Debug.Log(SoundEvent[0].Name);
			SoundEvent[0].Post(gameObject);
		}
	}

	private void OnDrawGizmos()
	{
		if (!UnityEngine.Application.isPlaying || !AkSoundEngine.IsInitialized())
			return;

		if (debugDrawData == null)
			debugDrawData = new DebugDrawData();

		if (drawFirstOrderReflections || drawSecondOrderReflections || drawHigherOrderReflections)
			debugDrawData.DebugDrawEarlyReflections(gameObject, drawFirstOrderReflections, drawSecondOrderReflections, drawHigherOrderReflections);

		if (drawDiffractionPaths)
			debugDrawData.DebugDrawDiffraction(gameObject);
	}

	private class DebugDrawData
	{
		// Constants
		private const uint kMaxIndirectPaths = 64;
		private const uint kMaxDiffractionPaths = 16;
		private readonly Color32 colorLightYellow = new Color32(255, 255, 121, 255);
		private readonly Color32 colorDarkYellow = new Color32(164, 164, 0, 255);
		private readonly Color32 colorLightOrange = new Color32(255, 202, 79, 255);
		private readonly Color32 colorDarkOrange = new Color32(164, 115, 0, 255);
		private readonly Color32 colorLightRed = new Color32(252, 177, 162, 255);
		private readonly Color32 colorDarkRed = new Color32(169, 62, 39, 255);
		private readonly Color32 colorLightGrey = new Color32(75, 75, 75, 255);
		private readonly Color32 colorGreen = new Color32(38, 113, 88, 255);
		private const float radiusSphere = 0.25f;

		// Calculated path info
		private readonly AkReflectionPathInfoArray indirectPathInfoArray = new AkReflectionPathInfoArray((int)kMaxIndirectPaths);
		private readonly AkDiffractionPathInfoArray diffractionPathInfoArray = new AkDiffractionPathInfoArray((int)kMaxDiffractionPaths);

		public void DebugDrawEarlyReflections(GameObject gameObject, bool firstOrder, bool secondOrder, bool higherOrder)
		{
			var listenerPosition = Vector3.zero;
			var emitterPosition = Vector3.zero;
			uint numValidPaths = (uint)indirectPathInfoArray.Count();
			if (AkSoundEngine.QueryReflectionPaths(gameObject, ref listenerPosition, ref emitterPosition, indirectPathInfoArray, out numValidPaths) != AKRESULT.AK_Success)
				return;

			for (var idxPath = (int)numValidPaths - 1; idxPath >= 0; --idxPath)
			{
				var path = indirectPathInfoArray[idxPath];
				var order = path.numReflections;

				var colorLight = colorLightRed;
				var colorDark = colorDarkRed;

				if (order == 1)
				{
					if (!firstOrder)
						continue;

					colorLight = colorLightYellow;
					colorDark = colorDarkYellow;
				}
				else if (order == 2)
				{
					if (!secondOrder)
						continue;

					colorLight = colorLightOrange;
					colorDark = colorDarkOrange;
				}
				else if (order > 2 && !higherOrder)
					continue;

				var listenerPt = listenerPosition;

				for (var idxSeg = (int)path.numPathPoints - 1; idxSeg >= 0; --idxSeg)
				{
					var pt = path.GetPathPoint((uint)idxSeg);

					Debug.DrawLine(listenerPt, pt, path.isOccluded ? colorLightGrey : colorLight);

					Gizmos.color = path.isOccluded ? colorLightGrey : colorLight;
					Gizmos.DrawWireSphere(pt, radiusSphere / 2 / order);

					if (!path.isOccluded)
					{
						var surface = path.GetAcousticSurface((uint)idxSeg);
						DrawLabelInFrontOfCam(pt, surface.strName, 100000, colorDark);
					}

					float dfrnAmount = path.GetDiffraction((uint)idxSeg);
					if (dfrnAmount > 0)
					{
						string dfrnAmountStr = dfrnAmount.ToString("0.#%");
						DrawLabelInFrontOfCam(pt, dfrnAmountStr, 100000, colorDark);
					}

					listenerPt = pt;
				}

				if (!path.isOccluded)
				{
					// Finally the last path segment towards the emitter.
					Debug.DrawLine(listenerPt, emitterPosition, path.isOccluded ? colorLightGrey : colorLight);
				}
			}
		}

		public void DebugDrawDiffraction(GameObject gameObject)
		{
			var listenerPosition = Vector3.zero;
			var emitterPosition = Vector3.zero;
			uint numValidPaths = (uint)diffractionPathInfoArray.Count();
			if (AkSoundEngine.QueryDiffractionPaths(gameObject, ref listenerPosition, ref emitterPosition, diffractionPathInfoArray, out numValidPaths) != AKRESULT.AK_Success)
				return;

			for (var idxPath = (int)numValidPaths - 1; idxPath >= 0; --idxPath)
			{
				var path = diffractionPathInfoArray[idxPath];
				if (path.nodeCount <= 0)
					continue;

				var prevPt = listenerPosition;

				for (var idxSeg = 0; idxSeg < (int)path.nodeCount; ++idxSeg)
				{
					var pt = path.GetNodes((uint)idxSeg);
					Debug.DrawLine(prevPt, pt, colorGreen);

					float angle = path.GetAngles((uint)idxSeg) / Mathf.PI;
					if (angle > 0)
					{
						string angleStr = angle.ToString("0.#%");
						DrawLabelInFrontOfCam(pt, angleStr, 100000, colorGreen);
					}

					prevPt = pt;
				}

				Debug.DrawLine(prevPt, emitterPosition, colorGreen);
			}
		}
	}

	private static DebugDrawData debugDrawData = null;

	private static void DrawLabelInFrontOfCam(Vector3 position, string name, float distance, Color c)
	{
		var style = new GUIStyle();
		var oncam = Camera.current.WorldToScreenPoint(position);

		if (oncam.x >= 0 && oncam.x <= Camera.current.pixelWidth && oncam.y >= 0 &&
			oncam.y <= Camera.current.pixelHeight && oncam.z > 0 && oncam.z < distance)
		{
			style.normal.textColor = c;
			UnityEditor.Handles.Label(position, name, style);
		}
	}
}
