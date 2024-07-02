/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:12:09 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 14:31:25 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

/* ************************************************************************** */
/*                 MACROS DEFINITIONS                                         */
/* ************************************************************************** */

/* -------------- SCREEN DIMENSIONS -------------- */

# define IMG_W 64
# define IMG_H 64

/* -------------- BACKGROUND IMGS -------------- */

# define HEADER "textures/background/header.xpm"

# define GRASS "textures/background/grass.xpm"

/* -------------- TREE SPRITES -------------- */

# define TREE1 "textures/tree/tree1.xpm"
# define TREE2 "textures/tree/tree2.xpm"
# define TREE3 "textures/tree/tree3.xpm"
# define TREE4 "textures/tree/tree4.xpm"

/* -------------- DOOR SPRITES -------------- */

# define DOOR_CLOSE "textures/door/door_closed.xpm"
# define DOOR_OPEN "textures/door/door_open.xpm"

/* -------------- COLLECTIBLES SPRITES -------------- */

# define COLL1 "textures/collectible/star1.xpm"
# define COLL2 "textures/collectible/star2.xpm"

/* -------------- PLAYER SPRITES -------------- */

# define KIRBY_LEFT "textures/character/kirby_left.xpm"
# define KIRBY_RIGHT "textures/character/kirby_right.xpm"

/* -------------- ENEMY SPRITES -------------- */

# define ENEMY_LEFT "textures/character/enemy_left.xpm"
# define ENEMY_RIGHT "textures/character/enemy_right.xpm"

/* -------------- EXTRA SPRITES -------------- */

# define LIFE "textures/icons/life.xpm"
# define STAR "textures/icons/star_icon.xpm"

/* ************************************************************************** */
/*                 DATA STRUCTURES DEFINITIONS                                */
/* ************************************************************************** */

/** @brief Character structure
 * 
 *  @param l left sprite
 *  @param r right sprite
 *  @param curr current sprite
*/
typedef struct s_charac_sp
{
	void	*l;
	void	*r;
	void	*curr;
}			t_charac_sp;

/** @brief Sprites structure
 * 
 *  @param grass grass sprite
 *  @param header header sprite
 * 
 *  @param tree1 tree frame 1 sprite
 *  @param tree1 tree frame 2 sprite
 *  @param tree1 tree frame 3 sprite
 *  @param tree1 tree frame 4 sprite
 * 
 *  @param collec1 collectible frame 1 sprite
 *  @param collec2 collectible frame 2 sprite
 * 
 *  @param exit_open opened exit structure
 * 	@param exit_closed closed exit structure
 * 
 *  @param player player structure
 *  @param enemy enemy structure
 * 
 *  @param life life sprite
 *  @param star star sprite
*/
typedef struct s_sprites
{
	void		*grass;
	void		*header;

	void		*tree1;
	void		*tree2;
	void		*tree3;
	void		*tree4;

	void		*collec1;
	void		*collec2;

	void		*exit_open;
	void		*exit_closed;

	t_charac_sp	player;
	t_charac_sp	enemy;

	void		*life;
	void		*star;
}				t_sprites;

#endif