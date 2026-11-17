#pragma strict

var soundTurnOn : AudioClip;
var soundTurnOff : AudioClip;


function Start()
{

}



  function Update () {
 
   if (Input.GetKeyDown("f")) {
   
       if (GetComponent.<Light>().enabled == true) {
       
       	   GetComponent.<AudioSource>().clip = soundTurnOn;
           GetComponent.<Light>().enabled = false;
           
           } else {
           
           GetComponent.<AudioSource>().clip = soundTurnOff;
           GetComponent.<Light>().enabled = true;
           }
           
           GetComponent.<AudioSource>().Play();
           }
 }
 
	
 
	@script RequireComponent(AudioSource)
	
		
				
	
	