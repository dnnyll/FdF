/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:57:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/13 09:36:45 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hook(int keycode, void *param)
{
	t_map *map;

	map = (t_map *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);
		mlx_destroy_display(map->window->mlx_ptr);
		free (map->window->mlx_ptr);
		free_map_resources(map);  // Function to free other dynamically allocated structures
		ft_printf("ESC_KEY used successfully.\n");
		exit (0);
	}
	return (0);
}

int close_window(void *param)
{
	t_map *map;

	map = (t_map *)param;
	mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);
	mlx_destroy_display(map->window->mlx_ptr);
	free (map->window->mlx_ptr);
	free_map_resources(map);  // Function to free dynamically allocated resources
	ft_printf("Window manually closed.\n");
	exit (0);
}

