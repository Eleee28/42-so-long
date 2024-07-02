# MiniLibX information

MiniLibX is a graphic library which allows to do basic things for rendering something on screens. It includes basic tools to open a window, create images and deal with keyboard and mouse events.

## Installation

### MacOS

MiniLibX requires AppKit and OpenGL so we need to link them.

Add this in the Makefile:
~~~~
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
~~~~

### Linux

In Linux it requires ```xorg```, ```x11``` and ```zlib```, so we need to install them:
~~~~
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
~~~~

Add this in the Makefile:
~~~~
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
~~~~

## Getting started

Include the header:
~~~~
#include "mlx.h"
~~~~

Initialize the MiniLibX establishing a connection to the graphical system:
~~~~
int main {
    void    *mlx_ptr;
    
    mlx_ptr = mlx_init();
}
~~~~

Initialize a window which will stay open forever:
~~~~
int main {
    void    *mlx_ptr;
    void    *mlx_win;
    
    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx_ptr);      // Infinite window rendering
}
~~~~

Put an image on the window:

To do so we will need to have the image in ```xpm``` format. 
~~~~
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename, &w, &h);      // w and h are return variables
    mlx_put_image_to_window(mlx_ptr, mlx_win, img_ptr, w, h);
~~~~

```mlx_clear_window``` clears the current window.
~~~~
    mlx_clear_window(mlx_ptr, mlx_win);
~~~~

## Hooks

Hooks are used to register events like a mouse click or pressing a key.

```mlx_hook``` is used to register any kind of event.
~~~~
    mlx_hook(mlx_win, event, mask, function, param);

// both event and mask can be declared in the header file and represent the codes for each key or mouse event
~~~~


To deal with key events we must declare variables that represent the keycode of each key we are interested in.

```mlx_key_hook``` is an alias of mlx_hook on key up event
~~~~
    mlx_key_hook(mlx_win, handle_input, param);
    
// inside the handle input function we can make distinctions between different keycodes, so each key has its own action
~~~~

**Hooking into loops**

~~~~
    mlx_loop_hook(mlx_ptr, function, param);

// the function will be called for each frame it requires with the parameter param
~~~~

## Extra

```mlx_get_color_value``` gets the color value from an int.

```mlx_string_put``` puts a string in the location (x, y) on a given window.

~~~~
	mlx_string_put(mlx_ptr, mlx_win, x, y, mlx_get_color_value(mlx_ptr, 0x00FFFFFF), string);

// the hex 0x00FFFFFF represents white. The format is 0xTTRRGGBB where T represents transparency and RGB (red-green-blue)
~~~~