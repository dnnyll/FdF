/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:57:52 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/09 13:27:07 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map *parse_map_file(const char *filename)
{
	t_map *map = initialize_map();
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		free(map);
		exit(EXIT_FAILURE);
	}

	char *line = get_next_line(fd);
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
	}
	close(fd);
	return (map);
}

int	count_elements(char **array)
{
	int	count;

	count = 0;
	while(array && array[count])
		count++;
	ft_printf("count_elements: %d\n", count);
	return (count);
}
