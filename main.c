/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:54:34 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/22 17:27:03 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_manage_input(int argc, char **argv, int *fd_map)
{
	char	try_to_read[2];

	if (argc != 2)
		return (ft_printf("Wrong cuantity of args\n"), -1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		return (ft_printf("Map is not .ber\n"), -1);
	*fd_map = open(argv[1], O_RDONLY);
	if (fd_map < 0 || read(*fd_map, try_to_read, 0) < 0)
		return (ft_printf("Problem opening the fd"), close(*fd_map), -1);
	return (0);
}

// Me ocupo dentro de la funcion de 
// liverar si aloqeo nueva memoriia y 
// devuelvo un int segun si l programa ha tendo exito o no 
int	ft_get_map(t_game game, int fd) 
{
	char **temp;
	
	
	while ()
	{
		/* code */
	}
	
}

int	main(int argc, char **argv)
{
	int		fd_map;
	t_game	*game;

	if (ft_manage_input(argc, argv, &fd_map) == -1)
		return (-1);
	game = malloc(sizeof(t_game)); // Aparti de ahora hay que hacer free de la estructura
	ft_printf("MAPA: \n");
	
}

// Aparti de ahora hay que hacer free de la estructura GAME si se sale del programa
//el Progrma siempre abre el fd al principio 