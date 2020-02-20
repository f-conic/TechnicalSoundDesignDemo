using UnityEngine;

public class SurfaceReflectorCreator : MonoBehaviour
{
	private AkGameObj akGameObject;
	private AkSurfaceReflector akSurfaceReflector;
	private BoxCollider boxCollider;
	private Rigidbody rigidBody;
	private MeshCollider meshCollider;
	private MeshRenderer meshRenderer;

	public void CreateSurfaceReflector()
	{

		boxCollider = gameObject.GetComponent<BoxCollider>();
		akSurfaceReflector = gameObject.GetComponent<AkSurfaceReflector>();
		akGameObject = gameObject.GetComponent<AkGameObj>();
		rigidBody = gameObject.GetComponent<Rigidbody>();
		meshCollider = gameObject.GetComponent<MeshCollider>();
		meshRenderer = gameObject.GetComponent<MeshRenderer>();

		// Check if we have any components there already.
		if (meshCollider != null)
		{
			DestroyImmediate(meshCollider);
		}

		if (boxCollider != null)
		{
			DestroyImmediate(boxCollider);
		}

		if (akSurfaceReflector != null)
		{
			DestroyImmediate(akSurfaceReflector);
		}

		if (akGameObject != null)
		{
			DestroyImmediate(akGameObject);
		}

		if (rigidBody != null)
		{
			DestroyImmediate(rigidBody);
		}

		if (meshRenderer != null)
		{
			DestroyImmediate(meshRenderer);
		}

		// Re-add our components.
		boxCollider = gameObject.AddComponent<BoxCollider>();
		akSurfaceReflector = gameObject.AddComponent<AkSurfaceReflector>();
		akGameObject = gameObject.AddComponent<AkGameObj>();
		rigidBody = gameObject.AddComponent<Rigidbody>();

		// Set properties.
		boxCollider.isTrigger = true;
		akGameObject.isEnvironmentAware = true;

		rigidBody.mass = 1f;
		rigidBody.drag = 0f;
		rigidBody.angularDrag = 0.05f;
		rigidBody.useGravity = false;
		rigidBody.isKinematic = true;
		rigidBody.interpolation = 0;
		rigidBody.collisionDetectionMode = 0;

		gameObject.name = "SurfaceReflector";

		// Destroy our ReflectorCreator when done.
		DestroyImmediate(this);
	}
}
