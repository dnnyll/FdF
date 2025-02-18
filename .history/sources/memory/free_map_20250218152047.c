/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:17:07 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_t_map(t_map *map)
{
	if (map->line)
		free(map->line);
	if (map->char_matrix_stash)
		free_char_matrix_stash(map);
	if (map->z_matrix)
		free_z_matrix(map);
	if (map->colours_matrix)
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