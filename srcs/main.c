/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:29 by elena             #+#    #+#             */
/*   Updated: 2024/07/02 12:32:44 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	*file_name;
	t_game	game;
	int		len;

	if (argc != 2)
		print_error("Invalid number of arguments\n");
	file_name = argv[1];
	len = ft_strlen(file_name);
	if (ft_strncmp(file_name + len - LEN, EXT, 4))
		print_error("Invalid file extension\n");
	game.map.map = read_map(file_name);
	if (game.map.map)
	{
		if (check_map(game.map.map))
			get_game_info(&game);
		open_window(&game);
		ft_free_matrix(game.map.map);
	}
	else
		print_error("Invalid content\n");
	return (0);
}
