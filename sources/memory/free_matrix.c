/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:26:46 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 12:05:05 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Free the `line` string
// void free_line(char *line) {
// 	if (line) {
// 		free(line);
// 	}
// }

void free_char_matrix_stash(t_map *map)
{
	int i = 0;
	while (i < map->y && map->char_matrix_stash[i])
	{
		ft_printf("Freeing char_matrix_stash row %d: %p\n", i, map->char_matrix_stash[i]);
		free(map->char_matrix_stash[i]);
		map->char_matrix_stash[i] = NULL;
		i++;
	}
	free(map->char_matrix_stash);
	map->char_matrix_stash = NULL;
}

void free_c_z_matrix(t_map *map)
{
	int i;
	int	j;
	
	i = 0;
	if (map->c_z_matrix)
	{
		while (map->c_z_matrix[i])
		{
			j = 0;
			while (map->c_z_matrix[i][j])
			{
				ft_printf("Freeing c_z_matrix[%d][%d]: %p\n", i, j, map->c_z_matrix[i][j]);
				free(map->c_z_matrix[i][j]);
				j++;
			}
			free(map->c_z_matrix[i]);
			i++;
		}
		free(map->c_z_matrix);
	}
}

void	free_c_colours_matrix(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (map->c_colours_matrix)
	{
		while (map->c_colours_matrix[i])
		{
			j = 0;
			while (map->c_colours_matrix[i][j])
			{
				if (map->c_colours_matrix[i][j])
				{
					ft_printf("Freeing c_colours_matrix[%d][%d]: %p\n", i, j, map->c_colours_matrix[i][j]);
					free(map->c_colours_matrix[i][j]);
					j++;
				}
				else
					ft_printf("Skipping NULL c_colours_matrix[%d][%d]\n", i, j);
			}
			free(map->c_colours_matrix[i]);
			i++;
		}
		free(map->c_colours_matrix);
	}
}



// // Free the `colours_matrix` (an `int **`)
// void free_colours_matrix(int **colours_matrix) {
// 	int i = 0;
// 	if (colours_matrix) {
// 		while (colours_matrix[i]) {
// 			free(colours_matrix[i]);
// 			i++;
// 		}
// 		free(colours_matrix);
// 	}
// }

// // Free the `c_map->z_matrix` (a `char ***`)
// void free_c_map->z_matrix(char ***c_map->z_matrix) {
// 	int i = 0;
// 	int j;
// 	if (c_map->z_matrix) {
// 		while (c_map->z_matrix[i]) {
// 			j = 0;
// 			while (c_map->z_matrix[i][j]) {
// 				free(c_map->z_matrix[i][j]);
// 				j++;
// 			}
// 			free(c_map->z_matrix[i]);
// 			i++;
// 		}
// 		free(c_map->z_matrix);
// 	}
// }


