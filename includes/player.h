/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele <ele@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:04:22 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/25 08:17:15 by ele              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

# include "position.h"

typedef struct s_player
{
	t_pos	coord;
	int		collec;
	int		moves;
	int		life;
}			t_player;

#endif