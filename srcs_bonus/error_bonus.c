/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:18:57 by elena             #+#    #+#             */
/*   Updated: 2024/07/02 12:05:32 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

/** 
 *  @details Frees the memory of the map matrix and prints the error
*/
void	map_error(char **map, char *msg)
{
	ft_free_matrix(map);
	print_error(msg);
}

/** 
 *  @details Prints 'Error\n' along with the error message to the stderr
*/
void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}
