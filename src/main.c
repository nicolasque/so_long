/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:54:34 by nquecedo          #+#    #+#             */
/*   Updated: 2024/03/06 02:49:19 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game_starter(t_game *g)
{
	g->mlx = mlx_init();
	g->moves = 0;
	g->window = mlx_new_window(g->mlx, g->with * PIX, \
			g->heigth * PIX, "SO_LONG");
	ft_get_sprites(g);

	ft_drau_map(g);
	mlx_hook(g->window, 17, 1, ft_on_close, g);
	mlx_key_hook(g->window, ft_key_hook, g);
	mlx_loop (g->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		return (ft_printf("Game malloc fail"), -1);
	ft_manage_input(argc, argv, g);
	ft_get_map_h_w(g);
	g->map = ft_get_map_char(g);
	if (!g->map)
		return (ft_printf("Problem geting the map"), -1);
	ft_count_objects_map(g);
	if (ft_verify_invalid_map_chars(g) == -1)
		return (-1);
	ft_get_p_position(g);
	ft_map_copy(g);
	ft_flood_fill(g, g->p_pos[0], g->p_pos[1]);
	ft_check_after_flod(g);
	ft_game_starter(g);
	ft_on_close(g);
	return (0);
}
