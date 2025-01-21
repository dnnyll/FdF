/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:08:55 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/21 12:06:18 by daniefe2         ###   ########.fr       */
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

void	read_map_size(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening and reading file\n");
		exit(EXIT_FAILURE);
	}
	matrix_memory_alloc(map);
}

void	matrix_alloc_height(t_map *map, int tracker)
{
	tracker = 0;
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
	matrix_alloc_width(map, tracker);
}

void	matrix_alloc_width(t_map *map, int tracker)
{
	tracker = 0;
	while (tracker < map->height)
	{
		map->z_matrix[tracker] = (int *)malloc(sizeof(int *) * map->width);
		if(!map->z_matrix[tracker])
		{
			ft_printf("Error allocating width memory for z_matrix");
			exit(EXIT_FAILURE);
		}
		map->colour_matrix[tracker] = (int *)malloc(sizeof(int *) * map->width);
		if(!map->colour_matrix[tracker])
		{
			ft_printf("Error allocating width memory for colour_matrix");
			exit(EXIT_FAILURE);
		}
		tracker++;
	}
}
void parse_map_row(char *row, int *z_row, int *color_row, int width)
{
	char 	**parts;
	char	**z_str;
	char	**colour_str;
	char	**z_colour;
	char	**comma_pos;
	int		index;

	parts = ft_split(line, ' ');
	if (!parts)
	{
		ft_printf("Error splitting line\n");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while(parts[index])
	{
		z_str = parts[index];
		colour_str = NULL;
		comma_pos = ft_strchr(parts[index], ',');
		if (comma_pos)
		{
			*comma_pos = '\0';
			colour_str = comma_pos + 1;
		}
		z_row[index] = ft_atoi(z_str);
		if(colour_str)
			colour_str = hex_to_int(colour_str);
		else
			colour_row[index] = 0xFF8DA1;
		index++;
	}
	free (parts);
}
}

int	hex_to_int(const char *hex_str)
{	
	int	index;
	int	result;

	index = 2; // skips 0x
	result = 0;

	while(hex_str[index] != '\0')
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