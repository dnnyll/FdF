/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:50:42 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/27 14:59:39 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	map->scaling_factor = 10;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->coordinates_grid[row][col][0] = map->coordinates_grid[row][col][0] * map->scaling_factor;
			map->coordinates_grid[row][col][1] = map->coordinates_grid[row][col][1] * map->scaling_factor;
			map->coordinates_grid[row][col][2] = map->coordinates_grid[row][col][2] * map->scaling_factor;
			col++;
		}
	row++;
	}
}

// void	iso_convertion(t_map *map)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	col = 0;

// 	alloc_conversion_grid(map);
// }

void	alloc_conversion_grid(t_map *map)
{
	float	cos = 0.866;
	float	sin = 0.5;
	float	x_iso;
	float	y_iso;
	int		row;
	int		col;

	ft_printf("Allocating memory for conversion_grid\n");
	ft_printf("x: %d, y: %d\n", map->x, map->y);
	row = 0;
	while (row < map->y)
	{
		map->conversion_grid[row] = malloc((sizeof(float *)) * map->x);
		if (!map->conversion_grid[row])
		{
			exit (EXIT_FAILURE);
		}
	
		col = 0;
		while (col < map->x)
		{
			map->conversion_grid[row][col] = malloc((sizeof(float)) * 2);
			if (!map->conversion_grid[row][col])
			{
				exit (EXIT_FAILURE);
			}
			map->x_scaled = map->coordinates_grid[row][col][0];
			map->y_scaled = map->coordinates_grid[row][col][1];
			map->z_scaled = map->coordinates_grid[row][col][2];
			x_iso = map->x_scaled - map->y_scaled * cos;
			y_iso = map->x_scaled + map->y_scaled * sin - map->z_scaled;
			map->conversion_grid[row][col][0] = x_iso;
			map->conversion_grid[row][col][1] = y_iso;
			col++;
		}
	row++;
	ft_printf("Memory allocation completed successfully\n");
	}
}
