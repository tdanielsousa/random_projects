#pragma strict

 var level : String = "h1_desert";
 var delay : int = 10;
 
 Invoke("Load", delay);
 
 function Load() {
     Application.LoadLevel(level);
 }