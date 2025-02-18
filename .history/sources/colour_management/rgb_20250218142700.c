/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:21:28 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 14:27:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rgb_management(t_map *map, int row, int col)
{
	int	colour;
	
	colour = map->colours_matrix[row][col];
	map->colour->red = (colour >> 16) & 0xFF;
	map->colour->green = (colour >> 8) & 0xFF;
	map->colour->blue = colour & 0xFF;
}

void	rgb_grid_populate(t_map *map)
{
	int row;
	int col;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			rgb_management(map, row, col);
			if (!map->colour->rgb_grid)
			{
				ft_printf("Error: rgb_grid is NULL!\n");
				return;
			}
			map->colour->rgb_grid[row][col] = 
				(map->colour->red << 16) |
				(map->colour->green << 8) |
				(map->colour->blue);
			col++;
		}
		row++;
	}
}
void	malloc_rgb_grid(t_map *map)
{
	int row;

	row = 0;
	map->colour->rgb_grid = malloc(sizeof(int *) * map->y);
	if (!map->colour->rgb_grid)
	{
		ft_printf("Error: Failed to allocate rgb_grid\n");
		return;
	}
	while (row < map->y)
	{
		map->colour->rgb_grid[row] = malloc(sizeof(int) * map->x);
		if (!map->colour->rgb_grid[row])
		{
			ft_printf("Error: Failed to allocate rgb_grid row %d\n", row);
			return;
		}
		row++;
	}
}