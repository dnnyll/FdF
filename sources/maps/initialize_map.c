/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:57:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/28 14:32:44 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*initialize_map(void)
{
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Memory allocation failed for structs");
		free (map);
		return (NULL);
	}
	map->iso = (t_iso *)malloc(sizeof(t_iso));
	if (!map->iso)
	{
		ft_printf("Memory allocation failed for structs");
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
	map->scaling_factor = 10;
	
	map->iso->cos = 0.866f;
	map->iso->sin = 0.5f;
	map->iso->x_iso = 0;
	map->iso->y_iso = 0;
	map->iso->x_scaled = 0;
	map->iso->y_scaled = 0;
	map->iso->z_scaled = 0;

}
