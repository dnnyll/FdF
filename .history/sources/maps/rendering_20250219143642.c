/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:02:50 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 14:36:42 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_img(t_map *map)
{
	ft_printf("mlx_ptr: %p, win_width: %d, win_height: %d\n", map->mlx_ptr, \
	map->window->win_width, map->window->win_height);
	map->render->img_ptr = mlx_new_image(map->mlx_ptr, map->window->win_width, \
	map->window->win_height);
	if(!map->render->img_ptr)
	{
		ft_printf("NO IMG PTR");
		return ;
	}
	map->render->buffer = mlx_get_data_addr(map->render->img_ptr, \
	&map->render->bpp, &map->render->size_line, &map->render->endian);
	if (!map->render->buffer)
	{
		ft_printf("NO BUFFER");
		return ;
	}
	map->render->i = 0;
	while (map->render->i < map->y)
	{
		map->render->j = 0;
		while (map->render->j < map->x)
		{
			map->colour->current_colour = \
			map->colours_matrix[map->render->i][map->render->j];
			ft_printf("Setting pixel at (%d, %d) with color %d\n", map->render->i, map->render->j, map->colour->current_colour);
			put_pixel(map);
			map->render->j++;
		}
		map->render->i++;
	}
}

void	put_pixel(t_map *map)
{
	int	pixel_offset;
	printf("map->render->size_line: %d, map->render->bpp: %d\n", map->render->size_line, map->render->bpp);
	printf("buffer address: %p\n", map->render->buffer);

	pixel_index = (map->render->i * map->render->size_line) + \
	(map->render->j * (map->render->bpp / 8));
	printf("Pixel at (%d, %d): %d\n", map->render->i, map->render->j, map->colour->current_colour);
	*(unsigned int *)(map->render->buffer + pixel_index) = \
	map->colour->current_colour;
}


