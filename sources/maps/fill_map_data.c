/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:26:48 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/15 08:35:22 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	fill_map_data(t_map *map)
{
	int	fd;
	open()
}
// void	fill_map_data(t_map *map, char **lines)
// {
// 	ft_printf("Entering fill_map_data with lines = %p\n", (void *)lines);
// 	int		row;
// 	int		col;
// 	char	**values;

// 	row = 0;
// 	col = 0;
// 	ft_printf("height before loop: %d\n", map->height);
// 	// values = allocate_map_axis(map);
// 	// if (!values)
// 	// {
// 	// 	ft_printf("Error allocating memory for values\n");
// 	// 	exit(EXIT_FAILURE);
// 	// }
// 	// values = malloc((sizeof(char *) * map->width ) * map->height + 1);
// 	// if(!values)
// 	// {
// 	// 	ft_printf("Error allocating memory for values]n");
// 	// 	free (values);
// 	// 	exit (EXIT_FAILURE);
// 	// }
// 	lines = allocate_map_axis(map);
// 	if (!lines)
// 	{
// 		ft_printf("Error allocating memory for lines");
// 		exit(EXIT_FAILURE);
// 	}
// 	while (row < map->height)
// 	{
// 		ft_printf("split begins here\n");
// 		values = ft_split(lines[row], ' ');
// 		if(!values)
// 		{
// 			ft_printf("Error: ft_split failed on row %d\n", row);
// 			exit(EXIT_FAILURE);
// 		}
// 		ft_printf("map->data[%d][%d] = %d\n", row, col, map->data[row][col]);
// 		ft_printf("Row %d: %s\n", row, lines[row]);
// 		col = 0;
// 		while (col < map->width)
// 		{
// 			ft_printf("Converting values[%d] = %s to integer\n", col, values[col]);
// 			map->data[row][col] = ft_atoi(values[col]);
// 			ft_printf("map->data[%d][%d] = %d\n", row, col, map->data[row][col]);
// 			col++;
// 		}
// 	free(values);
// 	row++;
// 	}
// }
