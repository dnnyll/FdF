/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:08:55 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 11:57:13 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	free_char_matrix_stash(map);
	close(fd);
}

void	store_map_lines(t_map *map, int fd)
{
	ft_printf("Initiating: read_store_map_lines\n");
	int		index;

	index = 0;
	ft_printf("x: %d\n", map->x);
	ft_printf("y: %d\n", map->y);
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
		ft_printf("char_matrix_stash[line: %d]: %s\n", index, map->char_matrix_stash[index]);
		ft_printf("line %d: %s\n", index, map->line);
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
	ft_printf("split result: ");
	for (int i = 0; map->c_z_matrix[row][i] != NULL; i++)
	ft_printf("'%s' ", map->c_z_matrix[row][i]);
	ft_printf("\n");
		if (!map->c_z_matrix[row])
		{
			ft_printf("Error: no row content\n");
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

//exp
/*
Memory Allocation for a 2D Matrix:

1. Allocate memory for the array of row pointers:
   - This step creates an array where each element points to a row of the matrix.
   - Think of it as creating an array of pointers, each of which will later point to the start of a row.

   Example:
   +-----------+
   | Row Ptr 0 | --> [Pointer to first row]
   +-----------+
   | Row Ptr 1 | --> [Pointer to second row]
   +-----------+
   | Row Ptr 2 | --> [Pointer to third row]
   +-----------+

2. Allocate memory for each row:
   - For each row pointer, allocate memory to hold the elements of that row.
   - Each row is an array of integers (for `z-values` or `color values`), where the number of elements equals the x of the matrix.

   Example:
   Row Ptr 0 --> +-----+-----+-----+-----+
                 |  z0 |  z1 |  z2 |  z3 |  (Width = 4)
                 +-----+-----+-----+-----+

   Row Ptr 1 --> +-----+-----+-----+-----+
                 |  z4 |  z5 |  z6 |  z7 |  (Width = 4)
                 +-----+-----+-----+-----+

   Row Ptr 2 --> +-----+-----+-----+-----+
                 |  z8 |  z9 | z10 | z11 |  (Width = 4)
                 +-----+-----+-----+-----+

3. Fill the matrix:
   - Populate each allocated element with the appropriate values, either `z-values` or `color values`.
   - Each element in the row is set by parsing the corresponding value from the input data.

This process ensures that the matrix is fully dynamic, with each row having its own allocated space, and the entire structure capable of being resized or modified as needed.
*/