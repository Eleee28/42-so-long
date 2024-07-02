/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:01:35 by elena             #+#    #+#             */
/*   Updated: 2024/07/02 12:06:57 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

t_pos	find_object(char **map, int c)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return ((t_pos){i, j});
			j++;
		}
		i++;
	}
	return ((t_pos){-1, -1});
}

int	check_path(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map && map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'C')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	count_objects(char **map, int c)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}
