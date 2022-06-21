# HW 1

## Work with material and blueprint

In this homework, I create the material `Decay_M`. This material has a texture and base color, and texture is used for the decay map, where I get `G` value of color, and relative to this I create decay. Also, decay occurs relatively from scalar that has a range from 0 to 2, in 0 the material is invisible, and in 2 the material is visible.

For demonstration, I created a BP for cube where exists custom event that start to make the material invisible, and when the value is 0, the material will be hidden and destroyed. The event I call from projectile, when it hits a cube.

## Demonstration of work
![2022-06-21-16-16-17](https://user-images.githubusercontent.com/34779566/174808749-3b937fb0-bdb2-49ac-a8e2-03146c1e2c15.gif)
