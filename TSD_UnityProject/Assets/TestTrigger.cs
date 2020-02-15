using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestTrigger : MonoBehaviour
{
	public AK.Wwise.Event DialogEvent;

    void Start()
    {
	    AkSoundEngine.RegisterGameObj(gameObject);
	    DialogEvent.Post(gameObject);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
