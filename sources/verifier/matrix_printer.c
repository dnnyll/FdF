/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:00:10 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/17 11:13:03 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Function to print the 2D matrix of the map
void	print_map_matrix(t_map *map)
{
	ft_printf("Initiating map_matrix printing.\n");
	int	i = 0;
	while (i < map->height)
	{
		int	j = 0;
		while (j < map->width)
		{
			ft_printf("%c\t", map->data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("Printing completed.\n");
}

// Function to print the 2D matrix of colors
void	print_color_matrix(char ***color_stash, int height, int width)
{
	int	i = 0;
	while (i < height)
	{
		int	j = 0;
		while (j < width)
		{
			if (color_stash[i][j])
			{
				printf("%s\t", color_stash[i][j]);
			}
			else
			{
				printf("NULL\t");
			}
			j++;
		}
		printf("\n");
		i++;
	}
}
