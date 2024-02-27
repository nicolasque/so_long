/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:54:34 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 17:02:26 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	ft_manage_input(int argc, char **argv, t_game *g)
// {
// 	char	try_to_read[2];

// 	if (argc != 2)
// 		return (ft_printf("Wrong cuantity of args\n"), free(g), -1);
// 	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL || \
// 			ft_strlen(argv[1]) <= 4)
// 		return (ft_printf("Map is not .ber\n"), free(g), -1);
// 	g->map_fd = open(argv[1], O_RDONLY);
// 	if (g->map_fd < 0 || read(g->map_fd, try_to_read, 0) < 0)
// 		return (ft_printf("Problem opening the fd"), close(g->map_fd),
// 		free(g) , -1);
// 	g->map_url = argv[1];
// 	return (0);
// }

// int	ft_free_2d(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free (arr[i]);
// 		i++;
// 	}
// 	return (free(arr), 0);
// }

// int	ft_map_whith(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] != '\n' && line[i] != '\r' && line[i] != '\0')
// 		i ++;
// 	return (i);
// }

// // Me ocupo dentro de la funcion de 
// // liverar si aloqeo nueva memoriia y 
// // devuelvo un int segun si l programa ha tendo exito o no 
// int	ft_get_map_h_w(t_game *g)
// {
// 	char	*line;

// 	line = get_next_line(g->map_fd);
// 	if (!line)
// 		return (ft_printf("Invalid map"), free(g), -1);
// 	g->with = ft_map_whith(line);
// 	g->heigth = 0;
// 	while (line)
// 	{
// 		if (g->with != ft_map_whith(line))
// 			return (ft_printf("Invalid map"), free(line), free(g), -1);
// 		g->heigth ++;
// 		line = get_next_line(g->map_fd);
// 		if (!line)
// 			return (0);
// 	}
// 	close (g->map_fd);
// 	free(line);
// 	return (0);
// }

// 0 si todo bien -1  si caracter no valido 
// int	ft_is_valid_char(int c)
// {
// 	if (c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1' || c == '\n')
// 		return (0);
// 	return (-1);
// }

// int	ft_verify_invalid_map_chars(t_game *g) 
// {
// 	int	x;
// 	int	y;

// 	x = 0;	
// 	while (g->map[x])
// 	{
// 		y = 0;
// 		while (g->map[x][y] && g->map[x][y] != '\n')
// 		{
// 			if (ft_is_valid_char(g->map[x][y]))
// 				return (ft_free_2d(g->map) ,free(g), \
// 						ft_printf("Invalid character in map") , -1);
// 			if (g->map[0][y] != '1' || g->map[g->heigth - 1][y] != '1')
// 				return (ft_free_2d(g->map), free(g), \
// 						ft_printf("No proper border") , -1);
// 			y ++;
// 		}
// 			if (g->map[x][0] != '1' || g->map[x][g->with - 1] != '1')
// 				return (ft_free_2d(g->map), free(g), \
// 					ft_printf("No proper border") , -1);
// 		x ++;
// 	}
// 	return (0);
// }

// int	ft_count_objects_line(char *str, char c_object)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c_object)
// 			count ++;
// 		i++;
// 	}
// 	return (count);
// }	

// int	ft_verify_obj_count(t_game *g)
// {
// 	if (g->coins_count < 1)
// 		return (ft_free_2d(g->map), free(g), ft_printf("Not enoug coins"), -1);
// 	if (g->exit_count != 1)
// 		return (ft_free_2d(g->map), free(g), ft_printf("Invalid exit num"), -1);
// 	if (g->player_count != 1)
// 		return (ft_free_2d(g->map), free(g), ft_printf("Invalid player num"), -1);
// 	else
// 		return (0);
// }

// void	ft_count_objects_map(t_game *g)
// {
// 	int	x;

