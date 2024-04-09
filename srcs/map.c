/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:47:08 by elena             #+#    #+#             */
/*   Updated: 2024/04/09 08:59:03 by ejuarros         ###   ########.fr       */
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


void    reset_game(t_game *game)
{
    game->render = 0;
    usleep(1000);
    //ft_printf("Reset\n");

    char **map = game->map.map;
    // ft_free_matrix(game->map.map);
    game->map.map = NULL;
    ft_free_matrix(map);

    //ft_printf("------INIT_MAP-----\n");
    //ft_print_matrix(game->map.init_map);
    //ft_printf("------MAP-----\n");
    //ft_print_matrix(game->map.map);
    map = ft_dup_matrix(game->map.init_map);
    if (!map)
        print_error("Error using malloc");
    game->map.map = map;
    //ft_print_matrix(game->map.map);
    //ft_printf("Hello\n");
    //free(game->enemies.enemies);
    init_enemies(game, game->enemies.n_enemies);
    game->frames = 0;
    game->player.collec = 0;
    game->player.life = 1;
    game->player.coord = game->map.init_coord;
    game->player.moves = 0;
    game->render = 1;
}