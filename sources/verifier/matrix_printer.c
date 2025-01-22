/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:00:10 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/22 10:16:51 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_z_matrix(t_map *map)
{
	ft_printf("Initiating z_matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
//	ft_printf("i: %d, j: %d, height: %d, width: %d\n", i, j, map->height, map->width);
		while (j < map->width) {  // Iterating over columns
			ft_printf("%d", map->z_matrix[i][j]);  // Print the integer
			if (j < map->width - 1) {  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			}
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
}
