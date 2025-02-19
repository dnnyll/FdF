/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:02:50 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 11:00:51 by daniefe2         ###   ########.fr       */
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
			put_pixel(map->render->buffer, map->colurs_matri[i][j], \
			map->window->win_width, map->window->win_height, \
			map->render->bpp, map->render->size_line);
			j++;
		}
		i++;
	}

}
// void	put_pixel(char *buffer, int x, int y, int color, int bpp, int size_line)
void	put_pixel(t_map *map)
{
	int	current_colour;
	int	pixel_index;

	pixel_index = (map->y * map->render->size_line) + \
	(map->x * (map->render->bpp / 8));
	*(unsigned int *)(map->render->buffer + pixel_index) = current_color;
		// map->render->pixel_address = map->render->image_buffer + \
	// (map->y * map->render->size_line) + (map->x (map->render->bpp / 8));
}
// int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img, int x, int y);
int	mlx_put_image_to_window(t_map *map)
{
	
}
int	render(t_map *map)
{

	render_img(map);
	mlx_put_image_to_window(map);
	
}

