/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:08:55 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/21 16:35:22 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. Open file and prepare to read
    // 2. Allocate memory for matrices based on width and height
    // 3. For each line:
    //     - Split line into elements
    //     - Parse each element for `z` and color
    //     - Store values in matrices
    // 4. Close file and finalize

#include "fdf.h"

void	read_map_repeat(t_map *map, char *filename)
{
	ft_printf("START read_map_repeat\n");
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening and reading file\n");
		exit(EXIT_FAILURE);
	}
	matrix_alloc_height(map);
	parse_map_row(map);
}

void	matrix_alloc_height(t_map *map)
{
	ft_printf("Initiating memory allocation for z and colour matrices\n");
	map->z_matrix = (int **)malloc(sizeof(int *) * map->height);
	if(!map->z_matrix)
	{
		ft_printf("Error allocating height memory for z_matrix");
		exit(EXIT_FAILURE);
	}
	map->colour_matrix = (int **)malloc(sizeof(int *)* map->height);
	if(!map->colour_matrix)
	{
		ft_printf("Error allocating height memory for colour_matrix");
		exit(EXIT_FAILURE);
	}
	matrix_alloc_width(map);
}

void	matrix_alloc_width(t_map *map)
{
	int tracker;
	
	tracker = 0;
	ft_printf("alloc height: %d\n",map->height);
	while (tracker < map->height)
	{
		map->z_matrix[tracker] = (int *)malloc(sizeof(int) * map->width);
		if(!map->z_matrix[tracker])
		{
			ft_printf("Error allocating width memory for z_matrix");
			exit(EXIT_FAILURE);
		}
		map->colour_matrix[tracker] = (int *)malloc(sizeof(int) * map->width);
		if(!map->colour_matrix[tracker])
		{
			ft_printf("Error allocating width memory for colour_matrix");
			exit(EXIT_FAILURE);
		}
		tracker++;
	}
}
void parse_map_row(t_map *map)
{
	ft_printf("START parse_map_row\n");
	char 	**parts1;
	int		index;
	
	parts1 = ft_split(map->line, ' ');
		index = 0;
	while(parts1[index])
	{
		ft_printf("IHHHHHHHHHHHHHHHHHHHHHHH\n");
		map->z_row[index] = ft_atoi(parts1[index]);
		// map->z_str[index] = parts[index];
		// map->colour_str = NULL;
		map->comma_pos[index] = ft_strchr(parts1[index], ',');
		ft_printf("OHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH\n");
		if (map->comma_pos)
		{
			ft_printf("AHHHHHHHHHHHHHHHHHHHHHHHHHH\n");
			*map->comma_pos = '\0';
			map->colour_str[index] = map->comma_pos[index] + 1;	// The color starts right after the comma.
			map->colour_row[index] = hex_to_int(map->colour_str[index]);
		}
		else
			map->colour_row[index] = 0xFF8DA1;
		map->z_matrix[map->y][index] = map->z_row[index];  // Store z-value in z_matrix
		map->colour_matrix[map->y][index] = map->colour_row[index];  // Store color in colour_matrix
		index++;
	}
	free (parts1);
}

int	hex_to_int(char *hex_str)
{
	ft_printf("START last\n");
	int	index;
	int	result;

	index = 2; // skips 0x
	result = 0;
	while (hex_str[index] != '\0')
	{
		result *= 16;
		if (ft_isdigit(hex_str[index]))
			result += hex_str[index] - 0;
		else if (ft_isalpha(hex_str[index]))
		{
			if (hex_str[index] >='a' && hex_str[index] <= 'f')
				result += hex_str[index] - 'a' + 10;
			if (hex_str[index] >='A' && hex_str[index] <= 'F')
				result += hex_str[index] - 'A' + 10;
		}
		else
		{
			ft_printf("Error: invalid hexadecimal character: %c\n.", hex_str[index]);
			return (-1);
		}
		index++;
	}
	return (result);
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