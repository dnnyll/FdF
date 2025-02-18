/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grids.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:13:33 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 15:14:13 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf"

void	free_t_map(t_map *map)
{
	if (map->line)
		free(map->line);
	if (map->char_matrix_stash)
		free_char_matrix_stash(map);
	if (map->z_matrix)
		free_z_matrix(map);
	if	(map->colours_matrix)
		free_colours_matrix(map);
	if (map->c_z_matrix)
		free_c_z_matrix(map);
	if (map->c_colours_matrix)
		free_c_colours_matrix(map);
	if (map->conversion_grid)
		free_conversion_grid(map);
	if (map->colour->rgb_grid)
		free_rgb_grid(map);
	if (map->coordinates_grid)
		free_coordinates_grid(map);
	free(map);
}
void	free_conversion_grid(t_map *map)
{
	int	row;
	
	row = 0;
	if (map->conversion_grid)
	{
		while (row < map->y && map->conversion_grid[row])
		{
			free(map->conversion_grid[row]);
			map->conversion_grid[row] = NULL;
			row++;
		}
		free(map->conversion_grid);
		map->conversion_grid = NULL;
	}
}
void	free_rgb_grid(t_map *map)
{
	int	row;
	
	row = 0;
	if (map->colour->rgb_grid)
	{
		while (row < map->y && map->colour->rgb_grid[row])
		{
			free(map->colour->rgb_grid[row]);
			map->colour->rgb_grid[row] = NULL;
			row++;
		}
		free(map->colour->rgb_grid);
		map->colour->rgb_grid = NULL;
	}
}
void	free_coordinates_grid(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	if (map->coordinates_grid)
	{
		while (row < map->y)
		{
			col = 0;
			if (map->coordinates_grid[row])
			{
				while (col < map->x)
				{
					if (map->coordinates_grid[row][col])
						free(map->coordinates_grid[row][col]);
					col++;
				}
				free(map->coordinates_grid[row]);
			}
			row++;
		}
		free(map->coordinates_grid);
		map->coordinates_grid = NULL;
	}
}