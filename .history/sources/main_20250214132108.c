/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:35:37 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/14 13:21:08 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	printf("hello");
	t_map	*map;
	char	*file;
	
	if (argc != 2)
	{
		ft_printf("Error opening file");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	map = initialize_map();
	printf("hello2");
	if (!map)
		exit (EXIT_FAILURE);
	read_map_size(map, file);
	read_map_repeat(map, file);
	matrix_converter(map);
	printf("hello3");
	alloc_coordinates_grid(map);
	malloc_rgb_grid(map);
	rgb_grid_populate(map);
	scaling_coordinates(map);
	alloc_conversion_grid(map);
	printf("hello4");
	iso_conversion_grid(map);
	coordinates_shifting(map);
	map->window->mlx_ptr = mlx_init();
	map->window->win_ptr = mlx_new_window(map->window->mlx_ptr, map->iso->window_width, 
	map->iso->window_height, "FdF");
	printf("hello");
	mlx_key_hook(map->window->win_ptr, key_hook, map);
	draw_grid(map->window->mlx_ptr, map->window->win_ptr, map);
	free_conversion_grid(map);
	free_colours_matrix(map);
	free_rgb_grid(map);
	free_coordinates_grid(map);
	mlx_hook(map->window->win_ptr, 17, 0, close_window, map);
	mlx_loop(map->window->mlx_ptr);
	return (0);
}
