# HW 1

## Work with materials

In this homework, I created the same materials that were in the video.

Also, I created my own material `Decay_M`. This material has a texture and base color, and texture is used for the decay map, where I get `G` value of color, and relative to this I create decay. Also, decay occurs relatively from scalar that has a range from 0 to 2, in 0 the material is invisible, and in 2 the material is visible.

For demonstration, I created a BP for cube where exists custom event that start to make the material invisible, and when the value is 0, the material will be hidden and destroyed. The event I call from projectile, when it hits a cube.

## The same materials from video
![2022-06-22-14-58-54](https://user-images.githubusercontent.com/34779566/175029227-e7b8f612-0c6f-4d6d-8bdb-8cc4c0b58f27.gif)

## Demonstration of work my material
![2022-06-21-16-16-17](https://user-images.githubusercontent.com/34779566/174808749-3b937fb0-bdb2-49ac-a8e2-03146c1e2c15.gif)
