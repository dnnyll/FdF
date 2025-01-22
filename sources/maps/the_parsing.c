/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:08:55 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/22 17:29:43 by daniefe2         ###   ########.fr       */
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
	close(fd);
}

void	store_map_lines(t_map *map, int fd)
{
	ft_printf("Initiating: read_store_map_lines\n");
	int		tracker;

	tracker = 0;
	ft_printf("width: %d\n", map->width);
	ft_printf("height: %d\n", map->height);
	while (tracker < map->height)
	{
		map->line = get_next_line(fd);
		if (!map->line)
		{
			ft_printf("Error: no line\n");
			exit(EXIT_FAILURE);
		}
		map->char_matrix_stash[tracker] = ft_strdup(map->line);
		ft_printf("char_matrix_stash[line: %d]: %s\n", tracker, map->char_matrix_stash[tracker]);
		ft_printf("line %d: %s\n", tracker, map->line);
		free(map->line);
		tracker++;
	}
}

void	process_lines(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0; // Reset column index for every row
		map->parts_values[row] = ft_split(map->char_matrix_stash[row], ' ');
		//debug
	ft_printf("split result: ");
	for (int i = 0; map->parts_values[row][i] != NULL; i++)
	ft_printf("'%s' ", map->parts_values[row][i]);
	ft_printf("\n");
		if (!map->parts_values[row])
		{
			ft_printf("Error: no row content\n");
			exit(EXIT_FAILURE);
		}
		while (map->parts_values[row][col])
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

	value_element = map->parts_values[row][col];
	comma_pos = ft_strchr(value_element, ',');
	if (comma_pos)
	{
		*comma_pos = '\0';	
		map->parts_colours[row][col] = ft_strdup(comma_pos + 1); // Save the color part
	}
	else
		map->parts_colours[row][col] = NULL; // No color
	map->parts_values[row][col] = ft_strdup(value_element); // Store the value part
}

