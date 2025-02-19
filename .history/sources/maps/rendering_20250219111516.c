/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:02:50 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 11:15:16 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_img (t_map *map)
{
	int	i;
	int	j;
	
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->window->win_width, \
	map->window->win_height);
	map->render->buffer = mlx_get_data_addr(map->img_ptr, \
	&map->render->bpp, &map->render->size_line, &map->render->endian);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->colour->current_colour = map->colours_matrix[i][j];
			put_pixel(map->render->buffer, map->current_colour, \
			map->window->win_width, map->window->win_height, \
			map->render->bpp, map->render->size_line);
			j++;
		}
		i++;
	}
}

void	put_pixel(t_map *map)
{
	int	pixel_index;

	pixel_index = (map->y * map->render->size_line) + \
	(map->x * (map->render->bpp / 8));
	*(unsigned int *)(map->render->buffer + pixel_index) = \
	map->colour->current_color;
	map->render->pixel_address = map->render->image_buffer + \
	(map->y * map->render->size_line) + (map->x (map->render->bpp / 8));
}

int	render(t_map *map)
{	
	render_img(map);
	mlx_put_image_to_window(map);
	return (1);
}

