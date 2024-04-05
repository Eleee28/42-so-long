/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele <ele@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:07:15 by elena             #+#    #+#             */
/*   Updated: 2024/04/04 15:57:07 by ele              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../library/library.h"
# include <stdlib.h>
# include "player.h"

# define VALID_CHARS "01PCEX\0"

typedef struct s_map
{
	char	**map;
	char	**init_map;
	int		n_collec;
	t_pos	exit_coord;
	t_pos	init_coord;
}			t_map;

char	**read_map(char *file_name);
int		check_map(char **map);

int		is_rectangular(char **map);
int		valid_chars(char **map, int *n_e, int *n_p, int *n_c);
int		closed_map(char **map);
int		valid_path(char **map);
int		fill_with_ones(char **map, int row, int col);
t_pos	find_object(char **map, int c);
int		count_objects(char **map, int c);
int		check_path(char **map);

#endif