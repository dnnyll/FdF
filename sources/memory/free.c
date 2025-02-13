/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:04:56 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/13 08:30:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_t_map(t_map *map)
{
	int	i;
	int	j;

	// Free `line` if allocated
	if (map->line)
		free(map->line);

	// Free `char_matrix_stash` (a `char **`)
	if (map->char_matrix_stash)
	{
		i = 0;
		while (map->char_matrix_stash[i])
		{
			free(map->char_matrix_stash[i]);
			i++;
		}
		free(map->char_matrix_stash);
	}

	// Free `z_matrix` (an `int **`)
	if (map->z_matrix)
	{
		i = 0;
		while (map->z_matrix[i])
		{
			free(map->z_matrix[i]);
			i++;
		}
		free(map->z_matrix);
	}

	// Free `colours_matrix` (an `int **`)
	if (map->colours_matrix)
	{
		i = 0;
		while (map->colours_matrix[i])
		{
			free(map->colours_matrix[i]);
			i++;
		}
		free(map->colours_matrix);
	}

	// Free `c_z_matrix` (a `char ***`)
	if (map->c_z_matrix)
	{
		i = 0;
		while (map->c_z_matrix[i])
		{
			j = 0;
			while (map->c_z_matrix[i][j])
			{
				free(map->c_z_matrix[i][j]);
				j++;
			}
			free(map->c_z_matrix[i]);
			i++;
		}
		free(map->c_z_matrix);
	}

	// Free `c_colours_matrix` (a `char ***`)
	if (map->c_colours_matrix)
	{
		i = 0;
		while (map->c_colours_matrix[i])
		{
			j = 0;
			while (map->c_colours_matrix[i][j])
			{
				free(map->c_colours_matrix[i][j]);
				j++;
			}
			free(map->c_colours_matrix[i]);
			i++;
		}
		free(map->c_colours_matrix);
	}

	// Finally, free the structure itself
	free(map);
}
