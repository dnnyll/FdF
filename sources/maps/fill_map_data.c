/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:26:48 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/15 14:40:20 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map_data(t_map *map, const char *filename)
{
	int		fd;
	int		row;
	int		col;
	char	**values;

	row = 0;
//	col = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		free(map);
		exit(EXIT_FAILURE);
	}
	map->lines = allocate_map_data_char(map);
	values = allocate_map_data_char(map);

	while (row < map->height)
	{
		map->lines[row] = get_next_line(fd);
		ft_printf("in row < map->height loop\n");
		ft_printf("split begins here.\n");
		values = ft_split(map->lines[row], ' ');
		if(!values)
		{
			ft_printf("Error: ft_split failed on row %d\n", row);
			exit(EXIT_FAILURE);
		}
//		ft_printf("map->data[%d][%d] = %d\n", row, col, map->data[row][col]);
		ft_printf("Row %d: %s\n", row, map->lines[row]);
		col = 0;
		while (col < map->width)
		{
			ft_printf("Converting values[%d] = %s to integer\n", col, values[col]);
			map->data[row][col] = ft_atoi(values[col]);
			ft_printf("map->data[%d][%d] = %d\n", row, col, map->data[row][col]);
			col++;
		}
//		free(values);
		row++;
	}
}



