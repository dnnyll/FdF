/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:12:20 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/26 19:55:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_file_check (t_map *map, int fd)
{
	if (fd < 0)
	{
		ft_printf("Error opening and reading file\n");
		free_t_map(map);
		close (fd);
		exit (EXIT_FAILURE);
	}
}

void	empty_check(t_map *map, int fd)
{
	if (map ->x == 0 && map->y == 0)
	{
		ft_printf("Error: Empty map!");
		stop_map_inconsist(map);
		close(fd);
		exit (EXIT_FAILURE);
	}
}

void	check_fdf_file(const char *filename, int fd)
{
	int len;
	
	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + (len - 4), ".fdf", 4) != 0)
	{
		ft_printf("Error: Invalid file format. Must be a .fdf file\n");
		close (fd);
		exit(EXIT_FAILURE);
	}
}
