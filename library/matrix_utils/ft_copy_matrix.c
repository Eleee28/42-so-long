/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:35 by elena             #+#    #+#             */
/*   Updated: 2024/04/04 16:03:33 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_utils.h"
#include "../libft/libft.h"

void    ft_copy_matrix(char **src, char **dest)
{
    int     i;

    i = 0;
    while (src && src[i])
    {
        dest[i] = ft_strdup(src[i]);
        i++;
    }
    dest[i] = NULL;
}