/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:26:48 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/09 17:15:10 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map_data(t_map *map, char **lines)
{
	int		row;
	int		col;
	char	**values;
	
	row = 0;
	col = 0;
	while (row < map->height)
	{
		values = ft_split(lines[row], ' ');
		while (col < map->width)
		{
			map->data[row][col] = ft_atoi(values[col]);
			col++;
		}
	free(values[col]);
	row++;
	}
}
