#pragma strict


var enemy : Transform;
var delaybetweenspawn = 3;

function Start ()
{
StartCoroutine("Spawn");
}

function Spawn () {
yield WaitForSeconds (delaybetweenspawn);
var InstanceAi = Instantiate(enemy,transform.position,Quaternion.identity);
StartCoroutine("Start");
}