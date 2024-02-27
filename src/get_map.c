/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:11:51 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/27 17:17:20 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_map_whith(char *line)
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
int	ft_get_map_h_w(t_game *g)
{
	char	*line;

	line = get_next_line(g->map_fd);
	if (!line)
		return (ft_printf("Invalid map"), free(g), -1);
	g->with = ft_map_whith(line);
	g->heigth = 0;
	while (line)
	{
		if (g->with != ft_map_whith(line))
			return (ft_printf("Invalid map"), free(line), free(g), -1);
		g->heigth ++;
		line = get_next_line(g->map_fd);
		if (!line)
			return (0);
	}
	close (g->map_fd);
	free(line);
	return (0);
}

char	**ft_get_map_char(t_game *g)
{
	int		i;
	char	**map;

	g->map_fd = open(g->map_url, O_RDONLY);
	if (g->map_fd == -1)
		return (free(g), NULL);
	map = (char **)malloc(sizeof(char *) * (g->heigth + 1));
	if (!map)
		return (free(g), NULL);
	i = 0;
	while (i <= g->heigth)
	{
		map[i] = get_next_line(g->map_fd);
		i++;
	}
	close(g->map_fd);
	return (map);
}
