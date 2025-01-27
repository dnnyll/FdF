/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_convertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:50:42 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/27 11:59:11 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_conversion(t_map *map)
{
	int	scale;
	int x_scaled;
	int y_scaled;
	int z_scaled;

	scale = 200;
	y_scaled = y * scale;
	z_scaled = z * scale;
	while (map->coordinates_grid)
	{
			x_scaled = x * scale;
	}
}