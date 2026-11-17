using System.Collections;
using UnityEngine;

public class enemyai : MonoBehaviour
{
	public Transform thisObject;
	public Transform target;
	private UnityEngine.AI.NavMeshAgent navComponent;

	void Start()
	{
		target = GameObject.FindGameObjectWithTag("Player").transform;
		navComponent = this.gameObject.GetComponent<UnityEngine.AI.NavMeshAgent>();
	}

	void Update()
	{
		if (target)
		{
			navComponent.SetDestination(target.position);
		}
		else
		{
			if (target == null)
			{
				target = this.gameObject.GetComponent<Transform>();
			}
			else
			{
				target = GameObject.FindGameObjectWithTag("Player").transform;
			}
		}
	}
}