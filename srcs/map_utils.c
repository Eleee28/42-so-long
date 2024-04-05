/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:36:11 by elena             #+#    #+#             */
/*   Updated: 2024/04/04 09:08:32 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map && map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_chars(char **map, int *n_e, int *n_p, int *n_c)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(VALID_CHARS, map[i][j]))
				return (0);
			else if (map[i][j] == 'E')
				(*n_e)++;
			else if (map[i][j] == 'P')
				(*n_p)++;
			else if (map[i][j] == 'C')
				(*n_c)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	closed_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		if (i == 0 || i == ft_len_matrix(map) - 1)
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	valid_path(char **map)
{
	char	**copy;
	t_pos	player;
	int		ret;

	copy = (char **)malloc(sizeof(char *) * (ft_len_matrix(map) + 1));
	if (!copy)
		return (0);
	ft_copy_matrix(map, copy);
	player = find_object(map, 'P');  // find player position
	// Fill copy of map with 1s
	ret = fill_with_ones(copy, player.x, player.y);    
	// Check if there are any 0s in the copy of the map
	ret = ret && check_path(copy);    
	ft_free_matrix(copy);
	return (ret);
}

// find the player position
// starting from the player position, flood the map with 1s
// until you find a wall or an exit
// if you find a collectible, flood it with 1s and keep going
// if you find an exit, flood it with 1s and return
// if you find a wall, return
// if you find a 1, return
int	fill_with_ones(char **map, int row, int col)
{
	int	ret;

	ret = 0;
	if (row < 0 || (size_t)row >= ft_len_matrix(map) || col < 0 || (size_t)col >= ft_strlen(map[0])
		|| map[row][col] == '1')
		return 0;
	if (map[row][col] == 'E')
		ret = 1;
	map[row][col] = '1';
	ret = fill_with_ones(map, row - 1, col) || ret;	// UP
	ret = fill_with_ones(map, row + 1, col) || ret;	// DOWN
	ret = fill_with_ones(map, row, col - 1) || ret;	// LEFT
	ret = fill_with_ones(map, row, col + 1) || ret;	// RIGHT
	return (ret);
}
