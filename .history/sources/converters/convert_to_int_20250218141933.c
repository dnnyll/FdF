/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:19:52 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 14:19:33 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_converter(t_map *map)
{
	int_matrix_alloc(map);
	populate_int_values(map);
	free_c_z_matrix(map);
	populate_int_colours(map);
	free_c_colours_matrix(map);
}

int	colour_converter(const char *hex_str)
{
	const char	*hex_base;
	int			result;

	hex_base = "0123456789ABCDEF";
	if (!hex_str)
	{
		ft_printf("Error: NULL input.\n");
		return (-1);
	}
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	result = ft_atoi_base(hex_str, hex_base);
	return (result);
}

void	populate_int_values(t_map *map)
{
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
}

void	populate_int_colours(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->c_colours_matrix[i][j])
				map->colours_matrix[i][j] = \
			colour_converter(map->c_colours_matrix[i][j]);
			else
				map->colours_matrix[i][j] = map->colour->default_colour;
			j++;
		}
		i++;
	}
}
