/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:53:48 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/24 14:10:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	operation_launch(t_map *map)
{
	matrix_converter(map);
	alloc_coordinates_grid(map);
	scaling_coordinates(map);
	alloc_conversion_grid(map);
	iso_conversion_grid(map);
	coordinates_shifting(map);
}

void	operation_free(t_map *map)
{
	free_conversion_grid(map);
	free_colours_matrix(map);
	free_rgb_grid(map);
	free_coordinates_grid(map);
}

void	operation_mlx(t_map *map)
{
	map->window->mlx_ptr = mlx_init();
	map->window->win_ptr = mlx_new_window(map->window->mlx_ptr, \
	map->window->width, map->window->height, "FdF");
	map->window->img_ptr = mlx_new_image(map->window->mlx_ptr, \
	map->window->width, map->window->height);
	map->buffer = mlx_get_data_addr(map->window->img_ptr, &map->bpp, \
	&map->size_line, &map->endian);
}
