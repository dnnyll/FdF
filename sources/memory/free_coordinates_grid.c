/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coordinates_grid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:30:19 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/27 11:40:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_coordinates_grid(t_map *map)
{
	int row = 0;
	int col = 0;

	// Free each innermost array (int* at [row][col])
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			printf("Freeing coordinates_grid[%d][%d]: %p\n", col, row, map->coordinates_grid[col][row]);
			free(map->coordinates_grid[row][col]);
			col++;
		}
		// Free the array of int* (map->coordinates_grid[row])
		printf("Freeing coordinates_grid[%d]: %p\n", row, map->coordinates_grid[row]);
		free(map->coordinates_grid[row]);
		row++;
	}
	// Free the array of int** (map->coordinates_grid)
	printf("Freeing coordinates_grid: %p\n", map->coordinates_grid);
	free(map->coordinates_grid);
	// Nullify the pointer to avoid dangling pointers
	map->coordinates_grid = NULL;
}
