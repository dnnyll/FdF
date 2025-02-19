/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:02:50 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 14:02:51 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_img(t_map *map)
{
	int	i;
	int	j;
	
	ft_printf("mlx_ptr: %p, win_width: %d, win_height: %d\n", map->mlx_ptr, map->window->win_width, map->window->win_height);
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
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			map->colour->current_colour = map->colours_matrix[i][j];
			put_pixel(map);
			j++;
		}
		i++;
	}
}

void	put_pixel(t_map *map)
{
	int	pixel_index;
	printf("map->y: %d, map->x: %d\n", map->y, map->x);
	printf("map->render->size_line: %d, map->render->bpp: %d\n", map->render->size_line, map->render->bpp);
	printf("buffer address: %p\n", map->render->buffer);

	pixel_index = (i_pix * map->render->size_line) + \
	(map->x * (map->render->bpp / 8));
	*(unsigned int *)(map->render->buffer + pixel_index) = \
	map->colour->current_colour;
}

// int	render(t_map *map)
// {	
// 	render_img(map);
// 	mlx_put_image_to_window(map->mlx_ptr, map->window->win_ptr, map->img_ptr, 0 ,0);
// 	return (1);
// }

