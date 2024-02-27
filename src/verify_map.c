/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:14:18 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 17:09:29 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_is_valid_char(int c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1' || c == '\n')
		return (0);
	return (-1);
}

int	ft_verify_invalid_map_chars(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (g->map[x])
	{
		y = 0;
		while (g->map[x][y] && g->map[x][y] != '\n')
		{
			if (ft_is_valid_char(g->map[x][y]))
				return (ft_free_2d(g->map), free(g), \
						ft_printf("Invalid character in map"), -1);
			if (g->map[0][y] != '1' || g->map[g->heigth - 1][y] != '1')
				return (ft_free_2d(g->map), free(g), \
						ft_printf("No proper border"), -1);
			y ++;
		}
		if (g->map[x][0] != '1' || g->map[x][g->with - 1] != '1')
			return (ft_free_2d(g->map), free(g), \
				ft_printf("No proper border"), -1);
		x ++;
	}
	return (0);
}

static int	ft_verify_obj_count(t_game *g)
{
	if (g->coins_count < 1)
		return (ft_free_2d(g->map), free(g), ft_printf("Not enoug coins"), -1);
	if (g->exit_count != 1)
		return (ft_free_2d(g->map), free(g), ft_printf("Invalid exit num"), -1);
	if (g->player_count != 1)
		return (ft_free_2d(g->map), free(g), ft_printf("Invalid player n"), -1);
	else
		return (0);
}

void	ft_count_objects_map(t_game *g)
{
	int	x;

	x = 0;
	g->player_count = 0;
	g->coins_count = 0;
	g->exit_count = 0;
	while (g->map[x])
	{
		g->player_count += ft_count_objects_line(g->map[x], 'P');
		g->coins_count += ft_count_objects_line(g->map[x], 'C');
		g->exit_count += ft_count_objects_line(g->map[x], 'E');
		x ++;
	}
	if (ft_verify_obj_count(g) == -1)
		exit(-1);
}
