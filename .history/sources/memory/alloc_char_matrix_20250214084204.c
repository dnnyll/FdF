/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_char_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:36:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/14 08:42:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	alloc_char_matrix_stash(t_map *map)
{
	map->char_matrix_stash = malloc(sizeof(char *) * map->y);
	if (!map->char_matrix_stash)
	{
		ft_printf("Error: memory allocation failed for char_matrix_stash\n");
		return 0;
	}
		
	int i = 0;
	while (i < map->y)
	{
		map->char_matrix_stash[i] = NULL;
		i++;
	}
	return 1;  // Successful allocation
}

int	alloc_c_z_matrix(t_map *map)
{
	map->c_z_matrix = malloc(sizeof(char **) * map->y);
	if (!map->c_z_matrix)
	{
		ft_printf("Error: memory allocation failed for c_z_matrix\n");
		return 0;
	}

	int i = 0;
	while (i < map->y)
	{
		map->c_z_matrix[i] = malloc(sizeof(char *) * map->x);
		if (!map->c_z_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d for c_z_matrix\n", i);
			// Free only the rows that were allocated before the failure
			while (--i >= 0)
				free(map->c_z_matrix[i]);
			free(map->c_z_matrix);
			map->c_z_matrix = NULL;
		}
		i++;
	}
	return (1);  // Successful allocation
}

int	alloc_c_colours_matrix(t_map *map)
{
	map->c_colours_matrix = malloc(sizeof(char **) * map->y);
	if (!map->c_colours_matrix)
	{
		ft_printf("Error: memory allocation failed for c_colours_matrix\n");
		return 0;
	}

	int i = 0;
	while (i < map->y)
	{
		map->c_colours_matrix[i] = malloc(sizeof(char *) * map->x);
		if (!map->c_colours_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d for c_colours_matrix\n", i);
			free_c_colours_matrix(map);  // Free previously allocated memory
			return 0;
		}
		i++;
	}
	return 1;  // Successful allocation
}

void	char_matrix_alloc(t_map *map)
{
	if (!alloc_char_matrix_stash(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);  // Exit on failure
	}

	if (!alloc_c_z_matrix(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);  // Exit on failure
	}

	if (!alloc_c_colours_matrix(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);  // Exit on failure
	}
}

