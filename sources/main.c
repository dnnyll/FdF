/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:35:37 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/26 13:07:22 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*file;
	int		fd;

	if (argc != 2)
		exit(EXIT_FAILURE);
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	close(fd);
	// check map is valid ()
	map = initialize_map();
	if (!map)
		exit (EXIT_FAILURE);
	operation_mlx(map);
	read_map_size(map, file);
	read_map_repeat(map, file);
	operation_launch(map);
	mlx_key_hook(map->window->win_ptr, key_hook, map);
	draw_grid(map->window->mlx_ptr, map->window->win_ptr, map);
	operation_free(map);
	mlx_hook(map->window->win_ptr, 17, 0, close_window, map);
	mlx_loop(map->window->mlx_ptr);
	return (0);
}
