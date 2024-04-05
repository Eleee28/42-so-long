/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:49:12 by elena             #+#    #+#             */
/*   Updated: 2024/04/05 21:36:36 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <stdio.h>

/** @brief Opens a window and plays the game
 * 
 *  @details 
 * 		mlx_init() - used to establish a connection to the X server
 * 		mlx_new_window() - initializes an open window
 * 		mlx_key_hook() - handles the keyboard input
 * 		mlx_hook() - handles the mouse input
 * 		mlx_loop_hook() - for each frame will execute the arg function
 * 		mlx_loop() - used for infinite window rendering
 * 
 *  @param game game structure
*/
void	open_window(t_game *game)
{
	game->mlx.mlx_data.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_data.mlx_ptr)
	{
		ft_free_matrix(game->map.map);
		print_error("Error initializing mlx\n");
	}
	game->mlx.mlx_data.mlx_win = mlx_new_window(game->mlx.mlx_data.mlx_ptr, 
		game->screen_w, game->screen_h + IMG_H, "so_long");
	if (!game->mlx.mlx_data.mlx_win)
	{
		ft_free_matrix(game->map.map);
		free(game->mlx.mlx_data.mlx_ptr);
		print_error("Error creating window\n");
	}
	game->mlx.sprites = init_sprites(game);	
	mlx_key_hook(game->mlx.mlx_data.mlx_win, handle_input, game);
	mlx_hook(game->mlx.mlx_data.mlx_win, CloseButton, CloseButtonMask, exit_window, &game->mlx.mlx_data);	// seg fault when closing with button
	mlx_loop_hook(game->mlx.mlx_data.mlx_ptr, play_game, game);
	mlx_loop(game->mlx.mlx_data.mlx_ptr);
}

/** @brief Fills the structure with the corresponding info
 * 
 *  @param game game structure
*/
void	get_game_info(t_game *game)
{
	game->frames = 0;
	game->player.collec = 0;
	game->player.moves = 0;
	game->player.life = 1;
	game->player.coord = find_object(game->map.map, 'P');
	game->map.init_coord = game->player.coord;
	game->map.exit_coord = find_object(game->map.map, 'E');
	game->map.n_collec = count_objects(game->map.map, 'C');
	game->map_w = ft_strlen(game->map.map[0]);
	game->map_h = ft_len_matrix(game->map.map);
	game->screen_w = game->map_w * IMG_W;
	game->screen_h = game->map_h * IMG_H;
	game->enemies.n_enemies = count_objects(game->map.map, 'X');
	init_enemies(game, game->enemies.n_enemies);
	ft_printf("Before 1st dup_matrix:\n");
	ft_printf("------INIT_MAP-----\n");
    ft_print_matrix(game->map.init_map);
    ft_printf("------MAP-----\n");
    ft_print_matrix(game->map.map);
	game->map.init_map = ft_dup_matrix(game->map.map);
	if (!game->map.init_map)
		print_error("Error using malloc");
}

int play_game(t_game *game)
{
	game->frames++;
	if (game->player.life <= 0)
		print_end_screen(game, "Game Over!");
	else if (equal_pos(game->player.coord, game->map.exit_coord) && game->player.collec == game->map.n_collec)
		print_end_screen(game, "You Win!");
	
	else
	{
		if (game->frames == 50)
		{
			game->frames = 0;
			move_enemies(game);
		}
		print_game(game);
	}
	return (0);
}

int print_game(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	mlx_clear_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win);
	while (r < game->map_h)
	{
		c = 0;
		while (c < game->map_w)
		{
	
			print_obj(game, (t_pos){r, c});
			c++;
		}
		r++;
	}
	print_header(game);
	return (0);
}

void	print_obj(t_game *game, t_pos pos)
{	
	/*if (!game->mlx.sprites.grass)
	{
		print_error("Not sprite found");
	}*/
	mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.grass, pos.y * IMG_W, (pos.x + 1) * IMG_H);
	//ft_printf("Hello\n");
	if (game->map.map[pos.x][pos.y] == 'E')
	{
		if (game->player.collec != game->map.n_collec)
			mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.exit.close, pos.y * IMG_W, (pos.x + 1) * IMG_H);
		else
			mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.exit.open, pos.y * IMG_W, (pos.x + 1) * IMG_H);
		if (equal_pos(pos, game->player.coord))
			mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.player.down, (pos.y * IMG_W) + 2, ((pos.x + 1) * IMG_H) + 5);
	
	}
	else if (equal_pos(pos, game->player.coord) && game->player.life > 0)
		mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.player.down, (pos.y * IMG_W) + 2, ((pos.x + 1) * IMG_H) + 5);
	else if (game->map.map[pos.x][pos.y] == '1')
		mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.tree, pos.y * IMG_W, (pos.x + 1) * IMG_H);
	else if (game->map.map[pos.x][pos.y] == 'C')
		mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.coin.on, (pos.y * IMG_W) + 6, ((pos.x + 1) * IMG_H) + 6);
	print_enemies(game, pos);
}


