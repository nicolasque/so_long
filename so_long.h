/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:32:21 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:05 by nquecedo         ###   ########.fr       */
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

# define PIX 32

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SHIP "textures/ship(P).xpm"
# define WATER "textures/water(0).xpm"
# define CHEST "textures/chest(C).xpm"
# define PORT "textures/port(E).xpm"
# define BORDER "textures/border(1).xpm"

typedef struct t_game //maloqueado desde el inicio
{
	char	**map; //maloqueado desde que se lee el mapa enn FT_GET_MAP_CHAR
	char	**map_cpy;
	char	*map_url; 
	int		map_fd;

	void		*mlx;
	void		*window;

	int		heigth;
	int		with;

	void	*ship;
	void	*water;
	void	*chest;
	void	*port;
	void	*border;

	int		p_pos[2];
	int		moves;	

	int coins_count;
	int exit_count;
	int player_count;	
}	t_game;

int	ft_manage_input(int argc, char **argv, t_game *g);
int	ft_verify_invalid_map_chars(t_game *g);
int	ft_get_map_h_w(t_game *g);
char	**ft_get_map_char(t_game *g);
void	ft_count_objects_map(t_game *g);
int	ft_count_objects_line(char *str, char c_object);
int	ft_free_2d(char **arr);
void	ft_get_p_position(t_game *g);
void	ft_flood_fill(t_game *g, int x, int y);
int	ft_check_after_flod(t_game *g);
void	ft_map_copy(t_game *g);
int	ft_key_hook(int key_code, t_game *g);
int	ft_get_sprites(t_game *g);
void	ft_drau_map(t_game *g);
void	ft_free_textures(t_game *g);
int	ft_on_close(t_game *g);




// void	ft_print_map(char **map);


#endif //SO_LONG_H