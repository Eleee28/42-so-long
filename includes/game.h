/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:49:35 by elena             #+#    #+#             */
/*   Updated: 2024/04/04 16:16:53 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../library/library.h"
# include "../mlx/mlx.h"
# include "../mlx_linux/mlx.h"
# include "map.h"
# include "mlx_info.h"
# include "enemies.h"

typedef struct s_game
{
	t_map		map;
	t_enemies	enemies;
	t_player	player;
	t_mlx		mlx;
	int			map_w;
	int			map_h;
	int			screen_w;
	int			screen_h;
	int			frames;
}				t_game;

void		open_window(t_game *game);
void		get_game_info(t_game *game);
int			play_game(t_game *game);
int			print_game(t_game *game);
void		print_obj(t_game *game, t_pos pos);

void   		move_enemies(t_game *game);
void		print_end_screen(t_game *game, char *text);
t_sprites	init_sprites(t_game *game);

int			handle_input(int keycode, t_game *game);
int			in_board(t_game game, t_pos pos);
void		move_player(t_game *game, int keycode);
void		perform_move(t_game *game, t_pos aux);

void		print_enemies(t_game *game, t_pos pos);
void		init_enemies(t_game *game, int n);

void		print_header(t_game *game);
void    	reset_game(t_game *game);

#endif