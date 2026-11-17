using UnityEngine;
using System.Collections;



public class PlayerLifeAndLoad : MonoBehaviour
{


	public AudioClip die;

	public int hp = 100;

	public int hplevel;

	IEnumerator MyMethod()
	{
		yield return new WaitForSeconds(1);
		Application.LoadLevel("retry_die");

	}


	void OnTriggerEnter(Collider other)
	{
		if (other.gameObject.tag == "Zombie")
		{
			hp -= 20;

			hplevel = hp;
		}


		if (hp == 0)
		{

			AudioSource.PlayClipAtPoint(die, transform.position);

			StartCoroutine(MyMethod());


		}
	}

}



