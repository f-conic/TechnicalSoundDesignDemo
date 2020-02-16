using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestTrigger : MonoBehaviour
{
	public AK.Wwise.Event DialogEvent;

    void Start()
    {
	    AkSoundEngine.PostEvent("Play_Discussion", gameObject);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
