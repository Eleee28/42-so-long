/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:12:09 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/02 09:42:50 by ejuarros         ###   ########.fr       */
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

# define BLACK "textures/background/black_32.xpm"
# define BLUE "textures/background/blue_32.xpm"

# define HEADER "textures_v2/xpm/background/header2.xpm"

# define GRASS "textures_v2/xpm/background/grass.xpm"

/* -------------- TREE SPRITES -------------- */

//# define TREE "textures/tree.xpm"
# define TREE1 "textures_v2/xpm/tree/tree1.xpm"
# define TREE2 "textures_v2/xpm/tree/tree2.xpm"
# define TREE3 "textures_v2/xpm/tree/tree3.xpm"
# define TREE4 "textures_v2/xpm/tree/tree4.xpm"

/* -------------- DOOR SPRITES -------------- */

# define DOOR_CLOSE "textures_v2/xpm/door/door_closed.xpm"
# define DOOR_OPEN "textures_v2/xpm/door/door_open.xpm"

/* -------------- COLLECTIBLES SPRITES -------------- */

# define COLL1 "textures_v2/xpm/collectible/star1.xpm"
# define COLL2 "textures_v2/xpm/collectible/star2.xpm"

/* -------------- PLAYER SPRITES -------------- */

# define KIRBY_LEFT "textures_v2/xpm/character/kirby_left.xpm"
# define KIRBY_RIGHT "textures_v2/xpm/character/kirby_right.xpm"

/* -------------- ENEMY SPRITES -------------- */

# define ENEMY_LEFT "textures_v2/xpm/character/enemy_left.xpm"
# define ENEMY_RIGHT "textures_v2/xpm/character/enemy_right.xpm" 

/* -------------- EXTRA SPRITES -------------- */

# define LIFE "textures_v2/xpm/icons/life2.xpm"
# define STAR "textures_v2/xpm/icons/star_icon2.xpm"

/* ************************************************************************** */
/*                 DATA STRUCTURES DEFINITIONS                                */
/* ************************************************************************** */

/** @brief Character structure
 * 
 *  @param up up sprite
 *  @param down down sprite
 *  @param left left sprite
 *  @param right right sprite
*/
typedef struct s_charac_sp
{
	void	*l;
	void	*r;
	void	*curr;
}			t_charac_sp;

/** @brief Sprites structure
 * 
 *  @param black black background sprite
 *  @param blue blue background sprite
 *  @param grass grass sprite
 *  @param tree tree sprite
 *  @param exit exit structure
 *  @param life life sprite
 *  @param coin coin structure
 *  @param player player structure
 *  @param enemy enemy structure
*/
typedef struct s_sprites
{
	void		*black;
	void		*blue;
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