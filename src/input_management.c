/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:18 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 16:50:34 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_manage_input(int argc, char **argv, t_game *g)
{
	char	try_to_read[2];

	if (argc != 2)
		return (ft_printf("Wrong cuantity of args\n"), free(g), exit(-1),-1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL \
		|| ft_strlen(argv[1]) <= 4)
	{
		ft_printf("Map is not .ber\n");
		return (free(g),exit(-1) , -1);
	}
	g->map_fd = open(argv[1], O_RDONLY);
	if (g->map_fd < 0 || read(g->map_fd, try_to_read, 0) < 0)
	{
		ft_printf("Problem opening the fd");
		return (close(g->map_fd), free(g), exit(-1) , -1);
	}
	g->map_url = argv[1];
	return (0);
}
