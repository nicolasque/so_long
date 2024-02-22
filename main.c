/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:54:34 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/22 13:37:38 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_manage_input(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (ft_printf("Wrong uantity of args"), -1);
	if ()
	return (0);
}

int	main(int argc, char **argv)
{
	int fd = open("map.ber", O_RDONLY);
	if (ft_manage_input(argc, argv) == -1)
		return (-1);
	
	printf("pprimera linea: %s", "hola");
}