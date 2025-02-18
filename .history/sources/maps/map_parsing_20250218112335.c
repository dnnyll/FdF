/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:08:55 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 11:23:35 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_map_lines(t_map *map, int fd)
{
	int i = 0;

	while (i < map->y)
	{
		map->line = get_next_line(fd);
		if (!map->line)
		{
			ft_printf("Error: no line\n");
			while (i-- > 0)  // Free previous lines
				free(map->char_matrix_stash[i]);
			free(map->char_matrix_stash);
			map->char_matrix_stash = NULL;
			return;
		}
		map->char_matrix_stash[i] = ft_strdup(map->line);
		ft_printf("Stored line %d at %p\n", i, map->char_matrix_stash[i]);
		free(map->line);
		i++;
	}
}

// void	store_map_lines(t_map *map, int fd)
// {
// 	int		i;

// 	i = 0;
// 	while (i < map->y)
// 	{
// 		map->line = get_next_line(fd);
// 		if (!map->line)
// 		{
// 			ft_printf("Error: no line\n");
// 			free(map->line);
// 			return;
// 		}
// 		map->char_matrix_stash[i] = ft_strdup(map->line);
// 		free(map->line);
// 		i++;
// 	}
// }

void	process_lines(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		map->c_z_matrix[row] = ft_split(map->char_matrix_stash[row], ' ');
		if (!map->c_z_matrix[row])
		{
			ft_printf("Error: no row content\n");
			free_c_z_matrix(map);
			return;
		}
		while (map->c_z_matrix[row][col])
		{
			process_parts(map, row, col);
			col++;
		}
		row++;
	}
}

void process_parts(t_map *map, int row, int col)
{
	char *value_element;
	char *comma_pos;

	value_element = map->c_z_matrix[row][col];
	comma_pos = ft_strchr(value_element, ',');
	if (comma_pos)
	{
		*comma_pos = '\0';
		if (map->c_colours_matrix[row][col])
			free(map->c_colours_matrix[row][col]);
		map->c_colours_matrix[row][col] = ft_strdup(comma_pos + 1);
	}
	else
	{
		if (map->c_colours_matrix[row][col])
			free(map->c_colours_matrix[row][col]);
		map->c_colours_matrix[row][col] = NULL;
	}
	map->c_z_matrix[row][col] = ft_strdup(value_element);
}

void	read_map_repeat(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening and reading file\n");
		return;
	}
	alloc_char_matrix_stash(map);
	char_matrix_alloc(map);
	store_map_lines(map, fd);
	process_lines(map);
	free_char_matrix_stash(map);
	close(fd);
	print_c_z_matrix(map);
}
