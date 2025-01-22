/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:00:10 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/22 17:27:00 by daniefe2         ###   ########.fr       */
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

void print_char_stash_matrix(t_map *map)
{
	ft_printf("Initiating char_matrix_stash printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
//	ft_printf("i: %d, j: %d, height: %d, width: %d\n", i, j, map->height, map->width);
		while (j < map->width) {  // Iterating over columns
			// ft_printf("char_matrix_stash line: %s\n", map->char_matrix_stash[i]);
			ft_printf("%c", map->char_matrix_stash[i][j]);  // Print the integer
			if (j < map->width - 1)	// Avoid printing a tab after the last column
				ft_printf("\t");	// Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
}

void print_parts_values_matrix(t_map *map)
{
	ft_printf("Initiating parts_values matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			ft_printf("%s", map->parts_values[i][j]);  // Print the value
			if (j < map->width - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
}

void print_parts_colours_matrix(t_map *map)
{
	ft_printf("Initiating parts_colours matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			if (map->parts_colours[i][j])  // Check if there is a color
				ft_printf("%s", map->parts_colours[i][j]);  // Print the color
			else
				ft_printf("NULL");  // If no color, print NULL
			if (j < map->width - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
}

