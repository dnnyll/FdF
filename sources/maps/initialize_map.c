/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:57:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/07 15:30:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*initialize_map(void)
{
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		// ft_printf("Memory allocation failed for structs");
		free (map);
		return (NULL);
	}
	map->iso = (t_iso *)malloc(sizeof(t_iso));
	if (!map->iso)
	{
		// ft_printf("Memory allocation failed for structs");
		free (map);
		return (NULL);
	}
	map->colour = (t_colour *)malloc(sizeof(t_colour));
	if (!map->colour)
	{
		// ft_printf("Memory allocation failed for structs");
		free (map);
		return (NULL);
	}
	initialize_map_fields(map);
	return (map);
}

void initialize_map_fields(t_map *map)
{
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

	map->scaling_factor = 40;
	map->iso->pi_val = 3.141592653589793;
	map->iso->alpha = 75.0 * (map->iso->pi_val / 180.0);
	map->iso->beta = 45.0 * (map->iso->pi_val / 180.0);
	
	map->iso->cos_alpha = cos(map->iso->alpha);
	map->iso->sin_alpha = sin(map->iso->alpha);
	map->iso->cos_beta = cos(map->iso->beta);
	map->iso->sin_beta = sin(map->iso->beta);

	map->iso->zoom = 20;
	map->iso->x_shift = 0;
	map->iso->y_shift = 0;

	map->iso->cos = map->iso->cos_beta;
	map->iso->sin = map->iso->sin_alpha;
	
	map->iso->x_iso = 0;
	map->iso->y_iso = 0;	
	map->iso->x_scaled = 0;
	map->iso->y_scaled = 0;
	map->iso->z_scaled = 0;
	map->iso->sum_x_points = 0;
	map->iso->sum_y_points = 0;
	map->iso->window_width = 3200;
	map->iso->window_height = 2048;

	map->colour->red = 0;
	map->colour->green = 0;
	map->colour->blue = 0;
	map->colour->default_colour = 0x009a22;
	map->colour->rgb_grid = NULL;
	map->colour->x_colour_grid = 0;;
	map->colour->y_colour_grid = 0;;
}
