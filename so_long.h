/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:32:21 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/26 16:33:36 by nquecedo         ###   ########.fr       */
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

# define PIXEL 32

typedef struct t_game //maloqueado desde el inicio
{
	char	**map; //maloqueado desde que se lee el mapa enn FT_GET_MAP_CHAR
	char	**map_cpy;
	char	*map_url; 
	int		map_fd;

	void		*mlx;
	void		*window;

	int		map_heigth;
	int		map_with;

	void	*ship;
	void	*water;
	void	*chest;
	void	*portal;

	int		player_pos[2];
	int		moves;	

	int coins_count;
	int exit_count;
	int player_count;	
}	t_game;

#endif //SO_LONG_H