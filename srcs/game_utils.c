/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:06:53 by ele               #+#    #+#             */
/*   Updated: 2024/04/09 22:27:58 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/** @brief Creates the messages to print on the screen for each frame
 * 
 *  @param game game structure
 *  @param life string to store the life message
 *  @param coll string to store the collectibles message
 *  @param mov string to store the moves message
*/
static void	create_messages(t_game *game, char **life, char **coll, char **mov)
{
	char	*aux;

	aux = ft_itoa(game->player.life);
	*life = ft_strjoin("x0", aux);
	free(aux);
	aux = ft_itoa(game->player.collec);
	*mov = ft_strjoin(aux, "/");
	free(aux);
	aux = ft_itoa(game->map.n_collec);
	*coll = ft_strjoin(*mov, aux);
	free(*mov);
	free(aux);
	aux = ft_itoa(game->player.moves);
	*mov = ft_strjoin(" |  Movements: ", aux);
	free(aux);
}

static void	put_info(t_game *game, char *life, char *collec, char *moves)
{
	int		i;
	void	*ptr;
	void	*win;
	int		color;

	i = 0;
	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	while (i < game->map_w)
	{
		mlx_put_image_to_window(ptr, win, game->mlx.sprites.blue, i * IMG_W, 0);
		i++;
	}
	color = mlx_get_color_value(ptr, 0x00FFFFFF);
	mlx_put_image_to_window(ptr, win, game->mlx.sprites.life, 6, 6);
	mlx_string_put(ptr, win, 25, 20, color, life);
	mlx_put_image_to_window(ptr, win, game->mlx.sprites.coin.on, 55, 6);
	mlx_string_put(ptr, win, 75, 20, color, collec);
	mlx_string_put(ptr, win, 100, 20, color, moves);
}

/**
 *  @details Uses strings to store the text to print. Clears the banner and 
 *  puts the corresponding information
*/
void	print_header(t_game *game)
{
	char	*collec;
	char	*moves;
	char	*life;

	collec = 0;
	moves = 0;
	life = 0;
	create_messages(game, &life, &collec, &moves);
	put_info(game, life, collec, moves);
	free(life);
	free(moves);
	free(collec);
}

void	print_end_screen(t_game *game, char *text)
{
	void				*ptr;
	void				*win;
	unsigned int		color;

	ptr = game->mlx.mlx_data.mlx_ptr;
	win = game->mlx.mlx_data.mlx_win;
	color = mlx_get_color_value(ptr, 0x00FFFFFF);
	mlx_clear_window(ptr, win);
	mlx_string_put(ptr, win, ((game->map_w / 2) - 1) * IMG_H,
		(game->map_h / 2) * IMG_W, color, text);
	mlx_string_put(ptr, win, ((game->map_w / 2) - 2) * IMG_H,
		((game->map_h / 2) + 1) * IMG_W, color, "Press [R] to reset");
}
