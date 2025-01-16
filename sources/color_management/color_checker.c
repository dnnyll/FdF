/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:17:01 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/16 11:17:42 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_line_for_colors(t_map *map, char *line, int row)
{
	int		col;
	char	**parts;
	char	**split_parts;

	col = 0;
	parts = ft_split(line, ' ');
	map->color_stash = allocate_color_data_char(map);
	while (parts[col])
	{
		if (ft_strchr(parts[col], ','))
		{
			split_parts = ft_split(parts[col], ',');
			if (split_parts[1] && ft_strncmp(split_parts[1], "0x", 2) == 0 && ft_strlen(split_parts[1]) == 8)
			{
				ft_printf("split_parts[1] at row[%d], col:[%d]: %s\n", (row + 1), (col + 1), split_parts[1]);
				map->color_stash[row] = ft_strdup(split_parts[1]);
				if (!map->color_stash[row])
					ft_printf("Error: Memory allocation failed for color_stash.\n");
			}
			else
			{
				ft_printf("Warning: Invalid or missing color value.\n");
			}
			free_split_parts(split_parts); 
		}
		col++;
	}
	free(parts);
}

void	color_occurence(t_map *map, const char *filename)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		free(map);
		exit(EXIT_FAILURE);
	}
	row = 0;
	while ((line = get_next_line(fd)))
	{
		process_line_for_colors(map, line, row);
		free(line);
		row++;
	}

	close(fd);
}

char	**allocate_color_data_char(t_map *map)
{
	int	index;

	map->color_stash = malloc(sizeof(char *) * map->height);
	if (!map->color_stash)
	{
		free(map->color_stash);
		ft_printf("failed allocating memory for map->data_char[rows]");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < map->height)
	{
		map->color_stash[index] = malloc(sizeof(char) * 10 + 1);
		if (!map->color_stash[index])
		{
			free(map->color_stash);
			ft_printf("failed allocating memory for map->data_char[index] (row content)");
			exit(EXIT_FAILURE);
		}
		index++;
	}
	ft_printf("allocate_map_data_char successful\n");
	return (map->color_stash);
}
