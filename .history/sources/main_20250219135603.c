/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:35:37 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 13:56:03 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*file;
	
	if (argc != 2)
	{
		ft_printf("Error opening file");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	map = initialize_map();
	if (!map)
		exit (EXIT_FAILURE);
	read_map_size(map, file);
	read_map_repeat(map, file);
	matrix_converter(map);
	alloc_coordinates_grid(map); 
	malloc_rgb_grid(map);
	rgb_grid_populate(map);
	scaling_coordinates(map);
	alloc_conversion_grid(map);
	iso_conversion_grid(map);
	coordinates_shifting(map);
	map->mlx_ptr = mlx_init();
	// if (!map->mlx_ptr) 
	// {
	// 	ft_printf("MLX Initialization failed\n");
	// 	exit (0);
	// }
	map->window->win_ptr = mlx_new_window(map->window->mlx_ptr, map->window->win_width, 
	map->window->win_height, "FdF");
	mlx_key_hook(map->window->win_ptr, key_hook, map);
	ft_printf("0000\n");
	render_img(map);
	ft_printf("0001\n");
	bresenham(map);
	ft_printf("0002\n");
	mlx_put_image_to_window(map->mlx_ptr, map->window->win_ptr, map->render->img_ptr, 0 ,0);
	ft_printf("0003\n");
	// draw_grid(map->window->mlx_ptr, map->window->win_ptr, map);
	free_conversion_grid(map);
	free_colours_matrix(map);
	free_rgb_grid(map);
	free_coordinates_grid(map);
	mlx_hook(map->window->win_ptr, 17, 0, close_window, map);
	mlx_loop(map->window->mlx_ptr);
	return (0);
}
