/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:04:22 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/09 20:43:33 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "position.h"

/* ************************************************************************** */
/*                 DATA STRUCTURES DEFINITIONS                                */
/* ************************************************************************** */

/** @brief Player structure
 * 
 *  @param coord player position
 *  @param collec number of collectibles picked up
 *  @param moves number of moves made
 *  @param life player life
*/
typedef struct s_player
{
	t_pos	coord;
	int		collec;
	int		moves;
	int		life;
}			t_player;

#endif