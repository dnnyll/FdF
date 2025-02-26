/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:37:44 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/26 12:41:57 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map_ressources(t_map *map)
{
	if (!map)
		return ;
	free(map->iso);
	free(map->colour);
	free(map->window);
	free(map);
}

void	stop_map_inconsist(t_map *map)
{
	mlx_destroy_image(map->window->mlx_ptr, map->window->img_ptr);
	mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);
	mlx_destroy_display(map->window->mlx_ptr);
	free (map->window->mlx_ptr);
	free(map->iso);
	free(map->colour);
	free(map->window);
	free(map->line);
	free(map);
}
