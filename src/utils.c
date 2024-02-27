/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:19:57 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 17:07:25 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_objects_line(char *str, char c_object)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c_object)
			count ++;
		i++;
	}
	return (count);
}

int	ft_free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	return (free(arr), 0);
}

void	ft_get_p_position(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (g->map[x])
	{
		y = 0;
		while (g->map[x][y])
		{
			if (g->map[x][y] == 'P')
			{
				g->p_pos[0] = x;
				g->p_pos[1] = y;
			}
			y ++;
		}
		x ++;
	}
}
