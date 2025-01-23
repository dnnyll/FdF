/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:00:10 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/23 11:05:25 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_char_values_matrix(t_map *map)
{
	ft_printf("Initiating parts_values matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			ft_printf("%s", map->c_parts_values[i][j]);  // Print the value
			if (j < map->width - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
}

void print_char_colours_matrix(t_map *map)
{
	ft_printf("Initiating parts_colours matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			if (map->c_parts_colours[i][j])  // Check if there is a color
				ft_printf("%s", map->c_parts_colours[i][j]);  // Print the color
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

void print_int_values_matrix(t_map *map)
{
	ft_printf("Initiating values_matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			ft_printf("%d", map->values_matrix[i][j]);  // Print the value
			if (j < map->width - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
}

void print_int_colours_matrix(t_map *map)
{
	ft_printf("Initiating colours_matrix printing.\n");
	int i = 0;
	while (i < map->height) {  // Iterating over rows
		int j = 0;
		while (j < map->width) {  // Iterating over columns
			if (map->colours_matrix[i][j])  // Check if there is a color
				ft_printf("%d", map->colours_matrix[i][j]);  // Print the color
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
	ft_printf("PS: Hey YOU, remember you have set 0x00FF41 (65345) as your default colour!!!!");
}
