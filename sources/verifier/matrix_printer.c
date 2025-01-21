/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:00:10 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/17 20:36:29 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Here you can find 2 printers for char or int matrix

void print_char_map_matrix(t_map *map) {
	ft_printf("Initiating map_matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			ft_printf("%c", map->data[i][j]);  // Print the character
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

#include <stdio.h>

typedef struct {
	int height;
	int width;
	int **data;  // Assuming an int matrix
} t_map;

void print_int_map_matrix(t_map *map) {
	ft_printf("Initiating map_matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			ft_printf("%d", map->data[i][j]);  // Print the integer
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
