/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coodinates_shifting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:23:18 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 16:13:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this group is responsible for calculating and centering our projection
#include "fdf.h"

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
	int count_points =
	count_points = map->x * map->y;
	map->iso->center_x = map->iso->sum_x_points / count_points;
	map->iso->center_y = map->iso->sum_y_points / count_points;
}

void	coordinates_shifting(t_map *map)
{
	int		row;
	int		col;
	double	offset_x;
	double	offset_y;

	axis_point_calculation(map);
	center_calculation(map);
	offset_x = (map->iso->window_width / 2) - map->iso->center_x;
	offset_y = (map->iso->window_height / 2) - map->iso->center_y;
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->conversion_grid[row][col * 2] += offset_x;
			map->conversion_grid[row][col * 2 + 1] += offset_y;
			col++;
		}
		row++;
	}
}
