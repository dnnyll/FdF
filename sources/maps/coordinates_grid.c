/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   coordinates_grid.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: daniefe2 <daniefe2@student.42lausanne.c	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/27 10:11:59 by daniefe2		  #+#	#+#			 */
/*   Updated: 2025/01/27 11:27:35 by daniefe2		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fdf.h"

void	alloc_coordinates_row(t_map *map, int row)
{
	int	col;

	map->coordinates_grid[row] = malloc(sizeof(int *) * map->x);
	if (!map->coordinates_grid[row])
	{
		ft_printf("Error allocating coordinates_grid\n");
		return ;
	}
	col = 0;
	while (col < map->x)
	{
		map->coordinates_grid[row][col] = malloc(sizeof(int) * 3);
		if (!map->coordinates_grid[row][col])
		{
			ft_printf("Error allocating coordinates_grid\n");
			return ;
		}
		map->coordinates_grid[row][col][0] = col;
		map->coordinates_grid[row][col][1] = row;
		map->coordinates_grid[row][col][2] = map->z_matrix[row][col];
		col++;
	}
}

void	alloc_coordinates_grid(t_map *map)
{
	int	row;

	map->coordinates_grid = malloc(sizeof(int **) * map->y);
	if (!map->coordinates_grid)
	{
		ft_printf("Error allocating coodinates_grid\n");
		return ;
	}
	row = 0;
	while (row < map->y)
	{
		alloc_coordinates_row(map, row);
		row++;
	}
	free_z_matrix(map);
}
