/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:26:48 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/14 08:29:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map_data(t_map *map, char **lines)
{
	ft_printf("Entering fill_map_data with lines = %p\n", (void *)lines);
	int		row;
	int		col;
	char	**values;
	
	row = 0;
	col = 0;
	while (row < map->height)
	{
		ft_printf("Converting values[%d] = %s to integer\n", col, values[col]);
		values = ft_split(lines[row], ' ');
		ft_printf("map->data[%d][%d] = %d\n", row, col, map->data[row][col]);
		ft_printf("Row %d: %s\n", row, lines[row]);
		while (col < map->width)
		{
			map->data[row][col] = ft_atoi(values[col]);
			col++;
		}
	free(values);
	row++;
	}
}
