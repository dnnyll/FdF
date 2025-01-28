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

void	alloc_coordinates_grid(t_map *map)
{
	int	row;
	int	col;
	ft_printf("x: %d, y: %d, z: %d\n", map->x, map->y, map->z);
	map->coordinates_grid = malloc(sizeof(int **) * map->y);
	if(!map->coordinates_grid)
	{
		exit (EXIT_FAILURE);
	}
	row = 0;
	while (row < map->y)
	{
		map->coordinates_grid[row] = malloc((sizeof(int*)) * map->x);
		if (!map->coordinates_grid[row])
		{
			exit (EXIT_FAILURE);
		}
	
		col = 0;
		while (col < map->x)
		{
			map->coordinates_grid[row][col] = malloc((sizeof(int*)) * 3);
			if (!map->coordinates_grid[row][col])
			{
				exit (EXIT_FAILURE);
			}
			map->coordinates_grid[row][col][0] = col;	// x-coordinate
			map->coordinates_grid[row][col][1] = row;	// y-coordinate
			map->coordinates_grid[row][col][2] = map->z_matrix[row][col];	// z-coordinate
			col++;
		}
	row++;
	}
}

void print_coordinates_grid(t_map *map)
{
	ft_printf("Initiating coordinates_grid matrix printing.\n");

	int row = 0;
	while (row < map->y) // Iterating over rows
	{
		int col = 0;
		while (col < map->x) // Iterating over columns
		{
			// Access and print [x, y, z] for each coordinate
			ft_printf("[x: %d, y: %d, z: %d]", 
				map->coordinates_grid[row][col][0], // x-coordinate
				map->coordinates_grid[row][col][1], // y-coordinate
				map->coordinates_grid[row][col][2]  // z-coordinate
			);
			if (col < map->x - 1) // Add a tab unless it's the last column in the row
				ft_printf("\t");

			col++;
		}
		ft_printf("\n"); // Move to the next line after each row
		row++;
	}
	ft_printf("Printing completed.\n");
}

