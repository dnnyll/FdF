/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_int_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:37:42 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/14 12:51:58 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	alloc_z_matrix(t_map *map)
{
	map->z_matrix = malloc(sizeof(int *) * map->y);
	if (!map->z_matrix)
	{
		ft_printf("Error: memory allocation failed for z_matrix\n");
		return 0;
	}

	int i = 0;
	while (i < map->y)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->x);
		if (!map->z_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d for z_matrix\n", i);
			free_z_matrix(map);  // Free previously allocated memory
			return 0;
		}
		i++;
	}
	return 1;  // Successful allocation
}

int	alloc_colours_matrix(t_map *map)
{
	map->colours_matrix = malloc(sizeof(int *) * map->y);
	if (!map->colours_matrix)
	{
		ft_printf("Error: memory allocation failed for colours_matrix\n");
		return 0;
	}

	int	i;
	
	i = 0;
	while (i < map->y)
	{
		map->colours_matrix[i] = malloc(sizeof(int) * map->x);
		if (!map->colours_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d for colours_matrix\n", i);
			free_colours_matrix(map);  // Free previously allocated memory
			return 0;
		}
		i++;
	}
	return 1;  // Successful allocation
}

void	int_matrix_alloc(t_map *map)
{
	if (!alloc_z_matrix(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);  // Exit on failure
	}

	if (!alloc_colours_matrix(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);  // Exit on failure
	}
}
