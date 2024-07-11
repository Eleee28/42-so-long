# 42_so_long

Statement of the project (in [Spanish](es.subject.pdf) / [English](en.subject.pdf))

## Introduction

This project involves creating a small 2D game where the player collects all collectibles on a map and then escapes through an exit, taking the shortest possible route. The game uses the MiniLibX graphical library to handle window creation, images, and keyboard/mouse events.

## Game Overview

In this game, inspired by Kirby games, the player navigates through a map, collecting items and avoiding enemies. The main objective is to gather all the collectibles and reach the exit.


## Mandatory part

### Game Execution

The program runs by taking a map description file as a parameter. The map file must have a `.ber` extension.

Example:
```sh
./so_long maps/example_map.ber
```

### Controls

The player cam move around the map using the following keys:

| Key | Action |
|  -  |    -   |
| W / Up arrow | Move up |
| A / Left arrow | Move left |
| S / Down arrow | Move down |
| D / Right arrow | Move right |
| R | Reset the game |
| Esc | Close the window |

### Map Specifications

The map is described using specific characters in the `.ber` file:

| Char | Description |
| - | - |
| 0 | Empty space |
| 1 | Wall |
| C | Collectible |
| E | Map exit |
| P | Player's starting position |
| X | Enemy's starting position |


**Map Requirements**

- The map must contain exactly one exit ('**E**'), at least one collectible ('**C**'), and one starting position ('**P**').

- The map must be rectangular.

- The map must be surrounded by walls ('**1**').

- There must be a valid path from the player's starting position to all collectibles and to the exit.

## Bonus part

The bonus part includes additional features to improve the gameplay experience:

- **Enemies**: Introduce enemies ('**X**') that the player must avoid. Touching an enemy results in losing the game.

- **Animations**: Add sprite animations for the player and other game elements.

- **Movement Counter**: Display the number of moves the player has made on the screen.

## MiniLibX information

MiniLibX is a simple graphical library for rendering graphics, handling events, and managing windows in the X Windows System on Unix-like operating systems. It provides the basic necessary tools for creating 2D graphics.

### Key Functions Used - Check!!

- `mlx_init()` : Initializes the connection between software and display.

- `mlx_new_window()` : Creates a new window.

- `mlx_xpm_file_to_image()` : Creates a new image from an xpm file.

- `mlx_put_image_to_window()` : Puts an image to the window.

- `mlx_hook()` : Handles events.

- `mlx_loop()` : Puts the program in a loop, waiting for events.

For more detailed information on MiniLibX functions, refer to the [extended information](docs/mlx_info.md) or the [documentation](https://harm-smits.github.io/42docs/libs/minilibx).

## Implementation Steps

1. **Parse the Map File**: Read the .ber file and parse the map layout into a usable data structure.

2. **Initialize MiniLibX**: Set up the MiniLibX library, create a window, and prepare images for the game elements.

3. **Render the Map**: Draw the map on the window based on the parsed data.

4. **Handle Player Input**: Implement keyboard event handlers to move the player character.

5. **Game Logic**: Ensure the player can collect items, detect collision with walls, and determine if the player has reached the exit.

6. **Bonus Features**: Add enemies, animations, and a movement counter for enhanced gameplay.
