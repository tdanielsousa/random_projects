#pragma strict

 function OnTriggerEnter(other: Collider){
   if (other.tag == "Load"){
     Application.LoadLevel(3);
   }
 }

