/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:32:21 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/25 18:09:47 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <strings.h>
# include ".mlx/mlx.h"
# include "libft/libft.h"

typedef struct t_game //maloqueado desde el inicio
{
	char	**map; //maloqueado desde que se lee el mapa enn FT_GET_MAP_CHAR
	char	*map_url; 
	int		map_fd;

	int		map_heigth;
	int		map_with;

	int		x;
	int		y;
	int		player_pos[2];

	int coins_count;
	int exit_count;
	int player_count;	
}	t_game;

#endif //SO_LONG_H