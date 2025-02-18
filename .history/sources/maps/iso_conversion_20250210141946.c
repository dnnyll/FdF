/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:50:42 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/10 14:19:47 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling_coordinates(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->coordinates_grid[row][col][0] *= map->scaling_factor;
			map->coordinates_grid[row][col][1] *= map->scaling_factor;
			map->coordinates_grid[row][col][2] *= map->scaling_factor;
			col++;
		}
	row++;
	}
}
void	alloc_conversion_grid(t_map *map)
{
	int	i;
	
	i = 0;
	map->conversion_grid = malloc((sizeof(double *)) * map->y);
	if (!map->conversion_grid)
	{
		ft_printf("Error: memory allocation failed\n");
		free_conversion_grid(map);
		return;
	}
	while (i < map->y)
	{
		map->conversion_grid[i] = malloc((sizeof(double)) * (map->x * 2));
		if (!map->conversion_grid[i])
		{
			ft_printf("Error: memory allocation failed\n");
			free_conversion_grid(map);
			return;
		}
		i++;
	}
	iso_conversion_grid(map);
}

void	iso_conversion_grid(t_map * map)
{
	int		row;
	int		col;

	map->iso->min_x_iso = find_x_iso_min(map);
	map->iso->min_y_iso = find_y_iso_min(map);
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map-> x)
		{
			map->iso->x_scaled = map->coordinates_grid[row][col][0];
			map->iso->y_scaled = map->coordinates_grid[row][col][1];
			map->iso->z_scaled = map->coordinates_grid[row][col][2];
			map->iso->x_iso = (map->iso->x_scaled - map->iso->y_scaled) - map->iso->min_x_iso;
			map->iso->y_iso = (map->iso->x_scaled + map->iso->y_scaled * map->iso->sin - map->iso->z_scaled) - map->iso->min_y_iso;
			map->conversion_grid[row][col * 2] = map->iso->x_iso;
			map->conversion_grid[row][col * 2 + 1] = map->iso->y_iso;
			col++;
		}
		row++;
	}
}

double	find_x_iso_min(t_map *map)
{
	int	row;
	int	col;
	double	min_x;
	
	min_x = 0;
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->iso->x_scaled = map->coordinates_grid[row][col][0];
			map->iso->y_scaled = map->coordinates_grid[row][col][1];
			map->iso->x_iso = (map->iso->x_scaled - map->iso->y_scaled) * map->iso->cos;
			if (map->iso->x_iso < min_x)
				min_x = map->iso->x_iso;
			col++;
		}
		row++;
	}
	return (min_x);
}
double	find_y_iso_min(t_map *map)
{
	int	row;
	int	col;
	double	min_y;
	
	min_y = 0;
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->iso->x_scaled = map->coordinates_grid[row][col][0];
			map->iso->y_scaled = map->coordinates_grid[row][col][1];
			map->iso->y_iso = (map->iso->y_scaled - map->iso->x_scaled) * map->iso->cos;
			if (map->iso->y_iso < min_y)
				min_y = map->iso->y_iso;
			col++;
		}
		row++;
	}
	return (min_y);
}