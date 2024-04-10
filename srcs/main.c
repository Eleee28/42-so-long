/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:29 by elena             #+#    #+#             */
/*   Updated: 2024/04/10 10:58:02 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#ifdef __APPLE__

void	leaks(void)
{
	system("leaks -q so_long");
}

#elif __linux__

void	leaks(void)
{
	//system("valgrind --leak-check=full ./so_long files/small_map.ber");
}

#endif

int	main(int argc, char **argv)
{
	char	*file_name;
	t_game	game;

	atexit(leaks);
	if (argc != 2)
		print_error("Invalid number of arguments\n");
	file_name = argv[1];
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4))
		print_error("Invalid file extension\n");
	game.map.map = read_map(file_name);
	if (check_map(game.map.map))
		get_game_info(&game);
	srand(time(NULL));
	open_window(&game);
	ft_free_matrix(game.map.map);
	return (0);
}
