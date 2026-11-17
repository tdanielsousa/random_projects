using UnityEngine;
using System.Collections;

public class swaygun : MonoBehaviour
{
	public float tilt = 5;
	public float smooth = 5;

	void Update()
	{
		transform.localRotation = Quaternion.Lerp(transform.localRotation, Quaternion.Euler(new Vector3(0, 0, -Input.GetAxis("Vertical") * tilt)), Time.deltaTime * smooth);
	}
}