/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:26:59 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/21 16:10:52 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Opens and reads the map input
//	Calculates the height and width of the map
//	Verifies if the input is valid?!?!?!
#include "fdf.h"

void	read_map_size(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error opening and reading file\n");
		exit(EXIT_FAILURE);
	}
	map->line = get_next_line(fd);
	while (map->line)
	{
		read_map_width(map, map->line);
		map->height++;
		free(map->line);
		map->line = get_next_line(fd);
	}
	close(fd);
}

void	read_map_width(t_map *map, char *line)
{
	char	**parts;
	int		width;

	parts = ft_split(line, ' ');
	if (!parts)
	{
		ft_printf("Error splitting line\n");
		exit(EXIT_FAILURE);
	}
	width = count_line_elements(parts);
	if (map->width == 0)
		map->width = width;
	else if (map->width != width)
	{
		ft_printf("Error: inconsistent row width\n");
		free_split_result(parts);
		exit(EXIT_FAILURE);
	}
	ft_printf("width: %d\n" ,map->width);
	free_split_result(parts);
}

int	count_line_elements(char **array)
{
	int	count;

	count = 0;
	while (array && array[count])
		count++;
	ft_printf("count: %d\n", count);
	return (count - 1); //not sure if i should do this
}

void	free_split_result(char **array)
{
	int	i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
}
