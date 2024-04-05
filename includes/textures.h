/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:12:09 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/04 09:43:06 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# define IMG_W 32
# define IMG_H 32

# define BLACK "textures/black_32.xpm"
# define BLUE "textures/blue_32.xpm"

# define GRASS "textures/grass_32.xpm"
# define TREE "textures/tree.xpm"

# define DOOR_CLOSE "textures/door_close_32.xpm"
# define DOOR_OPEN "textures/door_open_32.xpm"

# define LIFE "textures/life_18.xpm"
//# define COIN_OFF_PATH "textures/star_18.xpm"
# define COIN_ON "textures/star_18.xpm"

# define KIRBY_NORMAL "textures/kirby_normal.xpm"

# define ENEMY_NORMAL "textures/exit.xpm"

typedef struct s_charac_sp
{
    void    *up;
    void    *down;
    void    *left;
    void    *right;
}           t_charac_sp;

typedef struct s_coin_sp
{
    void    *on;
    void    *off;
}           t_coin_sp;

typedef struct s_exit_sp
{
    void    *open;
    void    *close;
}           t_exit_sp;

typedef struct s_sprites
{
    void        *black;
    void        *blue;
    void        *grass;
    void        *tree;
    t_exit_sp   exit;
    void        *life;
    t_coin_sp   coin;
    t_charac_sp player;
    t_charac_sp enemy;
}               t_sprites;

#endif