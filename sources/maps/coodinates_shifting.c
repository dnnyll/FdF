/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coodinates_shifting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:23:18 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/30 12:06:58 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coordinates_shifting(t_map *map)
{
	int	i;

	center_calculation(map);

	offset_x = center_x - current_center;
	offset_y = center_y - current_center;
	
	// while (i < )
	// map->iso->x_iso_shift = map->iso->x_iso + map->iso->offset_x;
	// map->iso->y_iso_shift = map->iso->y_iso + map->iso->offset_y;
}

void	axis_point_calculation(t_map *map)
{
	int	row;
	int	col;
	
	row = 0;
	map->iso->sum_x_points = map->coordinates_grid[row][col];
	map->iso->sum_y_points = map->coordinates_grid[row][col];
	while (row < map->y)
	{
		while (col < map->x)
		{
			map->iso->sum_x_points += map->coordinates_grid[row][col];
			col++;	
		}
		map->iso->sum_y_points += map->coordinates_grid[row][col];
		row++;
	}
}

void	center_calculation(t_map *map)
{
	int	row;
	int	col;
	int	count_points;
	
	row = 0;
	while (row < map->y)
	{
		while (col < map->x)
		{
			count_points++;
			col++;	
		}
		count_points++;
		row++;
	}
	map->iso->center_x = map->iso->sum_x_points / count_points;
	map->iso->center_y = map->iso->sum_y_points / count_points;
	ft_printf("center x: %d, center y: %d\n", map->iso->center_x, map->iso->center_y);
}

