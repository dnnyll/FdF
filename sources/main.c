/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:35:37 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/24 09:19:41 by daniefe2         ###   ########.fr       */
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
	map->window->mlx_ptr = mlx_init();
	map->window->win_ptr = mlx_new_window(map->window->mlx_ptr, map->window->width, map->window->height, "FdF");
	map->window->img_ptr = mlx_new_image(map->window->mlx_ptr, map->window->width, map->window->height);
	map->buffer = mlx_get_data_addr(map->window->img_ptr, &map->bpp, &map->size_line, &map->endian);
	read_map_size(map, file);
	read_map_repeat(map, file);
	matrix_converter(map);
	alloc_coordinates_grid(map); 
	scaling_coordinates(map);
	alloc_conversion_grid(map);
	iso_conversion_grid(map);
	coordinates_shifting(map);
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
