/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:02:50 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 10:10:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rendering (t_map *map)
{
	map->img_ptr = mlx_new_image(map->mlx_ptr, map->x, map->y);
	map->buffer = mlx_get_data_addr(map->render->img_ptr, \
	&map->render->bpp, &map->size_line, &map->endian);
	
}