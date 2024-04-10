/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:49:35 by elena             #+#    #+#             */
/*   Updated: 2024/04/10 15:37:44 by ejuarros         ###   ########.fr       */
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

/* ************************************************************************** */
/*                 DATA TYPES DEFINITIONS                                     */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                 FUNTIONS DEFINITIONS                                       */
/* ************************************************************************** */

/* -------------- INITIALIZE -------------- */		

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

/* -------------- PRINT -------------- */

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

/** @brief Creates the messages to print on the screen for each frame
 * 
 *  @param game game structure
 *  @param life string to store the life message
 *  @param coll string to store the collectibles message
 *  @param mov string to store the moves message
*/
void	create_messages(t_game *game, char **life, char **coll, char **mov);

/** @brief Puts the information on the screen
 * 
 *  @param game game structure
 *  @param life string with the life message
 *  @param collec string with the collectibles message
 *  @param move string with the moves message
*/
void	put_info(t_game *game, char *life, char *collec, char *moves);

/* -------------- MOVEMENT -------------- */

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
//void		perform_move(t_game *game, t_pos aux);

/** @brief Moves the enemies
 * 
 *  @param game game structure
*/
void		move_enemies(t_game *game);

/* -------------- GAME -------------- */

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

/* -------------- UTILS -------------- */

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
void		reset_game(t_game *game);

/* -------------- SPRITES -------------- */

/** @brief Initializes the sprites structure
 * 
 *  @param game game structure
 * 
 *  @return sprites structure
*/
t_sprites	init_sprites(t_game *game);

void init_background_imgs(t_game *game, t_sprites *sprites);

void init_tree_sprites(t_game *game, t_sprites *sprites);

void init_collec_sprites(t_game *game, t_sprites *sprites);

void init_door_sprites(t_game *game, t_sprites *sprites);

void init_enemy_sprites(t_game *game, t_sprites *sprites);

void init_extra_sprites(t_game *game, t_sprites *sprites);

void init_player_sprites(t_game *game, t_sprites *sprites);

void    put_tree_sprite(t_game *game, t_pos pos);

void    put_collec_sprite(t_game *game, t_pos pos);

#endif