/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:50:42 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/05 12:09:43 by daniefe2         ###   ########.fr       */
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
	map->conversion_grid = malloc((sizeof(double *)) * map->y);
	if (!map->conversion_grid)
	{
		ft_printf("Error: memory allocation failed\n");
		free_conversion_grid(map);
		exit (EXIT_FAILURE);
	}
	while (i < map->y)
	{
		map->conversion_grid[i] = malloc((sizeof(double)) * (map->x * 2));
		if (!map->conversion_grid[i])
		{
			ft_printf("Error: memory allocation failed\n");
			free_conversion_grid(map);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	ft_printf("Memory allocation successful\n");
	// populate_conversion_grid(map);
}
//		needs to be free
void	populate_conversion_grid(t_map * map)
{
	int		row;
	int		col;
	double	min_x_iso = find_x_iso_min(map);
	double	min_y_iso = find_y_iso_min(map);
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map-> x)
		{
			map->iso->x_scaled = map->coordinates_grid[row][col][0];
			map->iso->y_scaled = map->coordinates_grid[row][col][1];
			map->iso->z_scaled = map->coordinates_grid[row][col][2];
			// Apply isometric transformation
			map->iso->x_iso = (map->iso->x_scaled - map->iso->y_scaled) - min_x_iso;
			map->iso->y_iso = (map->iso->x_scaled + map->iso->y_scaled * map->iso->sin - map->iso->z_scaled) - min_y_iso;
			boundry_check(map);
			map->conversion_grid[row][col * 2] = map->iso->x_iso;
			map->conversion_grid[row][col * 2 + 1] = map->iso->y_iso;
			col++;
		}
		row++;
	}
}
double	find_x_iso_min(t_map *map)
{
	int	row;
	int	col;
	double	min_x;
	
	min_x = 0;
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->iso->x_scaled = map->coordinates_grid[row][col][0];
			map->iso->y_scaled = map->coordinates_grid[row][col][1];
			map->iso->x_iso = (map->iso->x_scaled - map->iso->y_scaled) * map->iso->cos;
			if (map->iso->x_iso < min_x)
				min_x = map->iso->x_iso;
			col++;
		}
		row++;
	}
	return (min_x);
}
double	find_y_iso_min(t_map *map)
{
	int	row;
	int	col;
	double	min_y;
	
	min_y = 0;
	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			map->iso->x_scaled = map->coordinates_grid[row][col][0];
			map->iso->y_scaled = map->coordinates_grid[row][col][1];
			map->iso->y_iso = (map->iso->y_scaled - map->iso->x_scaled) * map->iso->cos;
			if (map->iso->y_iso < min_y)
				min_y = map->iso->y_iso;
			col++;
		}
		row++;
	}
	return (min_y);
}

void	boundry_check(t_map *map)
{
	// Print values before clamping
	// printf("Before: x_iso = %f, y_iso = %f\n", map->iso->x_iso, map->iso->y_iso);

	// Clamp x_iso and y_iso within the bounds of the window
	if (map->iso->x_iso < 0)
		map->iso->x_iso = 0; // Prevent it from going left of the window
	else if (map->iso->x_iso >= map->iso->window_width)
		map->iso->x_iso = map->iso->window_width - 1; // Prevent it from going beyond the window width

	if (map->iso->y_iso < 0)
		map->iso->y_iso = 0; // Prevent it from going above the window
	else if (map->iso->y_iso >= map->iso->window_height)
		map->iso->y_iso = map->iso->window_height - 1; // Prevent it from going beyond the window height

	// Print values after clamping
	// printf("After: x_iso = %f, y_iso = %f\n\n", map->iso->x_iso, map->iso->y_iso);
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