void	char_matrix_alloc(t_map *map)
{
	int	i;

	ft_printf("Allocating memory - Width: %d, Height: %d\n", map->width, map->height);

	map->char_matrix_stash = malloc(sizeof(char *) * map->height);
	map->parts_values = malloc(sizeof(char **) * map->height);
	map->parts_colours = malloc(sizeof(char **) * map->height);

	if (!map->char_matrix_stash || !map->parts_values || !map->parts_colours)
	{
		ft_printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	i = 0;
	while (i < map->height)
	{
		map->char_matrix_stash[i] = NULL;
		map->parts_values[i] = malloc(sizeof(char *) * map->width);
		map->parts_colours[i] = malloc(sizeof(char *) * map->width);

		if (!map->parts_values[i] || !map->parts_colours[i])
		{
			ft_printf("Error: memory allocation failed at row %d\n", i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_printf("Memory allocation completed successfully\n");
}




// #include "fdf.h"

// void	read_store_map_lines(t_map *map, char *filename)
// {
// 	ft_printf("Initiating: read_store_map_lines\n");
// 	int		fd;
// 	int		tracker;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_printf("Error opening and reading file\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	char_matrix_alloc(map);
// 	tracker = 0;
// 	ft_printf("width: %d\n", map->width);
// 	ft_printf("height: %d\n", map->height);
// 	while (tracker < map->height)
// 	{
// 		map->line = get_next_line(fd);
// 		map->char_matrix_stash[tracker] = ft_strdup(map->line);
// 		ft_printf("char_matrix_stash[line: %d]: %s\n", tracker, map->char_matrix_stash[tracker]);
// 		ft_printf("line %d: %s\n", tracker, map->line);
// 		free(map->line);
// 		tracker++;
// 	}
// 	close(fd);
// 	print_char_stash_matrix(map);
// //	parse_map_row(map);
// }
// void parse_map_row(t_map *map)
// {
// 	ft_printf("START parse_map_row\n");
// 	char 	**parts1;
// 	int		index;
// 	int		jndex;
	
// 	jndex = 0;
// 	parts1 = ft_split(map->char_matrix_stash[jndex], ' ');
// 	jndex++;
// 	index = 0;
// 	while(parts1[index])
// 	{
// 		map->z_row[index] = ft_atoi(parts1[index]);
// 		// map->z_str[index] = parts[index];
// 		// map->colour_str = NULL;
// 		map->comma_pos[index] = ft_strchr(parts1[index], ',');
// 		if (map->comma_pos)
// 		{
// 			*map->comma_pos = '\0';
// 			map->colour_str[index] = map->comma_pos[index] + 1;	// The color starts right after the comma.
// 			map->colour_row[index] = hex_to_int(map->colour_str[index]);
// 		}
// 		else
// 			map->colour_row[index] = 0xFF8DA1;
// 		map->z_matrix[map->y][index] = map->z_row[index];  // Store z-value in z_matrix
// 		map->colour_matrix[map->y][index] = map->colour_row[index];  // Store color in colour_matrix
// 		index++;
// 	}
// 	free (parts1);
// }

// int	hex_to_int(char *hex_str)
// {
// 	ft_printf("START last\n");
// 	int	index;
// 	int	result;

// 	index = 2; // skips 0x
// 	result = 0;
// 	while (hex_str[index] != '\0')
// 	{
// 		result *= 16;
// 		if (ft_isdigit(hex_str[index]))
// 			result += hex_str[index] - 0;
// 		else if (ft_isalpha(hex_str[index]))
// 		{
// 			if (hex_str[index] >='a' && hex_str[index] <= 'f')
// 				result += hex_str[index] - 'a' + 10;
// 			if (hex_str[index] >='A' && hex_str[index] <= 'F')
// 				result += hex_str[index] - 'A' + 10;
// 		}
// 		else
// 		{
// 			ft_printf("Error: invalid hexadecimal character: %c\n.", hex_str[index]);
// 			return (-1);
// 		}
// 		index++;
// 	}
// 	return (result);
// }


// void	matrix_alloc_height(t_map *map)
// {
// 	ft_printf("Initiating memory allocation for z and colour matrices\n");
// 	map->z_matrix = (int **)malloc(sizeof(int *) * map->height);
// 	if(!map->z_matrix)
// 	{
// 		ft_printf("Error allocating height memory for z_matrix");
// 		exit(EXIT_FAILURE);
// 	}
// 	map->colour_matrix = (int **)malloc(sizeof(int *)* map->height);
// 	if(!map->colour_matrix)
// 	{
// 		ft_printf("Error allocating height memory for colour_matrix");
// 		exit(EXIT_FAILURE);
// 	}
// 	matrix_alloc_width(map);
// }

// void	matrix_alloc_width(t_map *map)
// {
// 	int tracker;
	
// 	tracker = 0;
// 	ft_printf("alloc height: %d\n",map->height);
// 	while (tracker < map->height)
// 	{
// 		map->z_matrix[tracker] = (int *)malloc(sizeof(int) * map->width);
// 		if(!map->z_matrix[tracker])
// 		{
// 			ft_printf("Error allocating width memory for z_matrix");
// 			exit(EXIT_FAILURE);
// 		}
// 		map->colour_matrix[tracker] = (int *)malloc(sizeof(int) * map->width);
// 		if(!map->colour_matrix[tracker])
// 		{
// 			ft_printf("Error allocating width memory for colour_matrix");
// 			exit(EXIT_FAILURE);
// 		}
// 		tracker++;
// 	}
// }

// void	char_matrix_alloc(t_map *map)
// {
// 	int tracker;
	
// 	tracker = 0;
// 	ft_printf("Initiating memory allocation for char_matrix_stash\n");
// 	map->char_matrix_stash = (char **)malloc(sizeof(char *) * map->height);
// 	if(!map->char_matrix_stash)
// 	{
// 		ft_printf("Error allocating height memory for z_matrix");
// 		exit(EXIT_FAILURE);
// 	}
// 	ft_printf("alloc height: %d\n",map->height);
// 	while (tracker < map->height)
// 	{
// 		map->char_matrix_stash[tracker] = (char *)malloc(sizeof(char) * (map->width + 1));
// 		if(!map->char_matrix_stash[tracker])
// 		{
// 			while (--tracker >= 0)
// 				free(map->char_matrix_stash[tracker]);
// 			ft_printf("Error allocating width memory for char_matrix_stash");
// 			exit(EXIT_FAILURE);
// 		}
// 		tracker++;
// 	}
// }

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
   - Each row is an array of integers (for `z-values` or `color values`), where the number of elements equals the width of the matrix.

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