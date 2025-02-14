/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:08:55 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/14 10:17:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_map_lines(t_map *map, int fd)
{
	int index = 0;

	while (index < map->y)
	{
		map->line = get_next_line(fd);
		if (!map->line)
		{
			ft_printf("Error: no line\n");
			while (index-- > 0)  // Free previous lines
				free(map->char_matrix_stash[index]);
			free(map->char_matrix_stash);
			map->char_matrix_stash = NULL;
			return;
		}
		map->char_matrix_stash[index] = ft_strdup(map->line);
		free(map->line);
		index++;
	}
}
void	free_c_z_matrix(t_map *map)
{
	int i, j;

	// Check if the matrix exists
	if (map->c_z_matrix)
	{
		i = 0;
		// Loop through the first level (rows)
		while (i < map->y)
		{
			if (map->c_z_matrix[i])  // Ensure the row exists
			{
				j = 0;
				// Loop through the second level (columns) for each row
				while (j < map->x)
				{
					if (map->c_z_matrix[i][j])  // Ensure the sub-array exists
					{
						free(map->c_z_matrix[i][j]);  // Free the deepest level (3rd dimension)
					}
					j++;
				}
				free(map->c_z_matrix[i]);  // Free the row (2nd dimension)
			}
			i++;
		}
		// Free the top-level array (1st dimension)
		free(map->c_z_matrix);
		map->c_z_matrix = NULL;  // Set to NULL to avoid dangling pointer
	}
}

// void	store_map_lines(t_map *map, int fd)
// {
// 	int		index;

// 	index = 0;
// 	while (index < map->y)
// 	{
// 		map->line = get_next_line(fd);
// 		if (!map->line)
// 		{
// 			ft_printf("Error: no line\n");
// 			free(map->line);
// 			return;
// 		}
// 		map->char_matrix_stash[index] = ft_strdup(map->line);
// 		free(map->line);
// 		index++;
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

void	process_parts(t_map *map, int row, int col)
{
	char	*value_element;
	char	*comma_pos;

	value_element = map->c_z_matrix[row][col];
	comma_pos = ft_strchr(value_element, ',');
	if (comma_pos)
	{
		*comma_pos = '\0';	
		map->c_colours_matrix[row][col] = ft_strdup(comma_pos + 1);
	}
	else
		map->c_colours_matrix[row][col] = NULL;
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
	// alloc_char_matrix_stash(map);
	char_matrix_alloc(map);
	store_map_lines(map, fd);
	process_lines(map);
	free_char_matrix_stash(map);
	close(fd);
}
