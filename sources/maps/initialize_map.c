/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:57:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/23 11:45:50 by daniefe2         ###   ########.fr       */
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
	map->line = NULL;
	return (map);
}

