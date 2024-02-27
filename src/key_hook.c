/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:27:08 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 17:05:10 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_move_palyer(t_game *g, int x, int y)
{
	if (g->map[g->p_pos[0] + x][g->p_pos[1] + y] != '1')
	{
		if (x)
			g->p_pos[0] += x;
		else
			g->p_pos[1] += y;
		ft_printf("Moves: %i\n", g->moves++);
	}
	else
		return ;
}

int	ft_key_hook(int key_code, t_game *g)
{
	if (key_code == ESC)
		ft_on_close(g);
	if (key_code == W || key_code == UP)
		ft_move_palyer(g, -1, 0);
	if ((key_code == A || key_code == LEFT))
		ft_move_palyer(g, 0, -1);
	if ((key_code == S || key_code == DOWN))
		ft_move_palyer(g, 1, 0);
	if ((key_code == D || key_code == RIGHT))
		ft_move_palyer(g, 0, 1);
	if (g->map[g->p_pos[0]][g->p_pos[1]] == 'C')
	{
		g->coins_count--;
		g->map[g->p_pos[0]][g->p_pos[1]] = '0';
	}
	if (g->coins_count == 0 && g->map[g->p_pos[0]][g->p_pos[1]] == 'E')
		ft_on_close(g);
	ft_drau_map(g);
	return (0);
}
