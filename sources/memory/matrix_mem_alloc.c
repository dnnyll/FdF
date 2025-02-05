/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mem_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:37:42 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/05 15:21:05 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	char_matrix_alloc(t_map *map)
{
	int	i;

	// ft_printf("Allocating memory - Width: %d, Height: %d\n", map->x, map->y);
	map->char_matrix_stash = malloc(sizeof(char *) * map->y);
	map->c_z_matrix = malloc(sizeof(char **) * map->y);
	map->c_colours_matrix = malloc(sizeof(char **) * map->y);
	if (!map->char_matrix_stash || !map->c_z_matrix || !map->c_colours_matrix)
	{
		ft_printf("Error: memory allocation failed\n");
		free_t_map(map);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->y)
	{
		map->char_matrix_stash[i] = NULL;
		map->c_z_matrix[i] = malloc(sizeof(char *) * map->x);
		map->c_colours_matrix[i] = malloc(sizeof(char *) * map->x);

		if (!map->c_z_matrix[i] || !map->c_colours_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d\n", i);
			// free_t_map(map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	// ft_printf("Memory allocation successful\n");
}

void	int_matrix_alloc(t_map *map)
{
	int	i;

	// ft_printf("Allocating memory - Width: %d, Height: %d\n", map->x, map->y);
	map->z_matrix = malloc(sizeof(int *) * map->y);
	map->colours_matrix = malloc(sizeof(int *) * map->y);
	if (!map->z_matrix || !map->colours_matrix)
	{
		ft_printf("Error: memory allocation failed\n");
		free_t_map(map);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->y)
	{
		map->z_matrix[i] = malloc(sizeof(int ) * map->x);
		map->colours_matrix[i] = malloc(sizeof(int ) * map->x);

		if (!map->z_matrix[i] || !map->colours_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d\n", i);
			free_t_map(map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	// ft_printf("Memory allocation successful\n");
}
