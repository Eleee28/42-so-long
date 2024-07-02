/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:06:53 by ele               #+#    #+#             */
/*   Updated: 2024/07/02 10:07:48 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_messages(t_game *game, char **life, char **coll, char **mov)
{
	char	*aux;

	aux = ft_itoa(game->player.life);
	*life = ft_strjoin("x0", aux);
	free(aux);
	aux = ft_itoa(game->player.collec);
	*mov = ft_strjoin(aux, "/");
	free(aux);
	aux = ft_itoa(game->map.n_collec);
	*coll = ft_strjoin(*mov, aux);
	free(*mov);
	free(aux);
	aux = ft_itoa(game->player.moves);
	*mov = ft_strjoin(" |  Movements: ", aux);
	free(aux);
}

void	put_info(t_game *game, char *life, char *collec, char *moves)
{
	int		i;
	void	*ptr;
	void	*win;
	int		color;

	i = 0;
	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	while (i < game->map_w)
	{
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.header,
			i * IMG_W, 0);
		i++;
	}
	color = mlx_get_color_value(ptr, 0x00FFFFFF);
	mlx_put_image_to_window(ptr, win, game->mlx.sprites.life, 0, 0);
	mlx_string_put(ptr, win, 12, 53, color, life);
	mlx_put_image_to_window(ptr, win, game->mlx.sprites.star, 45, 0);
	mlx_string_put(ptr, win, 58, 53, color, collec);
	mlx_string_put(ptr, win, 95, 35, color, moves);
}

void	print_obj(t_game *game, t_pos pos)
{
	void	*ptr;
	void	*win;

	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	if (equal_pos(pos, game->player.coord) && game->player.life > 0)
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.player.curr,
			(pos.y * IMG_W) + 2, ((pos.x + 1) * IMG_H) + 5);
	else if (game->map.map[pos.x][pos.y] == 'E')
	{
		if (game->player.collec != game->map.n_collec)
			mlx_put_image_to_window(ptr, win, game->mlx.sprites.exit_closed,
				pos.y * IMG_W, (pos.x + 1) * IMG_H);
		else
			mlx_put_image_to_window(ptr, win, game->mlx.sprites.exit_open,
				pos.y * IMG_W, (pos.x + 1) * IMG_H);
	}
	else if (game->map.map[pos.x][pos.y] == '1')
		put_tree_sprite(game, pos);
	else if (game->map.map[pos.x][pos.y] == 'C')
		put_collec_sprite(game, pos);
	else
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.grass,
			pos.y * IMG_W, (pos.x + 1) * IMG_H);
	print_enemies(game, pos);
}

void	init_print(t_game *game)
{
	int		i;
	int		j;
	void	*ptr;
	void	*win;

	print_header(game);
	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			mlx_put_image_to_window(ptr, win, game->mlx.sprites.grass,
				j * IMG_W, (i + 1) * IMG_H);
			++j;
		}
		++i;
	}
}
