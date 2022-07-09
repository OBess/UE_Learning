# HW 3_1

## Work with blueprints and UMG

In this homework, was create a simple game with UMG widgets and some blueprint logic. There is a level ```FirstPersonMap``` where actions happen. To encapsulate and control all actions was create a custom blueprint GameMode, where many custom events were created to call them in another blueprint and UMG widgets. In the folder ```Homework/UMGs```, there are UMG widgets - UMG_StartGame, UMG_GameInfo, UMG_EndGame that, on different clicks call events from custom GameMode. Also, a blueprint manager was created for custom GameMode to manage it.

For the cube, a ```BP_MasterCube``` was created, which has a logic for moving and Cube Mesh and variable ```Value``` to define how many scores you can get from this type of cube. From the MasterCube were created two different cubes, but with different materials, scales and ```Values```. For grey cube you can get 1 score point, for blue 3 score points and for yellow 5 score points.

Cubes are spawned by custom GameMode with event ```Spawn Cubes```. Some events are called from ```BP_FirstPersonProjectile``` to increase score and spawn a new cube, and form ```BP_Rifle``` to decrease available shots.

## Start the game and demonstrate it
[Untitled.webm](https://user-images.githubusercontent.com/34779566/178114585-d7e2c765-a551-4ed9-b113-cc6f950ea518.webm)

## Restart game


## Exit the game
![2022-07-09 19-01-48](https://user-images.githubusercontent.com/34779566/178114193-9cc58aa9-6b45-493e-9ce5-8fb7a44611da.gif)
