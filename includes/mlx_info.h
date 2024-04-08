/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:49:38 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/08 23:32:24 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INFO_H
# define MLX_INFO_H

# include "textures.h"

# ifdef __APPLE__

	# define KEY_A 0
	# define KEY_W 13
	# define KEY_S 1
	# define KEY_D 2
	
	# define KEY_UP 126
	# define KEY_DOWN 125
	# define KEY_LEFT 123
	# define KEY_RIGHT 124
	
	# define KEY_ESC 53
	# define KEY_R 15

	# define CloseButton 17
	# define CloseButtonMask 0

# elif __linux__

	# define KEY_A 97
	# define KEY_W 119
	# define KEY_S 115
	# define KEY_D 100
	
	# define KEY_UP 65362
	# define KEY_DOWN 65364
	# define KEY_LEFT 65361
	# define KEY_RIGHT 65363
	
	# define KEY_ESC 65307
	# define KEY_R

	# define CloseButton 33
	# define CloseButtonMask 0
	

# endif

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_mlx_data;

typedef struct s_mlx
{
	t_mlx_data	mlx_data;
	t_sprites	sprites;
}				t_mlx;

/** @brief Executes every time a key is pressed
 *  
 *  @details KEYSYm vs KEYCODE
 *  A keycode is a hardware-specific code ent by the keyboard for a key press.
 *  A keysym is the abstract representation of it, used in software to 
 *  identify the key regardless of hardware.
*/

int	exit_window(t_mlx_data *data);

#endif