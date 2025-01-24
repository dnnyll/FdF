/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:00:10 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 13:03:33 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_char_values_matrix(t_map *map)
{
	ft_printf("Initiating parts_values matrix printing.\n");
	int index = 0;
	while (index < map->y) {  // Iterating over rows
		int jndex = 0;
		while (jndex < map->x) {  // Iterating over columns
			ft_printf("%s", map->c_z_matrix[index][jndex]);  // Print the value
			if (jndex < map->x - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			jndex++;
		}
		ft_printf("\n");  // Move to the next line after each row
		index++;
	}
	ft_printf("Printing completed.\n");
}

void print_char_colours_matrix(t_map *map)
{
	ft_printf("Initiating parts_colours matrix printing.\n");
	int index = 0;
	while (index < map->y)
	{
		int jndex = 0;
		while (jndex < map->x)
		{
			if (map->c_colours_matrix[index][jndex])
				ft_printf("%s", map->c_colours_matrix[index][jndex]);
			else
				ft_printf("NULL");
			if (jndex < map->x - 1)
				ft_printf("\t");
			jndex++;
		}
		ft_printf("\n");
		index++;
	}
	ft_printf("Printing completed.\n");
}

void print_int_values_matrix(t_map *map)
{
	ft_printf("Initiating z_matrix printing.\n");
	int index = 0;
	while (index < map->y) {  // Iterating over rows
		int jndex = 0;
		while (jndex < map->x) {  // Iterating over columns
			ft_printf("%d", map->z_matrix[index][jndex]);  // Print the value
			if (jndex < map->x - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			jndex++;
		}
		ft_printf("\n");  // Move to the next line after each row
		index++;
	}
	ft_printf("Printing completed.\n");
}

void print_int_colours_matrix(t_map *map)
{
	ft_printf("Initiating colours_matrix printing.\n");
	int index = 0;
	while (index < map->y) {  // Iterating over rows
		int jndex = 0;
		while (jndex < map->x) {  // Iterating over columns
			if (map->colours_matrix[index][jndex])  // Check if there is a color
				ft_printf("%d", map->colours_matrix[index][jndex]);  // Print the color
			else
				ft_printf("NULL");  // If no color, print NULL
			if (jndex < map->x - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			jndex++;
		}
		ft_printf("\n");  // Move to the next line after each row
		index++;
	}
	ft_printf("Printing completed.\n");
	ft_printf("PS: Hey YOU, remember you have set 0x00FF41 (65345) as your default colour!!!!\n");
}
