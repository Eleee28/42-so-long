/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:56:47 by elena             #+#    #+#             */
/*   Updated: 2024/07/02 11:43:01 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_game_info(t_game *game)
{
	game->player.collec = 0;
	game->player.moves = 0;
	game->player.life = 1;
	game->player.coord = find_object(game->map.map, 'P');
	game->map.init_coord = game->player.coord;
	game->map.exit_coord = find_object(game->map.map, 'E');
	game->map.n_collec = count_objects(game->map.map, 'C');
	game->map_w = ft_strlen(game->map.map[0]);
	game->map_h = ft_len_matrix(game->map.map);
	game->screen_w = game->map_w * IMG_W;
	game->screen_h = game->map_h * IMG_H;
	game->map.init_map = ft_dup_matrix(game->map.map);
	if (!game->map.init_map)
		print_error("Error using malloc");
}
