/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 08:59:33 by ele               #+#    #+#             */
/*   Updated: 2024/07/02 10:04:53 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/** @brief Performs the player movement
 * 
 *  @param game game structure
 *  @param aux new position
*/
static void	perform_move(t_game *game, t_pos aux)
{
	int	i;

	if (!equal_pos(game->player.coord, aux))
	{
		game->player.moves++;
		ft_printf("Number of movements performed: %d\n", game->player.moves);
		print_header(game);
	}
	if (game->map.map[aux.x][aux.y] == 'C')
	{
		game->player.collec++;
		game->map.map[aux.x][aux.y] = '0';
		print_header(game);
	}
	i = 0;
	while (i < game->enemies.n_enemies)
	{
		if (equal_pos(aux, game->enemies.enemies[i]))
			game->player.life--;
		i++;
	}
	game->player.coord = aux;
}

static void	update_move(t_game *game, t_pos aux, char move)
{
	if (game->map.map[aux.x][aux.y] != '1')
	{
		if (move == 'L')
			game->mlx.sprites.player.curr = game->mlx.sprites.player.l;
		else if (move == 'R')
			game->mlx.sprites.player.curr = game->mlx.sprites.player.r;
		perform_move(game, aux);
	}
}

void	move_player(t_game *game, int keycode)
{
	t_pos	aux;
	char	move;

	aux = game->player.coord;
	if (keycode == KEY_UP || keycode == KEY_W)
		aux.x--;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		aux.x++;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		aux.y--;
		move = 'L';
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		aux.y++;
		move = 'R';
	}
	if (in_board(*game, aux))
		update_move(game, aux, move);
}
