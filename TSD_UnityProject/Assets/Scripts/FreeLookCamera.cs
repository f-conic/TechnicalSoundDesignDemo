using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Characters.FirstPerson;

public class FreeLookCamera : MonoBehaviour
{
	[SerializeField]
	private float movementSpeed = 1f;
	[SerializeField]
	private bool lockCursor = true;

	private float lookAngle;
	private float tiltAngle;
	private Vector3 pivotEulers;
	private Quaternion pivotTargetRot;
	private Quaternion transformTargetRot;
	private MouseLook mouseLook;
	public Transform cameraTransform;
	private Transform pivot;

	private void Awake()
	{
		cameraTransform = GetComponentInChildren<Camera>().transform;

		Cursor.lockState = lockCursor ? CursorLockMode.Locked : CursorLockMode.None;
		Cursor.visible = !lockCursor;
	}

	private void Update()
	{
		Rotate();
		HandleKeyboardMovement();
	}

	void Rotate()
	{
		float newRotationX = transform.localEulerAngles.y + Input.GetAxis("Mouse X") * 3f;
		float newRotationY = transform.localEulerAngles.x - Input.GetAxis("Mouse Y") * 3f;
		transform.localEulerAngles = new Vector3(newRotationY, newRotationX, 0f);
	}

	private void HandleKeyboardMovement()
	{
		if (Input.GetKey(KeyCode.W))
		{
			transform.position = transform.position + (transform.forward * movementSpeed * Time.deltaTime);
		}
		if (Input.GetKey(KeyCode.A))
		{
			transform.position = transform.position + (-transform.right * movementSpeed * Time.deltaTime);
		}
		if (Input.GetKey(KeyCode.S))
		{
			transform.position = transform.position + (-transform.forward * movementSpeed * Time.deltaTime);
		}
		if (Input.GetKey(KeyCode.D))
		{
			transform.position = transform.position + (transform.right * movementSpeed * Time.deltaTime);
		}
	}
}
