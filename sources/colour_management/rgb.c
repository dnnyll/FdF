
#include "fdf.h"

void	rgb_management(t_map *map, int row, int col)
{
	int colour = map->colours_matrix[row][col];
	// printf("Accessing colours_matrix at [%d][%d]: %d\n", row, col, colour);

	map->colour->red = (colour >> 16) & 0xFF;
	map->colour->green = (colour >> 8) & 0xFF;
	map->colour->blue = colour & 0xFF;

	printf("red[%d] green[%d] blue[%d]\n", map->colour->red, map->colour->green, map->colour->blue);
}

void	rgb_grid_populate(t_map *map)
{
	int row;
	int col;

	printf("x = %d, y = %d\n", map->x, map->y);
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			rgb_management(map, row, col);
			// printf("i = %d | row = %d | col = %d\n", i, row, col);
			// printf("map->colour->red = %d\n", map->colour->red);
			// printf("map->colour->green = %d\n", map->colour->green);
			// printf("map->colour->blue = %d\n", map->colour->blue);
			if (!map->colour->rgb_grid)
			{
				printf("Error: rgb_grid is NULL!\n");
				return;
			}
			map->colour->rgb_grid[row][col] = 
				(map->colour->red << 16) |
				(map->colour->green << 8) |
				(map->colour->blue);
			// printf("Assigned rgb_grid[%d][%d] = 0x%06X\n", row, col, map->colour->rgb_grid[row][col]);
			col++;
		}
		row++;
	}
	print_rgb_grid(map);
}
void	malloc_rgb_grid(t_map *map)
{
	int row = 0;

	printf("malloc_rgb_grid : x = %d, y = %d\n", map->x, map->y);

	map->colour->rgb_grid = malloc(sizeof(int *) * map->y);
	if (!map->colour->rgb_grid)
	{
		printf("Error: Failed to allocate rgb_grid\n");
		exit(EXIT_FAILURE);
	}

	while (row < map->y)
	{
		map->colour->rgb_grid[row] = malloc(sizeof(int) * map->x);
		if (!map->colour->rgb_grid[row])
		{
			printf("Error: Failed to allocate row %d\n", row);
			exit(EXIT_FAILURE);
		}
		row++;
	}
}