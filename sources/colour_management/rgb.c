
#include "fdf.h"

void	rgb_management(t_map *map, int row, int col)
{
	int colour = map->colours_matrix[row][col];
	// printf("Accessing colours_matrix at [%d][%d]: %d\n", row, col, colour);

	map->colour->red = (colour >> 16) & 0xFF;
	map->colour->green = (colour >> 8) & 0xFF;
	map->colour->blue = colour & 0xFF;
}

void	rgb_grid_populate(t_map *map)
{
	int row;
	int col;
	int	i = 0;
	printf("x = %d, y = %d\n", map->x, map->y);
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			rgb_management(map, row, col);
			printf("i = %d | row = %d | col = %d\n", i, row, col);
			printf("map->colour->red = %d\n", map->colour->red);
			printf("map->colour->green = %d\n", map->colour->green);
			printf("map->colour->blue = %d\n", map->colour->blue);
			if (map->colour->rgb_grid == NULL)
			{
				printf("Error: rgb_grid is NULL!\n");
				return;
			}
			if (map->colour->rgb_grid[row][col] == NULL)
			{
				printf("Error: rgb_grid[%d][%d] is NULL!\n", row, col);
				return;
			}
			map->colour->rgb_grid[row][col][0] = map->colour->red;
			map->colour->rgb_grid[row][col][1] = map->colour->green;
			map->colour->rgb_grid[row][col][2] = map->colour->blue;
			printf("Assigned rgb_grid[%d][%d] = [%d, %d, %d]\n",
				row, col,
				map->colour->rgb_grid[row][col][0],
				map->colour->rgb_grid[row][col][1],
				map->colour->rgb_grid[row][col][2]);
			col++;
			i++;
		}
		row++;
	}
}
void	malloc_rgb_grid(t_map *map)
{
	int row;
	int col;
	printf("malloc_rgb_grid : x = %d, y = %d\n", map->x, map->y);

	map->colour->rgb_grid = malloc(sizeof(int **) * map->y);
	if (!map->colour->rgb_grid)
			exit(EXIT_FAILURE);
	row = 0;
	while (row < map->y)
	{
		map->colour->rgb_grid[row] = malloc(sizeof(int *) * map->x);
		if (!map->colour->rgb_grid[row])
			exit(EXIT_FAILURE);

		col = 0;
		while (col < map->x)
		{
			map->colour->rgb_grid[row][col] = malloc(sizeof(int) * 3);
			if (!map->colour->rgb_grid[row][col])
				exit(EXIT_FAILURE);
			col++;
		}
		row++;
	}
}
