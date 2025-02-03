/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:49:01 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/30 10:05:01 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_points(t_map *map)
{
	int	row;
	int	col;

	while (row < map->y)
	{
		while (col < map->x)
		{
			if (col < map->x - 1)
			
			if (row < map->y - 1)
			col++;
		}
		row++;
	}
}