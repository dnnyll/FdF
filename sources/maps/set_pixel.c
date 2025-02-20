/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:15:25 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/20 16:48:42 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_map * map, int current_colour)
{
	// ft_printf("current colour: %d\n", current_colour);
	*(int *) (map->buffer + (int) map->iso->y1 * map->size_line + (int) map->iso->x1 * (map->bpp / 8)) = current_colour;
	// ft_printf("current_colour: %d\n", current_colour);
}