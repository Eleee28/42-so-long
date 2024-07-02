/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:04:22 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 12:03:47 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "position_bonus.h"

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