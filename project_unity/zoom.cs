using UnityEngine;
using System.Collections;

public class zoom : MonoBehaviour
{
	public float zoomSpeed = 20;
	public int min;
	public int max;

	// Use this for init
	void Start()
	{

	}

	// Update is called once per frame
	void Update()
	{
		float scroll = Input.GetAxis("Mouse ScrollWheel");
		if (scroll != 0.0f)
		{
			GetComponent<Camera>().fieldOfView = Mathf.Clamp(GetComponent<Camera>().fieldOfView + scroll * zoomSpeed, min, max);

			GetComponent<Camera>().fieldOfView += scroll * zoomSpeed;
			GetComponent<Camera>().fieldOfView = Mathf.Clamp(GetComponent<Camera>().fieldOfView, min, max);
		}

	}
}
