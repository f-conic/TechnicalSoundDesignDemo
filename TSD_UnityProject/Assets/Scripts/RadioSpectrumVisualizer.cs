using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RadioSpectrumVisualizer : MonoBehaviour
{
	private SoundEmitter emitter;
	private Shader emissiveColor;
	private float emission;

    void Start()
    {
	    emitter = GetComponent<SoundEmitter>();
	    emissiveColor = GetComponent<Shader>();
    }

    void Update()
    {
	    Renderer renderer = GetComponent<Renderer>();
	    Material mat = renderer.material;

	    emission = (emitter.RtpcData * -1 / 10000) / 2;

	    Color baseColor = new Color(191f,15f,0f);
	    Color finalColor = baseColor * Mathf.LinearToGammaSpace(emission);

	    mat.SetColor("_EmissionColor", finalColor);
	}
}
