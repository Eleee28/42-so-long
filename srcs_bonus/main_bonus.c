/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:29 by elena             #+#    #+#             */
/*   Updated: 2024/09/28 20:37:03 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"
#include <time.h>

int	main(int argc, char **argv)
{
	char	*file_name;
	t_game	game;

	if (argc != 2)
		print_error("Invalid number of arguments\n");
	file_name = argv[1];
	if (ft_strncmp(file_name + ft_strlen(file_name) - LEN, EXT, 4))
		print_error("Invalid file extension\n");
	game.map.map = read_map(file_name);
	if (game.map.map)
	{
		if (check_map(game.map.map))
			get_game_info(&game);
		srand(time(NULL));
		open_window(&game);
		ft_free_matrix(game.map.map);
	}
	return (0);
}
