/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:26:46 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 15:38:38 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_char_matrix_stash(t_map *map)
{
	if (!map->char_matrix_stash)
		return ;
	int row = 0;
	while (row < map->y)
	{
		if (map->char_matrix_stash[row])
			free(map->char_matrix_stash[row]);
		row++;
	}

	free(map->char_matrix_stash);
	map->char_matrix_stash = NULL;
}

void	free_c_z_matrix(t_map *map)
{
	int row;
	int col;

	row = 0;
	while (row < map->y)
	{
		if (map->c_z_matrix[row])
		{
			col = 0;
			while (map->c_z_matrix[row][col])
			{
				free(map->c_z_matrix[row][col]);
				col++;
			}
			free(map->c_z_matrix[row]);
		}
		row++;
	}
	free(map->c_z_matrix);
}

void	free_c_colours_matrix(t_map *map)
{
	int row;
	int col;

	row = 0;
	if (map->c_colours_matrix)
	{
		while (row < map->y)
		{
			if (map->c_colours_matrix[row])
			{
				col = 0;
				while (col < map->x)
				{
					if (map->c_colours_matrix[row][col])
						free(map->c_colours_matrix[row][col]);
					col++;
				}
				free(map->c_colours_matrix[row]);
			}
			row++;
		}
		free(map->c_colours_matrix);
	}
}

void	free_z_matrix(t_map *map)
{
	int row;

	row = 0;
	if (map->z_matrix)
	{
		while (row < map->y)
		{
			if (map->z_matrix[row])
				free(map->z_matrix[row]);
		row++;
		}
		free(map->z_matrix);
		map->z_matrix = NULL;
	}
}

void	free_colours_matrix(t_map *map)
{
	int	row;

	row = 0;
	if (map->colours_matrix)
	{
		while (row < map->y)
		{
			free(map->colours_matrix[row]);
			map->colours_matrix[row] = NULL;
			row++;
		}
		free(map->colours_matrix);
		map->colours_matrix = NULL;
	}
}
