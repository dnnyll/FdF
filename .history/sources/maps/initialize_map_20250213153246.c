/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:57:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/13 15:32:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_other_fields(t_map *map)
{
	map->scaling_factor = 30;
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->line = NULL;
	map->char_matrix_stash = NULL;
	map->z_matrix = NULL;
	map->colours_matrix = NULL;
	map->c_z_matrix = NULL;
	map->c_colours_matrix = NULL;
	map->coordinates_grid = NULL;
	map->conversion_grid = NULL;
	map->colour->rgb_grid = NULL;
	map->colour->default_colour = 0x1f9983;
	map->colour->x_colour_grid = 0;
	map->colour->y_colour_grid = 0;
}

void	initialize_iso_fields(t_iso *iso)
{
	iso->pi_val = 3.141592653589793;
	iso->alpha = 45 * (iso->pi_val / 180.0);
	iso->beta = 75 * (iso->pi_val / 180.0);
	iso->cos_alpha = cos(iso->alpha);
	iso->sin_alpha = sin(iso->alpha);
	iso->cos_beta = cos(iso->beta);
	iso->sin_beta = sin(iso->beta);
	iso->cos = iso->cos_beta;
	iso->sin = iso->sin_alpha;
	iso->x_iso = 0;
	iso->y_iso = 0;
	iso->x_scaled = 0;
	iso->y_scaled = 0;
	iso->z_scaled = 0;
	iso->sum_x_points = 0;
	iso->sum_y_points = 0;
	iso->window_width = 3200;
	iso->window_height = 2048;
}

void	initialize_map_fields(t_map *map)
{
	initialize_other_fields(map);
	initialize_iso_fields(map->iso);
	initialize_matrices(map);
}

t_map	*allocate_map(void)
{
	t_map *map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);

	map->iso = (t_iso *)malloc(sizeof(t_iso));
	map->colour = (t_colour *)malloc(sizeof(t_colour));
	map->window = (t_window *)malloc(sizeof(t_window));

	if (!map->iso || !map->colour || !map->window)
	{
		free(map->iso);
		free(map->colour);
		free(map->window);
		free(map);
		return (NULL);
	}
	return (map);
}

t_map	*initialize_map(void)
{
	t_map *map = allocate_map();
	
	if (!map)
		return (NULL);
	initialize_map_fields(map);
	return (map);
}
