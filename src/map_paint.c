/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:28:50 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 16:32:59 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_get_sprites(t_game *g)
{
	int	x;
	int	y;

	g->water = mlx_xpm_file_to_image(g->mlx, WATER, &x, &y);
	g->border = mlx_xpm_file_to_image(g->mlx, BORDER, &x, &y);
	g->chest = mlx_xpm_file_to_image(g->mlx, CHEST, &x, &y);
	g->port = mlx_xpm_file_to_image(g->mlx, PORT, &x, &y);
	g->ship = mlx_xpm_file_to_image(g->mlx, SHIP, &x, &y);
	if (!g->water || !g->border || !g->chest || !g->port
		|| !g->ship)
	{
		ft_printf("Error\nFalta alguna textura\n");
		return (ft_free_2d(g->map), free(g) , exit(-1), -1);
	}
	return (0);
}

static void	ft_put_player(t_game *g, int y, int x)
{
	mlx_put_image_to_window(g->mlx, g->window, g->ship, PIX * x, PIX * y);
}
static void	ft_put_sprite(t_game *g,char c, int y, int x)
{
	mlx_put_image_to_window(g->mlx, g->window, g->water, PIX * x, PIX * y);
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->window, g->water, PIX * x, PIX * y);
	else if (c == '1')
		mlx_put_image_to_window(g->mlx, g->window, g->border, PIX * x, PIX * y);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->window, g->chest, PIX * x, PIX * y);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->window, g->port, PIX * x, PIX * y);
}

void	ft_drau_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < g->with)
	{
		x = 0;
		while (x < g->heigth)
		{
			ft_put_sprite(g, g->map[x][y] ,x, y);
			ft_put_player(g, g->p_pos[0], g->p_pos[1]);
			x ++;
		}
		y ++;
	}
}
