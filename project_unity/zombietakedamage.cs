using UnityEngine;
using System.Collections;

public class zombietakedamage : MonoBehaviour
{

	int hp = 50;

	void OnTriggerEnter(Collider other)
	{
		if (other.gameObject.tag == "Bullet")
		{
			hp = hp - 10;
		}
		if (hp == 0)
			Destroy(this.gameObject);
	}
}
