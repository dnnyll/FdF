/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:04:56 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 10:11:43 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_t_map(t_map *map)
{
	int	index;
	int	jndex;

	// Free `line` if allocated
	if (map->line)
		free(map->line);

	// Free `char_matrix_stash` (a `char **`)
	if (map->char_matrix_stash)
	{
		index = 0;
		while (map->char_matrix_stash[index])
		{
			free(map->char_matrix_stash[index]);
			index++;
		}
		free(map->char_matrix_stash);
	}

	// Free `z_matrix` (an `int **`)
	if (map->z_matrix)
	{
		index = 0;
		while (map->z_matrix[index])
		{
			free(map->z_matrix[index]);
			index++;
		}
		free(map->z_matrix);
	}

	// Free `colours_matrix` (an `int **`)
	if (map->colours_matrix)
	{
		index = 0;
		while (map->colours_matrix[index])
		{
			free(map->colours_matrix[index]);
			index++;
		}
		free(map->colours_matrix);
	}

	// Free `c_z_matrix` (a `char ***`)
	if (map->c_z_matrix)
	{
		index = 0;
		while (map->c_z_matrix[index]) {
			jndex = 0;
			while (map->c_z_matrix[index][jndex]) {
				free(map->c_z_matrix[index][jndex]);
				jndex++;
			}
			free(map->c_z_matrix[index]);
			index++;
		}
		free(map->c_z_matrix);
	}

	// Free `c_colours_matrix` (a `char ***`)
	if (map->c_colours_matrix)
	{
		index = 0;
		while (map->c_colours_matrix[index]) {
			jndex = 0;
			while (map->c_colours_matrix[index][jndex]) {
				free(map->c_colours_matrix[index][jndex]);
				jndex++;
			}
			free(map->c_colours_matrix[index]);
			index++;
		}
		free(map->c_colours_matrix);
	}

	// Finally, free the structure itself
	free(map);
}
