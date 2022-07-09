# HW 3_1

## Work with blueprints and UMG

In this homework, was create a simple game with UMG widgets and some blueprint logic. There is a level ```FirstPersonMap``` where actions happen. To encapsulate and control all actions was create a custom blueprint GameMode, where many custom events were created to call them in another blueprint and UMG widgets. In the folder ```Homework/UMGs```, there are UMG widgets - UMG_StartGame, UMG_GameInfo, UMG_EndGame that, on different clicks call events from custom GameMode. Also, a blueprint manager was created for custom GameMode to manage it.

For the cube, a ```BP_MasterCube``` was created, which has a logic for moving and Cube Mesh and variable ```Value``` to define how many scores you can get from this type of cube. From the MasterCube were created two different cubes, but with different materials, scales and ```Values```.

Cubes are spawned by custom GameMode with event ```Spawn Cubes```. Some events are called from ```BP_FirstPersonProjectile``` to increase score and spawn a new cube, and form ```BP_Rifle``` to decrease available shots.

## 
