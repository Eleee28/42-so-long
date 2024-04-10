/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:47:08 by elena             #+#    #+#             */
/*   Updated: 2024/04/10 11:01:55 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>

char    **read_map(char *file_name)
{
    char    **map;
    char    *line;
    char    *tmp;
    int     fd;
    
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        print_error("Couldn't open the file\n");
    line = get_next_line(fd);
    map = NULL;
    while (line)
    {
        if (line && line[ft_strlen(line) - 1] == '\n')
        {
            tmp = ft_substr(line, 0, ft_strlen(line) - 1);
            free(line);
            line = tmp;
        }
        map = ft_add_matrix(map, line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return(map);
}

int check_map(char **map)
{
    int n_e;
    int n_p;
    int n_c;

    n_e = 0;
    n_p = 0;
    n_c = 0;
    
    if (!is_rectangular(map))   // check if map is rectangular
        map_error(map, "Map is not rectangular\n");
    if (!closed_map(map)) // check if it is surrounded by walls
        map_error(map, "Map is not surrounded by walls\n");
    if (!valid_path(map)) // check if it has a valid path
        map_error(map, "Map has no valid path\n");
    if (!valid_chars(map, &n_e, &n_p, &n_c)) // check if map has only valid characters
        map_error(map, "Invalid characters in map\n");
    if (n_e != 1 || n_p != 1 || n_c < 1) // check if map has one exit, one player and at least one collectible
        map_error(map, "Invalid number of elements in map\n");
    return (1);
}
