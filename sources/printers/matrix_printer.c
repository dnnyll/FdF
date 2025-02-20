/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:00:10 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/20 18:30:58 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_char_values_matrix(t_map *map)
{
	ft_printf("Initiating parts_values matrix printing.\n");
	int i = 0;
	while (i < map->y)
	{
		int j = 0;
		while (j < map->x) {  // Iterating over columns
			ft_printf("%s", map->c_z_matrix[i][j]);  // Print the value
			if (j < map->x - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
}

void print_c_z_matrix(t_map *map)
{
	ft_printf("Initiating parts_z matrix printing.\n");
	int i = 0;
	while (i < map->y)
	{
		int j = 0;
		while (j < map->x)
		{
			if (map->c_z_matrix[i][j])
				ft_printf("%s", map->c_z_matrix[i][j]);
			else
				ft_printf("NULL");
			if (j < map->x - 1)
				ft_printf("\t");
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("Printing completed.\n");
}

void print_char_colours_matrix(t_map *map)
{
	ft_printf("Initiating parts_colours matrix printing.\n");
	int i = 0;
	while (i < map->y)
	{
		int j = 0;
		while (j < map->x)
		{
			if (map->c_colours_matrix[i][j])
				ft_printf("%s", map->c_colours_matrix[i][j]);
			else
				ft_printf("NULL");
			if (j < map->x - 1)
				ft_printf("\t");
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("Printing completed.\n");
}

void print_int_values_matrix(t_map *map)
{
	ft_printf("Initiating z_matrix printing.\n");
	int i = 0;
	while (i < map->y) {  // Iterating over rows
		int j = 0;
		while (j < map->x) {  // Iterating over columns
			ft_printf("%d", map->z_matrix[i][j]);  // Print the value
			if (j < map->x - 1)  // Avoid printing a tab after the last column
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
	while (i < map->y) {  // Iterating over rows
		int j = 0;
		while (j < map->x) {  // Iterating over columns
			if (map->colours_matrix[i][j])  // Check if there is a color
				ft_printf("%d", map->colours_matrix[i][j]);  // Print the color
			else
				ft_printf("NULL");  // If no color, print NULL
			if (j < map->x - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
	ft_printf("Printing completed.\n");
	ft_printf("PS: Hey YOU, remember you have set 0x00FF41 (65345) as your default colour!!!!\n");
}

void print_coordinates_grid(t_map *map)
{
	ft_printf("Initiating coordinates_grid matrix printing.\n");

	int row = 0;
	while (row < map->y) // Iterating over rows
	{
		int col = 0;
		while (col < map->x) // Iterating over columns
		{
			// Access and print [x, y, z] for each coordinate
			ft_printf("[x: %d, y: %d, z: %d]", 
				map->coordinates_grid[row][col][0], // x-coordinate
				map->coordinates_grid[row][col][1], // y-coordinate
				map->coordinates_grid[row][col][2]  // z-coordinate
			);
			if (col < map->x - 1) // Add a tab unless it's the last column in the row
				ft_printf("\t");

			col++;
		}
		ft_printf("\n"); // Move to the next line after each row
		row++;
	}
	ft_printf("Printing completed.\n");
}
void	print_conversion_grid(t_map *map)
{
	printf("Initiating conversion_grid printing.\n");
	int row = 0;
	while (row < map->y)
	{
		int col = 0;
		while (col < map->x)
		{
			printf("%f\t", map->conversion_grid[row][col * 2]);
			printf("%f\t", map->conversion_grid[row][col * 2 + 1]);
			if (col < map->x - 1)
				printf("\t");
			col++;
		}
		printf("\n");
		row++;
	}
	printf("Printing completed.\n");
}

void print_rgb_grid(t_map *map)
{
	ft_printf("Initiating rgb_grid printing.\n");
	int i = 0;
	while (i < map->y) {  // Iterating over rows
		int j = 0;
		while (j < map->x) {  // Iterating over columns
			if (map->colour->rgb_grid[i][j])  // Check if there is a color
				ft_printf("%d", map->colour->rgb_grid[i][j]);  // Print the color
			else
				ft_printf("NULL");  // If no color, print NULL
			if (j < map->x - 1)  // Avoid printing a tab after the last column
				ft_printf("\t");  // Print tab after each element except the last in a row
			j++;
		}
		ft_printf("\n");  // Move to the next line after each row
		i++;
	}
}