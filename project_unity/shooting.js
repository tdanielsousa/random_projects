#pragma strict

var firebullets : AudioClip;
var projectile : Rigidbody;
var fireRate = 0.5; 
private var nextFire = 0.0;

var speed = 20;

function Update(){
if (Input.GetButtonDown("Fire1") && (Time.time <= nextFire)) 
{ 
GetComponent.<AudioSource>().clip = firebullets;
 GetComponent.<AudioSource>().Play();

nextFire = Time.time + fireRate; 
} 
if(Input.GetButton("Fire1") && (Time.time > nextFire)) 
{ 
GetComponent.<AudioSource>().clip = firebullets;
 GetComponent.<AudioSource>().Play();

nextFire = Time.time + fireRate; 
Fire();
}
}

function Fire()

{


var instantiatedProjectile : Rigidbody = Instantiate(

projectile, transform.position, transform.rotation );



instantiatedProjectile.velocity =

transform.TransformDirection( Vector3( 0, 0, speed ) );




CancelInvoke();

}

@script RequireComponent(AudioSource)