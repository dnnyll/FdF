/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:57:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 10:51:38 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*initialize_map(void)
{
	t_map *map;
	map = malloc(sizeof(t_map));
	if(!map)
	{
		ft_printf("Memory allocation failed for map");
		exit(EXIT_FAILURE);
	}
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->line = NULL;
	map->char_matrix_stash = NULL;
	map->z_matrix = NULL;
	map->colours_matrix = NULL;
	map->c_z_matrix = NULL;
	map->c_colours_matrix = NULL;
	return (map);
}

