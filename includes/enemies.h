/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:58:29 by ele               #+#    #+#             */
/*   Updated: 2024/04/04 09:27:16 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H

# include "position.h"

typedef t_pos *t_enemy_arr;

typedef struct s_enemies
{
    t_enemy_arr   enemies;
    int         n_enemies;
}               t_enemies;

//int check_enemies(t_enemies enemies, t_pos pos);

#endif