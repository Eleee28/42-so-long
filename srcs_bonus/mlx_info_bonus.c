/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele <ele@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:17:43 by ejuarros          #+#    #+#             */
/*   Updated: 2024/09/24 13:28:47 by ele              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static void	destroy_img(void *img, void *ptr)
{
	if (img)
		mlx_destroy_image(ptr, img);
}

static void	destroy_images(t_sprites *sprites, void *ptr)
{
	destroy_img(sprites->collec1, ptr);
	destroy_img(sprites->collec2, ptr);
	destroy_img(sprites->exit_closed, ptr);
	destroy_img(sprites->exit_open, ptr);
	destroy_img(sprites->grass, ptr);
	destroy_img(sprites->header, ptr);
	destroy_img(sprites->life, ptr);
	destroy_img(sprites->player.l, ptr);
	destroy_img(sprites->player.r, ptr);
	destroy_img(sprites->enemy.l, ptr);
	destroy_img(sprites->enemy.r, ptr);
	destroy_img(sprites->star, ptr);
	destroy_img(sprites->tree1, ptr);
	destroy_img(sprites->tree2, ptr);
	destroy_img(sprites->tree3, ptr);
	destroy_img(sprites->tree4, ptr);
}

int	exit_window(t_game *game)
{
	destroy_images(&game->mlx.sprites, game->mlx.mlx_data.mlx_ptr);
	mlx_destroy_window(game->mlx.mlx_data.mlx_ptr, game->mlx.mlx_data.mlx_win);
	mlx_loop_end(game->mlx.mlx_data.mlx_ptr);
	mlx_destroy_display(game->mlx.mlx_data.mlx_ptr);
	free(game->mlx.mlx_data.mlx_ptr);
	ft_free_matrix(game->map.map);
	ft_free_matrix(game->map.init_map);
	free(game->enemies.enemies);
	exit(0);
}

/**   
 *  @details Executes every time a key is pressed
 *  KEYSYm vs KEYCODE
 *  A keycode is a hardware-specific code ent by the keyboard for a key press.
 *  A keysym is the abstract representation of it, used in software to 
 *  identify the key regardless of hardware.
*/
int	handle_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_window(game);
	else if (keycode == KEY_R)
		reset_game(game);
	else
		move_player(game, keycode);
	return (0);
}
