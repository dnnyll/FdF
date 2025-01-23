/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:19:52 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/23 11:04:07 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void matrix_converter(t_map *map)
{
	// Step 1: Allocate memory for int matrices
	ft_printf("Allocating memory for values_matrix and colours_matrix\n");
	int_matrix_alloc(map); // Function to allocate memory for integer matrices
	// Step 2: Convert values from char ***values_matrix to int ***values_matrix
	ft_printf("Converting values_matrix to values_matrix\n");
	populate_int_values(map); // Function to convert string values to integers
	// Step 3: Convert colors from char ***colours_matrix to int ***colours_matrix
	ft_printf("Converting colours_matrix to colours_matrix\n");
	populate_int_colours(map); // Function to convert color strings to integer values
}

int	colour_converter(const char *hex_str)
{
	const char *hex_base = "0123456789ABCDEF";

	ft_printf("Initiating hex conversion to int\n");
	if (!hex_str)
	{
		ft_printf("Error: NULL input.\n");
		return (-1);
	}
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	int result = ft_atoi_base(hex_str, hex_base);
	ft_printf("Hex conversion completed: %s -> %d\n", hex_str, result);
	return (result);
}

void	populate_int_values(t_map *map)
{
	ft_printf("Populating values_matrix with converted integers\n");
	int	index;
	int	jndex;

	index = 0;
	while (index < map->height)
	{
		jndex = 0;
		while (jndex < map->width)
		{
			map->values_matrix[index][jndex] = ft_atoi(map->c_parts_values[index][jndex]);
			jndex++;
		}
		index++;
	}
	ft_printf("values_matrix population completed\n");
}

void	populate_int_colours(t_map *map)
{
	ft_printf("Populating colours_matrix with converted hex values\n");
	int	index;
	int	jndex;
	int	default_colour;

	index = 0;
	default_colour = 0X00FF41;
	while (index < map->height)
	{
		jndex = 0;
		while (jndex < map->width)
		{
			if (map->c_parts_colours[index][jndex])
				map->colours_matrix[index][jndex] = colour_converter(map->c_parts_colours[index][jndex]);
			else
				map->colours_matrix[index][jndex] = default_colour; // Default value for no color
			jndex++;
		}
		index++;
	}
	ft_printf("colours_matrix population completed\n");
}

void	int_matrix_alloc(t_map *map)
{
	int	i;

	ft_printf("Allocating memory - Width: %d, Height: %d\n", map->width, map->height);

	map->values_matrix = malloc(sizeof(int *) * map->height);
	map->colours_matrix = malloc(sizeof(int *) * map->height);
	if (!map->values_matrix || !map->colours_matrix)
	{
		ft_printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->height)
	{
		map->values_matrix[i] = malloc(sizeof(int ) * map->width);
		map->colours_matrix[i] = malloc(sizeof(int ) * map->width);

		if (!map->values_matrix[i] || !map->colours_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d\n", i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_printf("Memory allocation completed successfully\n");
}