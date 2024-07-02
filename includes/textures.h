/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:12:09 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 14:46:10 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

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
 *  @param tree tree sprite
 * 
 *  @param collec collectible sprite
 * 
 *  @param exit_open opened exit structure
 * 	@param exit_closed closed exit structure
 * 
 *  @param player player structure

 *  @param life life sprite
 *  @param star star sprite
*/
typedef struct s_sprites
{
	void		*grass;
	void		*header;

	void		*tree;

	void		*collec;

	void		*exit_open;
	void		*exit_closed;

	t_charac_sp	player;

	void		*life;
	void		*star;
}				t_sprites;

#endif