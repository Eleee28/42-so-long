/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:02:32 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/09 20:37:57 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

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