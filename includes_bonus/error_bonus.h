/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:02:32 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 11:56:25 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

/* ************************************************************************** */
/*                 FUNCTIONS DEFINITIONS                                      */
/* ************************************************************************** */

/** @brief Prints the error message
 * 
 *  @param msg error message
*/
void	print_error(char *msg);

/** @brief Executes when there is an error in the map
 * 
 *  @param map map matrix
 *  @param msg error message
*/
void	map_error(char **map, char *msg);

#endif