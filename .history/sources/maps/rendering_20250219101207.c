/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:02:50 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 10:12:07 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rendering (t_map *map)
{
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->x, map->y);
	map->buffer = mlx_get_data_addr(map->img_ptr, \
	&map->render->bpp, &map->render->size_line, &map->render->endian);
	
}