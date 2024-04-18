# Cub3D

Project writen in C. Research of Raycasting and handling Windowing library (interupts, non-blocking visual loops).

![](https://github.com/stevebalk/cub3d/blob/main/cub3d.gif)

## Gameplay

The gameplay itself is minimal, serving as a demonstration of ray-casting. It features a walkable labyrinth, and non-interactive animated sprites.

## Game Map File Parsing

The game parses a .cub file, which represents the walkable labyrinth, texture images, ground and ceiling color.


## Ray Casting

Ray casting operates by measuring distances to walls based on the player's position and their facing direction towards the wall. To fill a screen, a measurement for each vertical pixel line must be taken.

Textures are then sampled onto the vertical line according to the coordinate of the measured cast position, and scaled/offset according to the distance. The entire screen is adjusted to remove the fisheye effect, maintaining a field of view (FOV) of 90 degrees. The sampled texture is dimmed according to the distance, but this dimming is not implemented in a linear fashion.

## Game Loop Engine/Cycle

Key presses and releases update the player's movement speed. Within the loop, the player's coordinate is updated according to their movement speed, considering factors such as wall collision (which is slideable) and frame-rate based on time. This ensures a consistent game speed independent of the game loop cycle speed. Key presses and releases act as interrupts that update game_data -> keys -> (key pressed). The Game Loop registers pressed keys, thereby accommodating multiple simultaneous key presses.