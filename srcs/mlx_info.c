/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:17:43 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/09 22:32:20 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
}


int	handle_input(int keycode, t_game *game)
{
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		exit_window(&game->mlx.mlx_data);
	//else if (keycode == KEY_R)
		//reset_game(game);
	else 
		move_player(game, keycode);
	return (0);
}

t_sprites   init_sprites(t_game *game)
{
	t_sprites sprites;
	int h;
	int w;
	
	sprites.black = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, BLACK, &w, &h);
	if (!sprites.black)
	{
		ft_printf("Error loading sprites\n");
	}
	sprites.blue = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, BLUE, &w, &h);
	sprites.grass = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, GRASS, &w, &h);
	sprites.tree = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, TREE, &w, &h);
	sprites.exit.close = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, DOOR_CLOSE, &w, &h);
	sprites.exit.open = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, DOOR_OPEN, &w, &h);
	sprites.life = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, LIFE, &w, &h);
	//sprites.coin.off = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, COIN_OFF_PATH, &w, &h);
	sprites.coin.on = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, COIN_ON, &w, &h);
	sprites.player.down = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, KIRBY_NORMAL, &w, &h);
	sprites.enemy.down = mlx_xpm_file_to_image(&game->mlx.mlx_data.mlx_ptr, ENEMY_NORMAL, &w, &h);

	
	//sprites.player.left = ;
	//sprites.player.right = ;
	//sprites.player.up = ;
	
	if (!sprites.grass || !sprites.tree || !sprites.exit.close || !sprites.exit.open || !sprites.life || !sprites.coin.on || !sprites.player.down || !sprites.enemy.down)
	{
		//ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win);
		//free(game->mlx.mlx_data.mlx_ptr);
		print_error("Not sprite found\n");
	}
	
	return (sprites);
}


