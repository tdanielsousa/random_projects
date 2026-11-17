# Survival Horror FPS (PAP Project)

A 3D survival horror zombie horde-like game built in Unity in 2015 (an era of no AI, and days of waiting for a stackoverflow answer!), as my final PAP (*Prova de Aptidão Profissional*) project for the 12th grade of the TGPSI course (*Técnico de Gestão e Programação de Sistemas Informáticos*).

The player survives against an endless horde of zombies that keep spawning and hunting them down, in a dark, atmospheric setting. 

It was made under tight time constraints and with very little help beyond documentation and trial and error, since this was long before AI tools.

 It earned the maximum grade of **20/20**, thanks to its complexity and the number of concepts it covered.

> Note: The project is barebones, as there was little time to build it. The focus was on covering as many game development concepts as possible and show a working prototype.
---

<p align="center">
  <img src="https://github.com/tdanielsousa/tdanielsousa/blob/main/gifs/wod.gif" alt="Survival" width="600px" />
</p>

##  Game Overview & Design

The player moves through a dark map while zombies spawn continuously and chase them using pathfinding. 

The goal is simply to survive and keep shooting for as long as possible.

### Technical Specifications
* **Engine:** Unity (2015, Unity 5 era).
* **Genre:** First-person survival horror shooter.
* **Enemy AI:** Zombies chase the player using the **A\* (A-Star) pathfinding algorithm**.
* **Game Flow:** Intro movie, Main menu, gameplay loop, player death.

---

##  Features

### Player Mechanics
* **Movement:** First-person movement with gravity and jumping.
* **Camera:** Mouse look with the cursor hidden and locked, plus a zoom function.
* **Head Bob and Sway:** Head bobbing while walking, plus player movement sway and weapon sway.
* **Footstep Sounds:** Audio feedback while moving.
* **Weapon Swap:** Switch between multiple weapons.
* **Shooting:** Fully working shooting with hit detection and projectile physics.
* **Life and Death:** The player has a health pool and dies when it reaches zero.

### Enemies
* **Spawning:** Zombies spawn continuously, forming a relentless horde.
* **Pathfinding:** Each zombie finds its way to the player with A\*.
* **Health and Damage:** Zombies take damage from shots and die when their health reaches zero.

### Atmosphere
* **Volumetric Sky and Fog:** Used to build the dark, heavy mood.
* **Lighting Work:** Light models and light textures, plus a **light flicker** effect.
* **Jump Scares:** Timed scares to keep the player on edge.
* **Collisions:** Collision handling for the player, enemies and the environment.

---

##  Project Background

* **Course:** TGPSI (*Técnico de Gestão e Programação de Sistemas Informáticos*)
* **Milestone:** 12th grade final project (PAP)
* **Year:** 2015
* **Grade:** **20/20**, the maximum, awarded for the complexity of the project and the amount of work and concepts it covered.

---

## Installation

### New versions
* **Legacy Unity Version Required:** This project was made in 2015 and requires an older Unity editor (**Unity 5.x era**). Newer versions of Unity introduce breaking changes that break the project structure and legacy APIs.
* **Why Only Scripts Are Shared:** Due to the discontinuation of the **Unity Web Player** (which originally hosted the playable build) and the large asset size of the full project exceeding GitHub's storage limits, this repository hosts only a curated selection of the core game scripts for code review and archival purposes.

---

## AI Usage Declaration

No AI tools were used to make this project, as it was developed in 2015, before they existed.

AI tools were only used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---