/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:58:29 by ele               #+#    #+#             */
/*   Updated: 2024/04/09 20:36:57 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H

# include "position.h"

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