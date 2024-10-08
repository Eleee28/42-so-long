/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele <ele@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:49:38 by ejuarros          #+#    #+#             */
/*   Updated: 2024/09/24 13:27:49 by ele              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INFO_H
# define MLX_INFO_H

# include "textures.h"

/* ************************************************************************** */
/*                 MACROS DEFINITIONS                                         */
/* ************************************************************************** */

# ifdef __APPLE__

#  define KEY_A 0
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2

#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124

#  define KEY_ESC 53
#  define KEY_R 15

#  define CLOSEBUTTON 17
#  define CLOSEBUTTONMASK 0

# elif __linux__

#  define KEY_A 97
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100

#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363

#  define KEY_ESC 65307
#  define KEY_R 114
#  define CLOSEBUTTON 33
#  define CLOSEBUTTONMASK 0

#  define ON_KEYDOWN 2

# endif

/* ************************************************************************** */
/*                 DATA STRUCTURES DEFINITIONS                                */
/* ************************************************************************** */

/** @brief Mlx data structure
 * 
 *  @param mlx_ptr mlx pointer
 *  @param mlx_win mlx window pointer
*/
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_mlx_data;

/** @brief Mlx structure
 * 
 *  @param mlx_data mlx data structure
 *  @param sprites sprites structure
*/
typedef struct s_mlx
{
	t_mlx_data	mlx_data;
	t_sprites	sprites;
}				t_mlx;

#endif