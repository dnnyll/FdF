/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:19:52 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 13:19:31 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void matrix_converter(t_map *map)
{
	ft_printf("Allocating memory for z_matrix and colours_matrix\n");
	int_matrix_alloc(map);
	ft_printf("Converting z_matrix to z_matrix\n");
	populate_int_values(map);
	free_c_z_matrix(map);
	ft_printf("Converting colours_matrix to colours_matrix\n");
	populate_int_colours(map);
	free_c_colours_matrix(map);
}

int	colour_converter(const char *hex_str)
{
	const char *hex_base;
	
	hex_base = "0123456789ABCDEF";
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
	ft_printf("Populating z_matrix with converted integers\n");
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			map->z_matrix[i][j] = ft_atoi(map->c_z_matrix[i][j]);
			j++;
		}
		i++;
	}
	ft_printf("z_matrix population completed\n");
}

void	populate_int_colours(t_map *map)
{
	ft_printf("Populating colours_matrix with converted hex values\n");
	int	i;
	int	j;
	int	default_colour;

	i = 0;
	default_colour = 0X00FF41;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->c_colours_matrix[i][j])
				map->colours_matrix[i][j] = colour_converter(map->c_colours_matrix[i][j]);
			else
				map->colours_matrix[i][j] = default_colour; // Default value for no color
			j++;
		}
		i++;
	}
	ft_printf("colours_matrix population completed\n");
}
