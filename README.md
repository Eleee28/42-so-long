# 42_so_long

Statement of the project (in [Spanish](es.subject.pdf) / [English](en.subject.pdf))

## About the project

The goal of the project is to create a small 2D game. 
<br>
<br>
The player's goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
In my case I used Kirby games as inspiration.
<br>
<br>
To do so, I sill use the graphical library MiniLibX, which includes the basic necessary tools to open a window, create images and deal with keyboard and mouse events.

### Mandatory part

The program has to take as parameter a map description file ending with the .ber extension. There are some map examples in the [maps folder](maps/).

#### Game 

Keyboard keys action's:

| Key | Action |
|  -  |    -   |
| W / Up arrow | Move up |
| A / Left arrow | Move left |
| S / Down arrow | Move down |
| D / Right arrow | Move right |
| R | Reset the game |
| Esc | Close the window |

#### Map

Characters to represent the map:

| Char | Description |
| - | - |
| 0 | Empty space |
| 1 | Wall |
| C | Collectible |
| E | Map exit |
| P | Player's starting position |
| X | Enemy's starting position |


The map must:

- Contain **1 exit**, at least **1 collectible**, and **1 starting position** to be valid.

- Be rectangular.

- Be surrounded by walls.

- Have a valid path.

### Bonus part

For the bonus part we have to develop extra features:

- Make the player lose when they touch an enemy.

- Add some sprite animation

- Display the movement count on screen.

### MiniLibX information

For some information on the mlx functions I used see: [doc](mlx_info.md).
