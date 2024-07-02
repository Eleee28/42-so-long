/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:58:29 by ele               #+#    #+#             */
/*   Updated: 2024/07/02 11:56:15 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_BONUS_H
# define ENEMIES_BONUS_H

# include "position_bonus.h"

/* ************************************************************************** */
/*                 DATA TYPES DEFINITIONS                                     */
/* ************************************************************************** */

/** @brief List of enemies
*/
typedef t_pos	*t_enemy_arr;

/** @brief Enemies structure
 * 
 *  @param enemies enemies array
 *  @param n_enemies number of enemies
*/
typedef struct s_enemies
{
	t_enemy_arr	enemies;
	int			n_enemies;
}				t_enemies;

#endif