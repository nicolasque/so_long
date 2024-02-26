/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:54:34 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/26 18:52:45 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_manage_input(int argc, char **argv, t_game *game)
{
	char	try_to_read[2];

	if (argc != 2)
		return (ft_printf("Wrong cuantity of args\n"),free(game) , -1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL || ft_strlen(argv[1]) <= 4)
		return (ft_printf("Map is not .ber\n"),free(game) , -1);
	game->map_fd = open(argv[1], O_RDONLY); //Este se cerrara en ft_get_map_h_w
	if (game->map_fd < 0 || read(game->map_fd, try_to_read, 0) < 0)
		return (ft_printf("Problem opening the fd"), close(game->map_fd),
		free(game) , -1);
	game->map_url = argv[1];
	return (0);
}
int ft_free_2d(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	return (free(arr), 0);
}

int	ft_map_whith(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\r' && line[i] != '\0')
		i ++;
	return (i);
}

// Me ocupo dentro de la funcion de 
// liverar si aloqeo nueva memoriia y 
// devuelvo un int segun si l programa ha tendo exito o no 
int	ft_get_map_h_w(t_game *game)
{
	char	*line;

	line = get_next_line(game->map_fd); //MEMEORIA PARA LIBERAR (menos en la comprobacion de abajo)
	if (!line)
		return (ft_printf("Invalid map"), free(game), -1);
	game->map_with = ft_map_whith(line);
	game->map_heigth = 0;
	while (line)
	{
		if (game->map_with != ft_map_whith(line)) // si una linea es de tro tamaño paramos el programa
			return (ft_printf("Invalid map"), free(line), free(game), -1); // LIVERO aqui GAME
		game->map_heigth ++;
		line = get_next_line(game->map_fd);
		if (!line)
			return (0);
	}
	close (game->map_fd); //Despues de "medir" el arrchivo lo cerramos para abrirlo de uevo a la ora de leer
	free(line);
	return (0);
}

int ft_is_valid_char(int c) // 0 si todo bien -1  si caracter no valido 
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1' || c == '\n')
		return (0);
	return (-1);
}

int	ft_verify_invalid_map_chars(t_game *game) 
{
	int x;
	int	y;

	x = 0;	
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y] && game->map[x][y] != '\n')
		{
			if (ft_is_valid_char(game->map[x][y]))
				return (ft_free_2d(game->map), free(game),ft_printf("Invalid character in map") , -1);
			if (game->map[0][y] != '1' || game->map[game->map_heigth - 1][y] != '1')
				return (ft_free_2d(game->map), free(game),ft_printf("No proper border") , -1);
			y ++;
		}
			if (game->map[x][0] != '1' || game->map[x][game->map_with - 1] != '1')
				return (ft_free_2d(game->map), free(game),ft_printf("No proper border") , -1);
		x ++;
	}
	return (0);
}

int ft_count_objects_line(char *str, char c_object)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c_object)
			count ++;
		i++;
	}
	return (count);
}	

int ft_verify_obj_count(t_game *game)
{
	if (game->coins_count < 1)
		return (ft_free_2d(game->map), free(game), ft_printf("Not enoug coins"), -1);
	if (game->exit_count != 1)
		return (ft_free_2d(game->map), free(game), ft_printf("Invalid exit num"), -1);
	if (game->player_count != 1)
		return (ft_free_2d(game->map), free(game), ft_printf("Invalid player num"), -1);
	else
		return (0);
	
}

void	ft_count_objects_map(t_game *game)
{
	int	x;

	x = 0;
	game->player_count = 0;
	game->coins_count = 0;
	game->exit_count = 0;
	while(game->map[x])
	{
		game->player_count += ft_count_objects_line(game->map[x], 'P');
		game->coins_count += ft_count_objects_line(game->map[x], 'C');
		game->exit_count += ft_count_objects_line(game->map[x], 'E');
		x ++;
	}
	if (ft_verify_obj_count(game) == -1)
		exit(-1);
}


void	ft_print_map(char **map)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	
}


char	**ft_get_map_char(t_game *game)
{
	int		i;
	char	**map;

	game->map_fd = open(game->map_url, O_RDONLY);
	if (game->map_fd == -1)
		return (free(game), NULL);
	map = (char **)malloc(sizeof(char *) * game->map_heigth + 1);
	if (!map)
		return (free(game), NULL);// APARTIR DE AQUI AY QUE LIVERAR GAME->MAP*
	i = 0;
	while (i <= game->map_heigth)
	{
		map[i] = get_next_line(game->map_fd);
		i++;
	}
	close(game->map_fd);
	return (map);
}

void	ft_get_player_position(t_game *game)
{
	int x;
	int	y;

	x = 0;	
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->player_pos[0] = x;
				game->player_pos[1] = y;
			}
			y ++;
		}
		x ++;
	}
}

