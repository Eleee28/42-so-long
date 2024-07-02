/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 06:00:45 by ele               #+#    #+#             */
/*   Updated: 2024/07/02 10:06:12 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	equal_pos(t_pos pos1, t_pos pos2)
{
	return (pos1.x == pos2.x && pos1.y == pos2.y);
}

int	in_board(t_game game, t_pos pos)
{
	return (pos.x >= 0 && pos.x < game.map_h
		&& pos.y >= 0 && pos.y < game.map_w);
}
