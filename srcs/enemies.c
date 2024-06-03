/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:49:55 by ele               #+#    #+#             */
/*   Updated: 2024/04/09 20:57:18 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemies(t_game *game, int n)
{
	int		i;
	t_pos	pos;

	game->enemies.enemies = (t_enemy_arr)malloc(n * sizeof(t_pos));
	if (!game->enemies.enemies)
		return ;
	i = 0;
	pos = (t_pos){0, 0};
	while (i < n && game->map.map[pos.x][pos.y])
	{
		if (game->map.map[pos.x][pos.y] == 'X')
		{
			game->enemies.enemies[i] = pos;
			i++;
		}
		pos.y++;
		if (pos.y == game->map_w)
		{
			pos.y = 0;
			pos.x++;
		}
	}
}

void	print_enemies(t_game *game, t_pos pos)
{
	int	i;

	i = 0;
	while (i < game->enemies.n_enemies)
	{
		if (equal_pos(pos, game->enemies.enemies[i]))
			mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr,
				game->mlx.mlx_data.mlx_win, game->mlx.sprites.enemy.curr,
				pos.y * IMG_W, (pos.x + 1) * IMG_H);
		i++;
	}
}

/* https://old.chuidiang.org/clinux/funciones/rand.php -> srand() and rand() */
/**
 * @details rand() % 5 generates a random number between 0 and 4.
 *  0 : dont move, 1: move up, 2: move down, 3: move left, 4: move right
*/
void	move_enemies(t_game *game)
{
	int		m;
	int		i;
	t_pos	aux;

	m = rand() % 5;
	i = 0;
	while (i < game->enemies.n_enemies)
	{
		aux = game->enemies.enemies[i];
		if (m == 1)
			aux.x++;
		else if (m == 2)
			aux.x--;
		else if (m == 3)
			aux.y--;
		else if (m == 4)
			aux.y++;
		if (in_board(*game, aux) && game->map.map[aux.x][aux.y] == '0')
			if (!equal_pos(game->player.coord, game->enemies.enemies[i])) {
				if (m == 3)
					game->mlx.sprites.enemy.curr = game->mlx.sprites.enemy.left;
				else if (m == 4)
					game->mlx.sprites.enemy.curr = game->mlx.sprites.enemy.right;
				game->enemies.enemies[i] = aux;
			}
		i++;
	}
}
