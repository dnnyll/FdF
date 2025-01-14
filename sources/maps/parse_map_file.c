/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:57:52 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/14 14:00:31 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//sets up the size of your map and gives you access to the dimensions (height and width)
#include "fdf.h"

t_map *parse_map_file(const char *filename)
{
	t_map *map = initialize_map();
	char *line;
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		free(map);
		exit(EXIT_FAILURE);
	}
//	gets the values of height and width for our argument map
	line = get_next_line(fd);
	if (line)
	{
		map->width = count_elements(ft_split(line, ' '));
		while (line)
		{
			map->height++;
			ft_printf("line: %s\n", line);
			free(line);
			line = get_next_line(fd);
		}
		ft_printf("height: %d\n", map->height);
		ft_printf("width: %d\n", map->width);
		allocate_map_data(map);
		

	}
	ft_printf("parse successful\n");
	close(fd);
	return (map);
}

int	count_elements(char **array)
{
	int	count;

	count = 0;
	while(array && array[count])
		count++;
	ft_printf("count_elements with newline at end: %d\n", count);
	//count is giving  an extra value, unknown yet, maybe \n
	return (count - 1);
}