// 	x = 0;
// 	g->player_count = 0;
// 	g->coins_count = 0;
// 	g->exit_count = 0;
// 	while(g->map[x])
// 	{
// 		g->player_count += ft_count_objects_line(g->map[x], 'P');
// 		g->coins_count += ft_count_objects_line(g->map[x], 'C');
// 		g->exit_count += ft_count_objects_line(g->map[x], 'E');
// 		x ++;
// 	}
// 	if (ft_verify_obj_count(g) == -1)
// 		exit(-1);
// }



// char	**ft_get_map_char(t_game *g)
// {
// 	int		i;
// 	char	**map;

// 	g->map_fd = open(g->map_url, O_RDONLY);
// 	if (g->map_fd == -1)
// 		return (free(g), NULL);
// 	map = (char **)malloc(sizeof(char *) * g->heigth + 1);
// 	if (!map)
// 		return (free(g), NULL);
// 	i = 0;
// 	while (i <= g->heigth)
// 	{
// 		map[i] = get_next_line(g->map_fd);
// 		i++;
// 	}
// 	close(g->map_fd);
// 	return (map);
// }

// void	ft_get_p_position(t_game *g)
// {
// 	int	x;
// 	int	y;

// 	x = 0;	
// 	while (g->map[x])
// 	{
// 		y = 0;
// 		while (g->map[x][y])
// 		{
// 			if (g->map[x][y] == 'P')
// 			{
// 				g->p_pos[0] = x;
// 				g->p_pos[1] = y;
// 			}
// 			y ++;
// 		}
// 		x ++;
// 	}
// }

// void	ft_map_copy(t_game *g)
// {
// 	g->map_cpy = ft_get_map_char(g);
// }

// void	ft_flood_fill(t_game *g, int x, int y)
// {
// 	if (x >= g->heigth || y >= g->with || x <= 0 || y <= 0 || g->map_cpy[x][y] == 'x')
// 		return ;
// 	if (g->map_cpy[x][y] == '0' || g->map_cpy[x][y] == 'P' || g->map_cpy[x][y] == 'E' || g->map_cpy[x][y] == 'C')
// 		g->map_cpy[x][y] = 'x';
// 	if (g->map_cpy[x][y] == '1')
// 		return ;
// 	ft_flood_fill(g, x, y - 1);
// 	ft_flood_fill(g, x, y + 1);
// 	ft_flood_fill(g, x - 1, y);
// 	ft_flood_fill(g, x + 1, y);
// }

// int	ft_check_after_flod(t_game *g)
// {
// 	int	x;

// 	x = 0;
// 	while (g->map_cpy[x])
// 	{
// 		if (ft_count_objects_line(g->map_cpy[x], 'C') || \
// 		ft_count_objects_line(g->map_cpy[x], 'P') || \
// 		ft_count_objects_line(g->map_cpy[x], 'E'))
// 		{
// 			ft_free_2d(g->map_cpy);
// 			ft_free_2d(g->map);
// 			free(g);
// 			ft_printf("No valida map");
// 			exit(-1);
// 		}
// 		x++;
// 	}
// 	ft_free_2d(g->map_cpy);
// 	return (0);
// }

// int	ft_get_sprites(t_game *g)
// {
// 	int	x;
// 	int	y;

// 	g->water = mlx_xpm_file_to_image(g->mlx, WATER, &x, &y);
// 	g->border = mlx_xpm_file_to_image(g->mlx, BORDER, &x, &y);
// 	g->chest = mlx_xpm_file_to_image(g->mlx, CHEST, &x, &y);
// 	g->port = mlx_xpm_file_to_image(g->mlx, PORT, &x, &y);
// 	g->ship = mlx_xpm_file_to_image(g->mlx, SHIP, &x, &y);
// 	if (!g->water || !g->border || !g->chest || !g->port
// 		|| !g->ship)
// 	{
// 		ft_printf("Error\nFalta alguna textura\n");
// 		return (ft_free_2d(g->map), free(g) , exit(-1), -1);
// 	}
// 	return (0);
// }

