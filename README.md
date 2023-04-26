<h1 align="center">
	so_long
</h1>

![alt text](https://raw.githubusercontent.com/tiagohtavares/so_long/master/assets/sprites/readme.png?token=GHSAT0AAAAAAB7REERGDDTP4VPCGMBXOMMYZCI72HA)

## About 

This project consists of creating a simple 2D game using minilibx. MiniLibX is a tiny graphics library which allows you to do things for rendering something on the screen.
It provides a simple window creation, a drawing tool, image functions and a event management system.

The game consists of a player , collectibles and a exit. The player must collect all collectibles and exit, when the player exits the game ends.

The game will receive as argument a matrix that represents the map, it has to be a ".ber" file type. Here is an example :

```txt
111111111111111111
1P0100000000001001
101111110000001001
100000000000000001
100000000000000001
10C00C000000000001
100001000C000C0001
1000110100000001E1
111111111111111111
```
Each char represents something that has to be shown on the map.

```1``` Wall

```0``` Floor

```P``` Player

```C``` Collectible

```E``` Exit

## Implementation

The first thing i do is to check if the file received is valid. I check if the file has any flaws, such as empty lines or is empty , if
the file type matches that of ".ber". Once i verify that the file is valid, i check if the map provided is valid. To this i check
if it contains a player, an exit, it is surrounded by walls, it is a rectangle and there is no invalid chars.

Lastly i must check if there is a valid path to exit. Using a flood fill algorithm i fill the map starting from the player 
position, first covering all the ```C``` and then all the ```E```, if
there is something left on the map that matches ```C``` or ```E``` it means there was no possible path from player position to both.

Once the map is valid , using the minilibx functions, i initialize each image i an going to use, and begin iterating over the map. 
Using its width, and height i get the window size, 
i iterate over the map again and this time for every char we display it's image on the created window. Since i use 64 pixels images i can
get the location of each image on the window simply by multiplying the coordinates of the matrix by 64 IE if image is at pos x 5, y 5 then it will display
it's image at x 320, y 320. After this the game enters a loop created by ```mlx_loop``` wich also allows the progam to whait for events.

To move the player, ```mlx_key_hook``` is used, wich allows us to redirect an input to function aswell the key that was inputed. With this we are able to
switch the player position on the matrix every time we press a key (```WASD``` to move). If a player moves up and it's a floor tile we simply swap the player
with the tile and render the map again. If it's a colllectible we simply turn the tile into a floor, add to the collectible counter and repeat the previous step.
Once all collectibles are collected the exit is liberated and it's then possible to exit.

A counter with player moves is also displayed on the terminal.

## Bonus

For bonus of this assignment the game must contain animations, enemies and display the ammount of moves on the window.

In order to do this i changed the way my game rendered. Rather than only render when a key pressed, we now use mlx_loop_hook, this function creates an 
loop and every time it enters the loop it calls a function passed as a parameter. Using this we render the map constantly giving us "FPS".

A new char to the map is added, ```Z``` wich represents the enemies. Keeping track of the frames and using a rand() function , the progam tells the enemy
to move at certain frame in the x or y axis based on the random number.
Using the frames the progam also switches betweens the images at a certain frame interval this allow us to get animations. 

I also added the ability to deploy a bomb by pressing space behind the player to destroy the enemies just for fun :D.


