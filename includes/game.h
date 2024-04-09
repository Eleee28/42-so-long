/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:49:35 by elena             #+#    #+#             */
/*   Updated: 2024/04/09 08:54:22 by ejuarros         ###   ########.fr       */
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

/** @brief Game structure
 * 
 *  @param map map structure
 *  @param enemies enemies structure
 *  @param player player structure
 *  @param mlx mlx structure
 *  @param map_w map width
 *  @param map_h map height
 *  @param screen_w screen width
 *  @param screen_h screen height
 *  @param frames current frame cycle
*/
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

	int			render;
}				t_game;

// INITIALIZE

/** @brief Initializes the sprites structure
 * 
 *  @param game game structure
 * 
 *  @return sprites structure
*/
t_sprites	init_sprites(t_game *game);

/** @brief Initializes the list of enemies
 * 
 *  @param game game structure
 *  @param n_enemies number of enemies
*/
void		init_enemies(t_game *game, int n);

/** @brief Gets the game info
 * 
 *  @param game game structure
*/
void		get_game_info(t_game *game);

// PRINT

/** @brief Prints the objects of the game
 * 
 *  @param game game structure
 *  @param pos position of the map
*/
void		print_obj(t_game *game, t_pos pos);

/** @brief Prints the game
 * 
 *  @param game game structure
 * 
 *  @return 0
*/
int			print_game(t_game *game);

/** @brief Prints the enemies
 * 
 *  @param game game structure
 *  @param pos position of the map
*/
void		print_enemies(t_game *game, t_pos pos);

/** @brief Prints the header
 * 
 *  @param game game structure
*/
void		print_header(t_game *game);

/** @brief Prints the end screen
 * 
 *  @param game game structure
 *  @param text text to print
*/
void		print_end_screen(t_game *game, char *text);

// MOVEMENT

/** @brief Moves the player
 * 
 *  @param game game structure
 *  @param keycode key representing the movement
*/
void		move_player(t_game *game, int keycode);

/** @brief Performs the player movement
 * 
 *  @param game game structure
 *  @param aux new position
*/
void		perform_move(t_game *game, t_pos aux);

/** @brief Moves the enemies
 * 
 *  @param game game structure
*/
void   		move_enemies(t_game *game);

// GAME

/** @brief Handles the keyboard input
 * 
 *  @param keycode code of the pressed key
 *  @param game game structure
 * 
 *  @return 0
*/
int			handle_input(int keycode, t_game *game);

/** @brief Opens a window and interacts with it
 * 
 *  @param game game structure
*/
void		open_window(t_game *game);

/** @brief Plays the game
 * 
 *  @param game game structure
 * 
 *  @return 0
*/
int			play_game(t_game *game);

// UTILS

/** @brief Checks whether a position is within map limits
 * 
 *  @param game game structure
 *  @param pos position
 * 
 *  @retval 1 if in board
 *  @retval 0 otherwise
*/
int			in_board(t_game game, t_pos pos);

/** @brief Resets the game
 * 
 *  @param game game structure
*/
void    	reset_game(t_game *game);

#endif