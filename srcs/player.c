/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 08:59:33 by ele               #+#    #+#             */
/*   Updated: 2024/04/04 11:33:56 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    move_player(t_game *game, int keycode)
{
    t_pos aux;
    
    aux = game->player.coord;
    if (keycode == KEY_UP || keycode == KEY_W)	// move player up
        aux.x--;
	else if (keycode == KEY_DOWN || keycode == KEY_S) // move player down
        aux.x++;
	else if (keycode == KEY_LEFT || keycode == KEY_A) // move player left
        aux.y--;
	else if (keycode == KEY_RIGHT || keycode == KEY_D) // move player right
        aux.y++;
    if (in_board(*game, aux))
        if (game->map.map[aux.x][aux.y] != '1')
            perform_move(game, aux);
}

void    perform_move(t_game *game, t_pos aux)
{
    int i;
    
    if (!equal_pos(game->player.coord, aux))
    {
        game->player.moves++;
        ft_printf("Number of movements performed: %d\n", game->player.moves);
    }
    if (game->map.map[aux.x][aux.y] == 'C')
    {
        game->player.collec++;
        game->map.map[aux.x][aux.y] = '0';
    }
    /*else if (game->map.map[aux.x][aux.y] == 'E')
    {
        if (game->player.collec == game->map.n_collec)
        {
            ft_free_matrix(game->map.map);
            exit_window(&game->mlx.mlx_data);
        }
    }*/
    i = 0;
    while (i < game->enemies.n_enemies)
    {
        if (equal_pos(aux, game->enemies.enemies[i]))
            game->player.life--;
        i++;
    }
    game->player.coord = aux;
}
