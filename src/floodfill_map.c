/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:22:56 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 16:25:28 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_copy(t_game *g)
{
	g->map_cpy = ft_get_map_char(g);
}

void	ft_flood_fill(t_game *g, int x, int y)
{
	if (x >= g->heigth || y >= g->with || x <= 0 || y <= 0 || g->map_cpy[x][y] == 'x')
		return ;
	if (g->map_cpy[x][y] == '0' || g->map_cpy[x][y] == 'P' || g->map_cpy[x][y] == 'E' || g->map_cpy[x][y] == 'C')
		g->map_cpy[x][y] = 'x';
	if (g->map_cpy[x][y] == '1')
		return ;
	ft_flood_fill(g, x, y - 1);
	ft_flood_fill(g, x, y + 1);
	ft_flood_fill(g, x - 1, y);
	ft_flood_fill(g, x + 1, y);
}

int	ft_check_after_flod(t_game *g)
{
	int	x;

	x = 0;
	while (g->map_cpy[x])
	{
		if (ft_count_objects_line(g->map_cpy[x], 'C') || \
		ft_count_objects_line(g->map_cpy[x], 'P') || \
		ft_count_objects_line(g->map_cpy[x], 'E'))
		{
			ft_free_2d(g->map_cpy);
			ft_free_2d(g->map);
			free(g);
			ft_printf("No valida map");
			exit(-1);
		}
		x++;
	}
	ft_free_2d(g->map_cpy);
	return (0);
}

