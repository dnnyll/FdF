/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:26:59 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/17 15:40:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Opens and reads the map input
//	Calculates the height and width of the map
//	Verifies if the input is valid?!?!?!
#include "fdf.h"
void	read_map(t_map *map, t_coordinates * coordinates, char *filename)
{
	char	*line;
	int		width_checker;
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening and reading file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	width_checker = 0;
	while(line)
	{
		if(!line)
		{
			ft_printf("Error: no line.\n");
			exit(EXIT_FAILURE);
		}
		map->width = count_elements(ft_split(line, ' '));
		map->height++;
		ft_printf("line: %s\n", line);
		line = get_next_line(fd);
		ft_printf("height: %d\n", map->height);
		ft_printf("width: %d\n", map->width);
		if (width_checker == 0)
			width_checker = map->width;
		else
		{
			if (map->width != width_checker)
			{
				ft_printf("Error: row width isn't constant.\n");
				free_map_data(map);
				exit(EXIT_FAILURE);
			}
		}
	}
	ft_printf("parsing successful.\n");
}

nt	count_elements(char **array)
{
	int	count;

	count = 0;
	while(array && array[count])
		count++;
	ft_printf("count_elements with newline at end: %d\n", count);
	//count is giving  an extra value, unknown yet, maybe \n
	return (count -1);
}
