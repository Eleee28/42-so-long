/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:17:43 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 10:01:21 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_window(&game->mlx.mlx_data);
	else if (keycode == KEY_R)
		reset_game(game);
	else
		move_player(game, keycode);
	return (0);
}
