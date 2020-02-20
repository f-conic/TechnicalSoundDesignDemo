using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RadioSpectrumVisualizer : MonoBehaviour
{
	public SoundEmitter Emitter;

    void Start()
    {
	    Emitter = GetComponent<SoundEmitter>();
    }

    void Update()
    {
    }
}
