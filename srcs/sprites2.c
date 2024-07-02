/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:37:24 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 10:14:34 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_door_sprites(t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->exit_closed = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			DOOR_CLOSE, &w, &h);
	sprites->exit_open = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			DOOR_OPEN, &w, &h);
	if (!sprites->exit_closed || !sprites->exit_open)
	{
		ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr,
			game->mlx.mlx_data.mlx_win);
		print_error("Couldn't load exit images\n");
	}
}

void	init_enemy_sprites(t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->enemy.l = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			ENEMY_LEFT, &w, &h);
	sprites->enemy.r = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			ENEMY_RIGHT, &w, &h);
	sprites->enemy.curr = sprites->enemy.r;
	if (!sprites->enemy.l || !sprites->enemy.r)
	{
		ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr,
			game->mlx.mlx_data.mlx_win);
		print_error("Couldn't load extra images\n");
	}
}

void	init_extra_sprites(t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->life = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			LIFE, &w, &h);
	sprites->star = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			STAR, &w, &h);
	if (!sprites->life || !sprites->star)
	{
		ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr,
			game->mlx.mlx_data.mlx_win);
		print_error("Couldn't load extra images\n");
	}
}

void	init_player_sprites(t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->player.l = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			KIRBY_LEFT, &w, &h);
	sprites->player.r = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			KIRBY_RIGHT, &w, &h);
	sprites->player.curr = sprites->player.r;
	if (!sprites->player.l || !sprites->player.r)
	{
		ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr,
			game->mlx.mlx_data.mlx_win);
		print_error("Couldn't load extra images\n");
	}
}