void	ft_map_copy(t_game *game)
{
	game->map_cpy = ft_get_map_char(game);
}

void	ft_flood_fill(t_game *game, int x, int y)
{
	if (x >= game->map_heigth || y >= game->map_with || x <= 0 || y <= 0 || game->map_cpy[x][y] == 'x')
		return ;
	if (game->map_cpy[x][y] == '0' || game->map_cpy[x][y] == 'P' || game->map_cpy[x][y] == 'E' || game->map_cpy[x][y] == 'C')
		game->map_cpy[x][y] = 'x';
	if (game->map_cpy[x][y] == '1')
		return ;
	ft_flood_fill(game, x, y - 1);
	ft_flood_fill(game, x, y + 1);
	ft_flood_fill(game, x - 1, y);
	ft_flood_fill(game, x + 1, y);
}

int	ft_check_after_flod(t_game *game)
{
	int	x;

	x = 0;
	while (game->map_cpy[x])
	{
		if (ft_count_objects_line(game->map_cpy[x], 'C') || \
		ft_count_objects_line(game->map_cpy[x], 'P') || \
		ft_count_objects_line(game->map_cpy[x], 'E'))
		{
			ft_free_2d(game->map_cpy);
			ft_free_2d(game->map);
			free(game);
			ft_printf("No valida map");
			exit(-1);
		}
		x++;
	}
	ft_free_2d(game->map_cpy);
	return (0);
}

void	ft_get_sprites(t_game *game)
{
	int	x;
	int	y;

	game->water = mlx_xpm_file_to_image(game->mlx, "textures/water(0).xpm", &x, &y);
	game->border = mlx_xpm_file_to_image(game->mlx, "textures/border(1).xpm", &x, &y);
	game->chest = mlx_xpm_file_to_image(game->mlx, "textures/chest(C).xpm", &x, &y);
	game->port = mlx_xpm_file_to_image(game->mlx, "textures/port(E).xpm", &x, &y);
	game->ship = mlx_xpm_file_to_image(game->mlx, "textures/ship(P).xpm", &x, &y);
	
}

void	ft_put_sprite(t_game *game,char c, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->window, game->water, PIXEL * x, PIXEL * y);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->water, PIXEL * x, PIXEL * y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->border, PIXEL * x, PIXEL * y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->chest, PIXEL * x, PIXEL * y);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->port, PIXEL * x, PIXEL * y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->ship, PIXEL * x, PIXEL * y);

}

void	ft_drax_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->map_with)
	{
		x = 0;
		while (x < game->map_heigth)
		{
			ft_put_sprite(game, game->map[x][y] ,x, y);
			x ++;
		}
		y ++;
	}
}


void	ft_game_starter(t_game *game)
{
	game->mlx = mlx_init();
	game->moves = 0;
	game->window = mlx_new_window(game->mlx, game->map_with * PIXEL, game->map_heigth * PIXEL, "SO_LONG");
	ft_get_sprites(game);
	ft_drax_map(game);
	mlx_loop (game->mlx);

}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game)); // SIEMPRE liverar (preferiblemente en el nterior de las funciones)
	if (ft_manage_input(argc, argv, game) == -1)
		return (-1);
	if (ft_get_map_h_w(game) == -1)
		return (ft_printf("Problema con get map (de momento solo h/w)\n"));
	game->map = ft_get_map_char(game);
	if (!game->map)
		return (ft_printf("Problem geting the map"), -1);
	ft_count_objects_map(game);
	if (ft_verify_invalid_map_chars(game) == -1)
		return (-1);
	ft_get_player_position(game);
	ft_map_copy(game);
	// ft_print_map(game->map_cpy);
	ft_flood_fill(game, game->player_pos[0], game->player_pos[1]);
	ft_check_after_flod(game); //No hace falta liberar map cpy despuesd e de esto
	//ft_print_map(game->map_cpy); //NO FUNCIONA POR QUE EL CPY YA ESTA LIVERADO
	ft_game_starter(game);


	printf("Player: %i \n", game->player_count);
	printf("Coins: %i \n", game->coins_count);
	printf("Exit no : %i \n", game->exit_count);
	printf("Player position x: %i\n", game->player_pos[0]);
	printf("Player position y: %i\n", game->player_pos[1]);
	printf("Alto del mapa: %i\n", game->map_heigth);
	printf("Anco del mapa: %i\n", game->map_with);
	printf("Estado del fd: %i\n", game->map_fd);
	printf("Direcion del fd: %s\n", game->map_url);
	printf("whater sprite: %s", game->water);
}

// Aparti de ahora hay que hacer free de la estructura GAME si se sale del programa
//el Progrma siempre abre el fd al principio
