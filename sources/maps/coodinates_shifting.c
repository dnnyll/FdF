/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coodinates_shifting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:23:18 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/03 13:36:25 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this group is responsible for calculating and centering our projection
#include "fdf.h"

void	coordinates_shifting(t_map *map)
{
	int		row;
	int		col;
	float	offset_x;
	float	offset_y;

	axis_point_calculation(map);
	center_calculation(map);
	// Computes offsets (shift to center)
	offset_x = (map->iso->window_width / 2) - map->iso->center_x;
	offset_y = (map->iso->window_height / 2) - map->iso->center_y;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			// Applies offset to every point
			map->conversion_grid[row][col * 2] += offset_x;
			map->conversion_grid[row][col * 2 + 1] += offset_y;
			col++;
		}
		row++;
	}
	print_conversion_grid(map);
}

void	axis_point_calculation(t_map *map)
{
	int	row;
	int	col;
	
	row = 0;
	map->iso->sum_x_points = 0;
	map->iso->sum_y_points = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->iso->sum_x_points += map->conversion_grid[row][col * 2];
			map->iso->sum_y_points += map->conversion_grid[row][col * 2 + 1];
			col++;	
		}
		row++;
	}
}


void	center_calculation(t_map *map)
{
	int count_points = map->x * map->y; // gets total number of points

	// calculate the average position (center of mass)
	map->iso->center_x = map->iso->sum_x_points / count_points;
	map->iso->center_y = map->iso->sum_y_points / count_points;

	ft_printf("Center X: %f, Center Y: %f\n", map->iso->center_x, map->iso->center_y);
}
