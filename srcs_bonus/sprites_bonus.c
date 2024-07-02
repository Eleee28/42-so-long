/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:07:08 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 12:08:21 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	init_background_imgs(t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->grass = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			GRASS, &w, &h);
	sprites->header = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			HEADER, &w, &h);
	if (!sprites->grass || !sprites->header)
	{
		ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr,
			game->mlx.mlx_data.mlx_win);
		print_error("Couldn't load background images\n");
	}
}

void	init_tree_sprites(t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->tree1 = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			TREE1, &w, &h);
	sprites->tree2 = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			TREE2, &w, &h);
	sprites->tree3 = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			TREE3, &w, &h);
	sprites->tree4 = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			TREE4, &w, &h);
	if (!sprites->tree1 || !sprites->tree2 || !sprites->tree3
		|| !sprites->tree4)
	{
		ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr,
			game->mlx.mlx_data.mlx_win);
		print_error("Couldn't load tree images\n");
	}
}

void	init_collec_sprites(t_game *game, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->collec1 = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			COLL1, &w, &h);
	sprites->collec2 = mlx_xpm_file_to_image(game->mlx.mlx_data.mlx_ptr,
			COLL2, &w, &h);
	if (!sprites->collec1 || !sprites->collec2)
	{
		ft_free_matrix(game->map.map);
		mlx_destroy_window(game->mlx.mlx_data.mlx_ptr,
			game->mlx.mlx_data.mlx_win);
		print_error("Couldn't load collectibles images\n");
	}
}

t_sprites	init_sprites(t_game *game)
{
	t_sprites	sprites;

	init_background_imgs(game, &sprites);
	init_tree_sprites(game, &sprites);
	init_collec_sprites(game, &sprites);
	init_door_sprites(game, &sprites);
	init_enemy_sprites(game, &sprites);
	init_extra_sprites(game, &sprites);
	init_player_sprites(game, &sprites);
	return (sprites);
}
