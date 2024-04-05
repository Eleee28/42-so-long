/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele <ele@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:18:57 by elena             #+#    #+#             */
/*   Updated: 2024/03/25 08:21:04 by ele              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/** @brief Executes when there is an error in the map
 * 
 *  @details Frees the memory of the map matrix and prints the error
 * 
 *  @param map map matrix
 *  @param msg error message
*/
void    map_error(char **map, char *msg) {
    ft_free_matrix(map);
    print_error(msg);
}

/** @brief Prints the error
 * 
 *  @details Prints 'Error\n' along with the error message to the stderr
 * 
 *  @param msg error message
*/
void    print_error(char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(msg, 2);
    exit(1);
}