/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:57:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/10 08:59:30 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hook(int keycode, void *param)
{
	t_map *map;
	map = (t_map *)param;

	printf("Keycode: %d\n", keycode); // Debug message for keycode
	if (keycode == KEY_W)
	{
		printf("KEY_W used successfully.");
	}
	else if (keycode == KEY_S)
	{
		printf("KEY_S used successfully.");
	}
	else if (keycode == KEY_A)
	{
		printf("KEY_A used successfully.");
	}
	else if (keycode == KEY_D)
	{
		printf("KEY_D used successfully.");
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);
		printf("ESC_KEY used successfully.");
		exit (0);
	}
	return (0);
}
int	close_window(void *param)
{
	t_map *map;

	map = (t_map *)param;
	mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);
	printf("Window manually closed.\n");
	exit(0);
}
