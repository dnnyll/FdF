/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:57:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 09:46:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

{
	t_map	*map;

	map = (t_map *)param;
	if (!map || !map->window)  // Prevent NULL dereference
		return (0);

	if (keycode == KEY_ESC)
	{
		if (map->window->mlx_ptr && map->window->win_ptr)
			mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);

		if (map->window->mlx_ptr)
			mlx_destroy_display(map->window->mlx_ptr);

		free_map_resources(map);
		ft_printf("ESC_KEY used successfully.\n");
	}
	return (0);
}

int	close_window(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (!map || !map->window)  // Prevent NULL dereference
		return (0);

	if (map->window->mlx_ptr && map->window->win_ptr)
		mlx_destroy_window(map->window->mlx_ptr, map->window



// #include "fdf.h"

// int	key_hook(int keycode, void *param)
// {
// 	t_map	*map;

// 	map = (t_map *)param;
// 	if (keycode == KEY_ESC)
// 	{
// 		mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);
// 		mlx_destroy_display(map->window->mlx_ptr);
// 		free (map->window->mlx_ptr);
// 		free_map_resources(map);
// 		ft_printf("ESC_KEY used successfully.\n");
// 	}
// 	return (0);
// }

// int	close_window(void *param)
// {
// 	t_map	*map;

// 	map = (t_map *)param;
// 	mlx_destroy_window(map->window->mlx_ptr, map->window->win_ptr);
// 	mlx_destroy_display(map->window->mlx_ptr);
// 	free (map->window->mlx_ptr);
// 	free_map_resources(map);
// 	ft_printf("Window manually closed.\n");
// 	return (0);
// }
