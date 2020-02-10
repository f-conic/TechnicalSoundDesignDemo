using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpatialAudioEmitter : AkSpatialAudioBase
{
	public AK.Wwise.Event SoundEvent;
	public AK.Wwise.AuxBus reflectAuxBus = new AK.Wwise.AuxBus();
	public float reflectionMaxPathLength = 1000;
	public float reflectionsAuxBusGain = 1;
	public uint reflectionsOrder = 1;
	public float roomReverbAuxBusGain = 1;
	public uint diffractionMaxEdges = 0;
	public uint diffractionMaxPaths = 0;
	public uint diffractionMaxPathLength = 0;

	private void Start()
	{
		AkSoundEngine.RegisterGameObj(gameObject);

		var emitterSettings = new AkEmitterSettings();

		emitterSettings.reflectAuxBusID = reflectAuxBus.Id;
		emitterSettings.reflectionMaxPathLength = reflectionMaxPathLength;
		emitterSettings.reflectionsAuxBusGain = reflectionsAuxBusGain;
		emitterSettings.reflectionsOrder = reflectionsOrder;
		emitterSettings.reflectorFilterMask = unchecked((uint)-1);
		emitterSettings.roomReverbAuxBusGain = roomReverbAuxBusGain;
		emitterSettings.useImageSources = 0;
		emitterSettings.diffractionMaxEdges = diffractionMaxEdges;
		emitterSettings.diffractionMaxPaths = diffractionMaxPaths;
		emitterSettings.diffractionMaxPathLength = diffractionMaxPathLength;

		if (AkSoundEngine.RegisterEmitter(gameObject, emitterSettings) == AKRESULT.AK_Success)
		{
			SetGameObjectInRoom();
		}

		AkSoundEngine.SetObjectPosition(gameObject, transform);
		SoundEvent.Post(gameObject);
	}
}
