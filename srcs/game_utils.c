/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:06:53 by ele               #+#    #+#             */
/*   Updated: 2024/04/04 12:00:16 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	create_messages(t_game *game, char **life, char **collec, char **moves)
{
	char	*aux;
	
	aux = ft_itoa(game->player.life);
	*life = ft_strjoin("x0", aux);
	free(aux);
	aux = ft_itoa(game->player.collec);
	*moves = ft_strjoin(aux, "/");
	free(aux);
	aux = ft_itoa(game->map.n_collec);
	*collec = ft_strjoin(*moves, aux);
	free(*moves);
	free(aux);
	aux = ft_itoa(game->player.moves);
	*moves = ft_strjoin(" |  Movements: ", aux);
	free(aux);
}

/** @brief Prints the header information
 * 
 *  @details Uses strings to store the text to print. Clears the banner and 
 *  puts the corresponding information
 * 
 *  @param game game
*/
void    print_header(t_game *game)
{
    char	*collec;
	char	*moves;
	char	*life;
    int		i;
	
	collec = 0;
	moves = 0;
	life = 0;
	create_messages(game, &life, &collec, &moves);
    i = 0;
	while (i < game->map_w)
	{
		mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.blue, i * IMG_W, 0);
		i++;
	}
    mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.life, 6, 6);
	mlx_string_put(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, 25, 20, mlx_get_color_value(game->mlx.mlx_data.mlx_ptr, 0x00FFFFFF), life);
    mlx_put_image_to_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, game->mlx.sprites.coin.on, 55, 6);
	mlx_string_put(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, 75, 20, mlx_get_color_value(game->mlx.mlx_data.mlx_ptr, 0x00FFFFFF), collec);
	mlx_string_put(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, 100, 20, mlx_get_color_value(game->mlx.mlx_data.mlx_ptr, 0x00FFFFFF), moves);
	free(life);
	free(moves);
	free(collec);
}


void	print_end_screen(t_game *game, char *text)
{
	mlx_clear_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win);
	mlx_string_put(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, ((game->map_w / 2) - 1) * IMG_H, (game->map_h / 2) * IMG_W,
		mlx_get_color_value(game->mlx.mlx_data.mlx_ptr, 0x00FFFFFF), text);
	mlx_string_put(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win, ((game->map_w / 2) - 2) * IMG_H, ((game->map_h / 2) + 1)* IMG_W,
		mlx_get_color_value(game->mlx.mlx_data.mlx_ptr, 0x00FFFFFF), "Press [R] to reset");
}