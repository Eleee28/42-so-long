/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:59:43 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 12:07:58 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	print_game(t_game *game)
{
	int	r;
	int	c;

	r = 0;
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
	return (0);
}

/**
 *  @details Uses strings to store the text to print. Clears the banner and 
 *  puts the corresponding information
*/
void	print_header(t_game *game)
{
	char	*collec;
	char	*moves;
	char	*life;

	collec = 0;
	moves = 0;
	life = 0;
	create_messages(game, &life, &collec, &moves);
	put_info(game, life, collec, moves);
	free(life);
	free(moves);
	free(collec);
}

void	print_end_screen(t_game *game, char *text)
{
	void				*ptr;
	void				*win;
	unsigned int		color;

	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	color = mlx_get_color_value(ptr, 0x00FFFFFF);
	mlx_clear_window(ptr, win);
	mlx_string_put(ptr, win, ((game->map_w / 2)) * IMG_W,
		(game->map_h / 2) * IMG_H, color, text);
	mlx_string_put(ptr, win, ((game->map_w / 2) - 0.5) * IMG_H,
		((game->map_h / 2) + 1) * IMG_W, color, "Press [R] to reset");
}
