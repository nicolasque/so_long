/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:54:34 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/24 19:18:31 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_manage_input(int argc, char **argv, t_game *game)
{
	char	try_to_read[2];

	if (argc != 2)
		return (ft_printf("Wrong cuantity of args\n"), -1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		return (ft_printf("Map is not .ber\n"), -1);
	game->map_fd = open(argv[1], O_RDONLY); //Este se cerrara en ft_get_map_h_w
	if (game->map_fd < 0 || read(game->map_fd, try_to_read, 0) < 0)
		return (ft_printf("Problem opening the fd"), close(game->map_fd), -1);
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

int	ft_verify_map_chars(t_game game)
{
	int i;

	
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
	else if (game->exit_count != 1)
		return (ft_free_2d(game->map), free(game), ft_printf("Invalid exit num"), -1);
	else if (game->player_count != 1)
		return (ft_free_2d(game->map), free(game), ft_printf("Invalid player num"), -1);
	else
		return (0);
	
}

void	ft_count_objects_map(t_game *game)
{
	int	x;

	x = 0;
	while(game->map[x])
	{
		game->coins_count += ft_count_objects_line(game->map[x], 'C');
		game->player_count += ft_count_objects_line(game->map[x], 'P');
		game->exit_count += ft_count_objects_line(game->map[x], 'E');
		x ++;
	}
	if (ft_verify_obj_count(game) == -1)
		exit(-1);
}


void	ft_print_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[i])
	{
		ft_printf("%s",game->map[i]);
		i++;
	}
	
}


int	ft_get_map_char(t_game *game) 
{
	int		i;

	game->map_fd = open(game->map_url, O_RDONLY);
	if (game->map_fd == -1)
		return (free(game), -1);
	game->map = (char **)malloc(sizeof(char *) * game->map_heigth + 1);
	if (!game->map)
		return (free(game), -1);// APARTIR DE AQUI AY QUE LIVERAR GAME->MAP*
	i = 0;
	while (i <= game->map_heigth)
	{
		game->map[i] = get_next_line(game->map_fd);
		i++;
	}
	ft_count_objects_map(game);
	return (0);
}



int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game)); // SIEMPRE liverar (preferiblemente en el nterior de las funciones)
	if (ft_manage_input(argc, argv, game) == -1)
		return (-1);
	if (ft_get_map_h_w(game) == -1)
		return (ft_printf("Problema con get map (de momento solo h/w)\n"));
	if (ft_get_map_char(game) == -1)
		return (ft_printf("Geting the map has fail"), -1);


	printf("Coins: %i \n", game->coins_count);
	printf("Player: %i \n", game->player_count);
	printf("Exit no : %i \n", game->exit_count);
	
	printf("Anco del mapa: %i\n", game->map_with);
	printf("Alto del mapa: %i\n", game->map_heigth);
	printf("Estado del fd: %i\n", game->map_fd);
	printf("Direcion del fd: %s\n", game->map_url);
	
}

// Aparti de ahora hay que hacer free de la estructura GAME si se sale del programa
//el Progrma siempre abre el fd al principio


//BATERIA DE COMPROBACIONES 