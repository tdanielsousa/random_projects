#pragma strict
 var level : String = "house1 forest";
 var delay : int = 70;
 
 Invoke("Load", delay);
 
 function Load() {
     Application.LoadLevel(level);
 }