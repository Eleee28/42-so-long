/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:07:53 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 11:51:46 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_tree_sprite(t_game *game, t_pos pos)
{
	void	*ptr;
	void	*win;

	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	mlx_put_image_to_window(ptr, win, game->mlx.sprites.tree,
		pos.y * IMG_W, (pos.x + 1) * IMG_H);
}

void	put_collec_sprite(t_game *game, t_pos pos)
{
	void	*ptr;
	void	*win;

	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	mlx_put_image_to_window(ptr, win, game->mlx.sprites.collec,
		(pos.y * IMG_W) + 6, ((pos.x + 1) * IMG_H) + 6);
}
