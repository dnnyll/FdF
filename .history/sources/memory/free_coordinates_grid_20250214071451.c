/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coordinates_grid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:30:19 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/14 07:14:51 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_coordinates_grid(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	if (!map->coordinates_grid)
	{
		ft_printf("No memory to free for coordinates_grid.\n");
		return ;
	}
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			printf("Freeing coordinates_grid[%d][%d] at %p\n", row, col, (void *)map->coordinates_grid[row][col]);
			free(map->coordinates_grid[row][col]);
			col++;
		}
		printf("Freeing coordinates_grid[%d] at %p\n", row, (void *)map->coordinates_grid[row]);
		free(map->coordinates_grid[row]);
		row++;
	}
	printf("Freeing coordinates_grid at %p\n", (void *)map->coordinates_grid);
	free (map->coordinates_grid);
	return(1);
}

// void free_coordinates_grid(t_map *map)
// {
// 	int row;
// 	int col;
	
// 	if (!map->coordinates_grid)
// 		return;
// 	row = 0;
// 	while (row < map->y)
// 	{
// 		if (!map->coordinates_grid[row])
// 		{
// 			row++;
// 				continue;
// 		}
// 		col = 0;
// 		while (col < map->x)
// 		{
// 		free(map->coordinates_grid[row][col]);
// 		col++;
// 		}
// 		free(map->coordinates_grid[row]);
// 		row++;
// 	}
// 	free(map->coordinates_grid);
// }

