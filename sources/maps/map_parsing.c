/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:08:55 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/05 14:58:43 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_map_lines(t_map *map, int fd)
{
	// ft_printf("Initiating: read_store_map_lines\n");
	int		index;

	index = 0;
	// ft_printf("x: %d\n", map->x);
	// ft_printf("y: %d\n", map->y);
	while (index < map->y)
	{
		map->line = get_next_line(fd);
		if (!map->line)
		{
			ft_printf("Error: no line\n");
			free(map->line);
			exit(EXIT_FAILURE);
		}
		map->char_matrix_stash[index] = ft_strdup(map->line);
		// ft_printf("char_matrix_stash[line: %d]: %s\n", index, map->char_matrix_stash[index]);
		// ft_printf("line %d: %s\n", index, map->line);
		free(map->line);
		index++;
	}
}

void	process_lines(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		map->c_z_matrix[row] = ft_split(map->char_matrix_stash[row], ' ');
		if (!map->c_z_matrix[row])
		{
			ft_printf("Error: no row content\n");
			free_c_z_matrix(map);
			exit(EXIT_FAILURE);
		}
		while (map->c_z_matrix[row][col])
		{
			process_parts(map, row, col);
			col++;
		}
		row++;
	}
}

void	process_parts(t_map *map, int row, int col)
{
	char	*value_element;
	char	*comma_pos;

	value_element = map->c_z_matrix[row][col];
	comma_pos = ft_strchr(value_element, ',');
	if (comma_pos)
	{
		*comma_pos = '\0';	
		map->c_colours_matrix[row][col] = ft_strdup(comma_pos + 1); // Save the color part
	}
	else
		map->c_colours_matrix[row][col] = NULL; // No color
	map->c_z_matrix[row][col] = ft_strdup(value_element); // Store the value part
}

void	read_map_repeat(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening and reading file\n");
		exit(EXIT_FAILURE);
	}
	char_matrix_alloc(map); // Allocate memory for all arrays first
	store_map_lines(map, fd); // Read and store lines
	process_lines(map); // Process parts and extract values/colors
	// free_char_matrix_stash(map);
	// free_c_z_matrix(map);
	// free_c_colours_matrix(map);
	close(fd);
}
