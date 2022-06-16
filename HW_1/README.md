# HW 1

## Work with materials

In this homework, I create the material `Decay_M`. This material has a texture and base color, and texture is used for the decay map, where I get `G` value of color, and relative to this I create decay. Also, decay occurs relatively from scalar that has a range from 0 to 2, in 0 the material is invisible, and in 2 the material is visible.

For demonstration, I created a BP for cube where I check if the boolean value of 'to_destroy' is true. If it is, then we start to make the material invisible, and when the value is 0, the material will be hidden and destroyed. The boolean, I switch in BP of projectile. When projectile hits a cube, and it is a cube with our material, I switch the boolean.

## Demonstration of work
![2022-06-16 13-41-11](https://user-images.githubusercontent.com/34779566/174053612-85c1a35f-2ff2-4bf7-9635-788e28eefac7.gif)
