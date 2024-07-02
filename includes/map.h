/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:07:15 by elena             #+#    #+#             */
/*   Updated: 2024/07/02 11:54:25 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../library/library.h"
# include <stdlib.h>
# include "player.h"

# define VALID_CHARS "01PCE\0"
# define MAX_SIZE 256

/* ************************************************************************** */
/*                 DATA TYPES DEFINITIONS                                     */
/* ************************************************************************** */

/** @brief Map structure
 * 
 *  @param map current map
 *  @param init_map original map
 *  @param n_collec total number of collectibles
 *  @param exit_coord exit coordinates
 *  @param init_coord initial player coordinates
*/
typedef struct s_map
{
	char	**map;
	char	**init_map;
	int		n_collec;
	t_pos	exit_coord;
	t_pos	init_coord;
}			t_map;

/* ************************************************************************** */
/*                 FUNCTIONS DEFINITIONS                                      */
/* ************************************************************************** */

/** @brief Reads the map
 * 
 *  @param file_name file name
 * 
 *  @return map
*/
char	**read_map(char *file_name);

/** @brief Checks whether the map is valid
 * 
 *  @param map map
 * 
 *  @retval 1 if valid map
 *  @retval 0 otherwise
*/
int		check_map(char **map);

/* -------------- MAP VALIDITY -------------- */

/** @brief Checks whether the map is rectangular
 * 
 *  @param map map
 * 
 *  @retval 1 if rectangular
 *  @retval 0 otherwise
*/
int		is_rectangular(char **map);

/** @brief Checks whether the map has valid characters
 * 
 *  @param map map
 *  @param n_e number of exits (output param)
 *  @param n_p number of player pos (output param)
 *  @param n_c number of collectibles (output param)
 * 
 *  @retval 1 if valid characters
 *  @retval 0 otherwise
*/
int		valid_chars(char **map, int *n_e, int *n_p, int *n_c);

/** @brief Checks whether the map is closed
 * 
 *  @param map map
 * 
 *  @retval 1 if closed
 *  @retval 0 otherwise
*/
int		closed_map(char **map);

/** @brief Checks whether the map has a valid path
 * 
 *  @param map map
 * 
 *  @retval 1 if valid path present
 *  @retval 0 otherwise
*/
int		valid_path(char **map);

/** @brief Fills the map with ones recursively
 * 
 *  @param map map
 *  @param row row
 *  @param col column
 * 
 *  @retval 1 if we can continue filling
 *  @retval 0 otherwise
*/
int		fill_with_ones(char **map, int row, int col);

/** @brief Finds an object in the map
 * 
 *  @param map map
 *  @param c object to find
 * 
 *  @return position of the object
*/
t_pos	find_object(char **map, int c);

/** @brief Counts the number of objects
 * 
 *  @param map map
 *  @param c object
 * 
 *  @return number of objects
*/
int		count_objects(char **map, int c);

/** @brief Checks the path in the map
 * 
 *  @param map map
 * 
 *  @retval 1 if there is a path
 *  @retval 0 otherwise
*/
int		check_path(char **map);

#endif