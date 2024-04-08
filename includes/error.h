/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:02:32 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/06 04:31:52 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/** @brief Prints the error message
 * 
 *  @param msg error message
*/
void    print_error(char *msg);

/** @brief Executes when there is an error in the map
 * 
 *  @param map map matrix
 *  @param msg error message
*/
void    map_error(char **map, char *msg);

#endif