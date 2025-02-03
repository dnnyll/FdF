/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:50:42 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/03 16:17:30 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->coordinates_grid[row][col][0] = 
			map->coordinates_grid[row][col][0] * map->scaling_factor;
			map->coordinates_grid[row][col][1] = 
			map->coordinates_grid[row][col][1] * map->scaling_factor;
			map->coordinates_grid[row][col][2] = 
			map->coordinates_grid[row][col][2] * map->scaling_factor;
			col++;
		}
	row++;
	}
}
void	alloc_conversion_grid(t_map *map)
{
	int	i;
	
	ft_printf("Allocating memory for conversion_grid\n");
	ft_printf("x: %d, y: %d\n", map->x, map->y);
	i = 0;
	map->conversion_grid = malloc((sizeof(float *)) * map->y);
	if (!map->conversion_grid)
	{
		ft_printf("Error: memory allocation failed\n");
		free_conversion_grid(map);
		exit (EXIT_FAILURE);
	}
	while (i < map->y)
	{
		map->conversion_grid[i] = malloc((sizeof(float)) * (map->x * 2));
		if (!map->conversion_grid[i])
		{
			ft_printf("Error: memory allocation failed\n");
			free_conversion_grid(map);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	ft_printf("Memory allocation successful\n");
	populate_conversion_grid(map);
}
//		needs to be free
void	populate_conversion_grid(t_map * map)
{
	int		row;
	int		col;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map-> x)
		{
		map->iso->x_scaled = map->coordinates_grid[row][col][0];
		map->iso->y_scaled = map->coordinates_grid[row][col][1];
		map->iso->z_scaled = map->coordinates_grid[row][col][2];
		map->iso->x_iso = map->iso->x_scaled - map->iso->y_scaled * map->iso->cos;
		map->iso->y_iso = map->iso->x_scaled + map->iso->y_scaled * map->iso->sin - map->iso->z_scaled;
		boundry_check(map);
		map->conversion_grid[row][col * 2] = map->iso->x_iso;
		map->conversion_grid[row][col * 2 + 1] = map->iso->y_iso;
		col++;
	}
	row++;
	}
	print_conversion_grid(map);
}
void	boundry_check(t_map *map)
{
	 // Clamp x_iso and y_iso within the bounds of the window
	if (map->iso->x_iso < 0)
		map->iso->x_iso = 0; // Prevent it from going left of the window
	else if (map->iso->x_iso >= map->iso->window_width)
		map->iso->x_iso = map->iso->window_width - 1; // Prevent it from going beyond the window width
	if (map->iso->y_iso < 0)
		map->iso->y_iso = 0; // Prevent it from going above the window
	else if (map->iso->y_iso >= map->iso->window_height)
		map->iso->y_iso = map->iso->window_height - 1; // Prevent it from going beyond the window height
}

void	print_conversion_grid(t_map *map)
{
	printf("Initiating conversion_grid printing.\n");
	int row = 0;
	while (row < map->y)
	{
		int col = 0;
		while (col < map->x)
		{
			printf("%f\t", map->conversion_grid[row][col * 2]);
			printf("%f\t", map->conversion_grid[row][col * 2 + 1]);
			if (col < map->x - 1)
				printf("\t");
			col++;
		}
		printf("\n");
		row++;
	}
	printf("Printing completed.\n");
}