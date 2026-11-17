#pragma strict

 var level : String = "main_menu";
 var delay : int = 4;
 
 Invoke("Load", delay);
 

 function Load() {
     Application.LoadLevel(level);
 }