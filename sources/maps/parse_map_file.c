/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:57:52 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/09 10:15:39 by daniefe2         ###   ########.fr       */
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
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
	return map;
}

int	count_elements(char **array)
{
	int	count;

	count = 0;
	while(array && array[count])
		count++;
	return (count);
}