// void	ft_put_sprite(t_game *g,char c, int y, int x)
// {
// 	mlx_put_image_to_window(g->mlx, g->window, g->water, PIX * x, PIX * y);
// 	if (c == '0')
// 		mlx_put_image_to_window(g->mlx, g->window, g->water, PIX * x, PIX * y);
// 	else if (c == '1')
// 		mlx_put_image_to_window(g->mlx, g->window, g->border, PIX * x, PIX * y);
// 	else if (c == 'C')
// 		mlx_put_image_to_window(g->mlx, g->window, g->chest, PIX * x, PIX * y);
// 	else if (c == 'E')
// 		mlx_put_image_to_window(g->mlx, g->window, g->port, PIX * x, PIX * y);
// }

// void	ft_put_player(t_game *g, int y, int x)
// {
// 	mlx_put_image_to_window(g->mlx, g->window, g->ship, PIX * x, PIX * y);
// }

// void	ft_drau_map(t_game *g)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	x = 0;
// 	while (y < g->with)
// 	{
// 		x = 0;
// 		while (x < g->heigth)
// 		{
// 			ft_put_sprite(g, g->map[x][y] ,x, y);
// 			ft_put_player(g, g->p_pos[0], g->p_pos[1]);
// 			x ++;
// 		}
// 		y ++;
// 	}
// }

// void	ft_free_textures(t_game *g)
// {
// 	if (g->ship)
// 		mlx_destroy_image(g->mlx, g->ship);
// 	if (g->water)
// 		mlx_destroy_image(g->mlx, g->water);
// 	if (g->chest)
// 		mlx_destroy_image(g->mlx, g->chest);
// 	if (g->port)
// 		mlx_destroy_image(g->mlx, g->port);
// 	if (g->border)
// 		mlx_destroy_image(g->mlx, g->border);
// }

// int	ft_on_close(t_game *g)
// {
// 	if (g->mlx && g->window)
// 		mlx_destroy_window(g->mlx, g->window);
// 	free(g->mlx);
// 	ft_free_textures(g);
// 	ft_free_2d(g->map);
// 	free(g);
// 	exit(0);
// 	return (0);
// }

// void	ft_move_palyer(t_game *g, int x, int y)
// {	if (g->map[g->p_pos[0] + x][g->p_pos[1] + y] != '1')
// 	{
// 		if (x)
// 			g->p_pos[0] += x;
// 		else
// 			g->p_pos[1] += y;
// 		ft_printf("Moves: %i\n", g->moves++);
// 	}
// 	else
// 		return ;
// }

// int	ft_key_hook(int key_code, t_game *g)
// {
// 	if (key_code == ESC)
// 		ft_on_close(g);
// 	if (key_code == W || key_code == UP)
// 		ft_move_palyer(g, -1, 0);
// 	if ((key_code == A || key_code == LEFT))
// 		ft_move_palyer(g, 0, -1);
// 	if ((key_code == S || key_code == DOWN))
// 		ft_move_palyer(g, 1, 0);
// 	if ((key_code == D || key_code == RIGHT))
// 		ft_move_palyer(g, 0, 1);
// 	if (g->map[g->p_pos[0]][g->p_pos[1]] == 'C')
// 	{
// 		g->coins_count--;
// 		g->map[g->p_pos[0]][g->p_pos[1]] = '0';
// 	}
// 	if (g->coins_count == 0 && g->map[g->p_pos[0]][g->p_pos[1]] == 'E')
// 		ft_on_close(g);
// 	ft_drau_map(g);
// 	return (0);
// }

void	ft_game_starter(t_game *g)
{
	g->mlx = mlx_init();
	g->moves = 0;
	g->window = mlx_new_window(g->mlx, g->with * PIX, g->heigth * PIX, "SO_LONG");
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

	if (ft_get_map_h_w(g) == -1)
		return (ft_printf("Problema con get map\n"));
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
