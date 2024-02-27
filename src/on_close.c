/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:31:42 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 16:32:21 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_textures(t_game *g)
{
	if (g->ship)
		mlx_destroy_image(g->mlx, g->ship);
	if (g->water)
		mlx_destroy_image(g->mlx, g->water);
	if (g->chest)
		mlx_destroy_image(g->mlx, g->chest);
	if (g->port)
		mlx_destroy_image(g->mlx, g->port);
	if (g->border)
		mlx_destroy_image(g->mlx, g->border);
}

int	ft_on_close(t_game *g)
{
	if (g->mlx && g->window)
		mlx_destroy_window(g->mlx, g->window);
	free(g->mlx);
	ft_free_textures(g);
	ft_free_2d(g->map);
	free(g);
	exit(0);
	return (0);
}
