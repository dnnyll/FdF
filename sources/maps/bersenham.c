/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:36:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/01 11:49:42 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_direction(t_map *map)
{
	map->iso->dif_x = map->iso->x2 - map->iso->x1;
	if (map->iso->dif_x < 0)
		map->iso->dif_x = -map->iso->dif_x;
	map->iso->dif_y = map->iso->y2 - map->iso->y1;
	if (map->iso->dif_y < 0)
		map->iso->dif_y = -map->iso->dif_y;
	map->iso->step_drct_x = -1;
	map->iso->step_drct_y = -1;
	if (map->iso->x1 < map->iso->x2)
		map->iso->step_drct_x = 1;
	if (map->iso->y1 < map->iso->y2)
		map->iso->step_drct_y = 1;
	map->iso->err = map->iso->dif_x - map->iso->dif_y;
}

int	validate_and_set_pixel(t_map *map, int current_colour)
{
	if (map->iso->x1 < 0 || map->iso->x1 >= map->window->width || \
		map->iso->y1 < 0 || map->iso->y1 >= map->window->height)
		return (0);
	if (map->colour->x_colour_grid >= map->x || \
	map->colour->y_colour_grid >= map->y)
		return (0);
	if (map->colour->x_colour_grid < 0)
		map->colour->x_colour_grid = 0;
	else if (map->colour->x_colour_grid >= map->x)
		map->colour->x_colour_grid = map->x - 1;
	if (map->colour->y_colour_grid < 0)
		map->colour->y_colour_grid = 0;
	else if (map->colour->y_colour_grid >= map->y)
		map->colour->y_colour_grid = map->y - 1;
	set_pixel(map, current_colour);
	return (1);
}

void	draw_line(void *mlx, void *win, t_map *map, int current_colour)
{
	(void)mlx;
	(void)win;
	setup_direction(map);
	while (1)
	{
		if (!validate_and_set_pixel(map, current_colour))
			break ;
		if (dif_check(map->iso->x1, map->iso->x2, map->epsilon) && \
			dif_check(map->iso->y1, map->iso->y2, map->epsilon))
			break ;
		map->iso->temp_err = 2 * map->iso->err;
		if (map->iso->temp_err > -map->iso->dif_y)
		{
			map->iso->err -= map->iso->dif_y;
			map->iso->x1 += map->iso->step_drct_x;
		}
		if (map->iso->temp_err < map->iso->dif_x)
		{
			map->iso->err += map->iso->dif_x;
			map->iso->y1 += map->iso->step_drct_y;
		}
	}
}

int	dif_check(double a, double b, double epsilon)
{
	return (fabs(a - b) < epsilon);
}
