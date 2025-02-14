/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_matrices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:00:25 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/14 08:28:10 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_matrices(t_map *map)
{
	init_row_pointers(map);
	init_cell_pointers(map);
}

void	init_row_pointers(t_map *map)
{
	int i = 0;

	while (i < map->y)
	{
		if (map->c_z_matrix)
			map->c_z_matrix[i] = NULL;
		if (map->c_colours_matrix)
			map->c_colours_matrix[i] = NULL;
		if (map->coordinates_grid)
			map->coordinates_grid[i] = NULL;
		if (map->conversion_grid)
			map->conversion_grid[i] = NULL;
		if (map->z_matrix)
			map->z_matrix[i] = NULL;
		if (map->colours_matrix) 
			map->colours_matrix[i] = NULL;
		if (map->colour->rgb_grid)  
			map->colour->rgb_grid[i] = NULL;
		i++;
	}

	if (map->char_matrix_stash)  
		map->char_matrix_stash = NULL;
}

void	init_cell_pointers(t_map *map)
{
	int i = 0;
	int j;

	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->c_z_matrix && map->c_z_matrix[i])  
				map->c_z_matrix[i][j] = NULL;
			if (map->c_colours_matrix && map->c_colours_matrix[i])  
				map->c_colours_matrix[i][j] = NULL;
			if (map->coordinates_grid && map->coordinates_grid[i])  
				map->coordinates_grid[i][j] = NULL;
			j++;
		}
		i++;
	}
}
