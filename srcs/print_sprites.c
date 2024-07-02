/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:07:53 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 10:09:28 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_tree_sprite(t_game *game, t_pos pos)
{
	void	*ptr;
	void	*win;

	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	if (game->frames == 0)
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.tree1,
			pos.y * IMG_W, (pos.x + 1) * IMG_H);
	else if (game->frames == 50)
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.tree2,
			pos.y * IMG_W, (pos.x + 1) * IMG_H);
	else if (game->frames == 100)
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.tree3,
			pos.y * IMG_W, (pos.x + 1) * IMG_H);
	else if (game->frames == 150)
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.tree4,
			pos.y * IMG_W, (pos.x + 1) * IMG_H);
}

void	put_collec_sprite(t_game *game, t_pos pos)
{
	void	*ptr;
	void	*win;

	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	if (game->frames <= 50)
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.collec1,
			(pos.y * IMG_W) + 6, ((pos.x + 1) * IMG_H) + 6);
	else
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.collec2,
			(pos.y * IMG_W) + 6, ((pos.x + 1) * IMG_H) + 6);
}
