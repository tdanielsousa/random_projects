#pragma strict

var gun1 : GameObject;
var gun2 : GameObject;
 
 
 
 
gun2.SetActive(false);
 
 
 
 function Update(){
 
 
 
 if(Input.GetKeyDown("q"))
   SwapWeapons();
 }
 
 function SwapWeapons(){
 if (gun1.active == true) {
 gun1.SetActive(false);
 gun2.SetActive(true);
 } else {
 gun1.SetActive(true);
 gun2.SetActive(false);
 }
 }
