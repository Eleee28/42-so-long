/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:49:12 by elena             #+#    #+#             */
/*   Updated: 2024/07/10 08:34:02 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  @details 
 * 		mlx_init() - used to establish a connection to the X server
 * 		mlx_new_window() - initializes an open window
 * 		mlx_key_hook() - handles the keyboard input
 * 		mlx_hook() - handles the mouse input
 * 		mlx_loop_hook() - for each frame will execute the arg function
 * 		mlx_loop() - used for infinite window rendering
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
	init_print(game);
	mlx_hook(game->mlx.mlx_data.mlx_win, ON_KEYDOWN, 1L<<0,
		handle_input, game);
	mlx_hook(game->mlx.mlx_data.mlx_win, CLOSEBUTTON, CLOSEBUTTONMASK,
		exit_window, game);
	mlx_loop_hook(game->mlx.mlx_data.mlx_ptr, play_game, game);
	mlx_loop(game->mlx.mlx_data.mlx_ptr);
}

int	play_game(t_game *game)
{
	if (!game->map.map)
		return (0);
	if (game->player.life <= 0)
		print_end_screen(game, "Game Over!");
	else if (equal_pos(game->player.coord, game->map.exit_coord)
		&& game->player.collec == game->map.n_collec)
		print_end_screen(game, "You Win!");
	else
		print_game(game);
	return (0);
}

void	reset_game(t_game *game)
{
	ft_free_matrix(game->map.map);
	game->map.map = ft_dup_matrix(game->map.init_map);
	if (!game->map.map)
		print_error("Error using malloc");
	game->player.collec = 0;
	game->player.life = 1;
	game->player.coord = game->map.init_coord;
	game->player.moves = 0;
	init_print(game);
}
