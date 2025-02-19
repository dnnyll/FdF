/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_char_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:36:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 10:00:13 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	alloc_char_matrix_stash(t_map *map)
{
	int	row;

	if (map->char_matrix_stash)
		free_char_matrix_stash(map);
	map->char_matrix_stash = malloc(sizeof(char *) * map->y);
	if (!map->char_matrix_stash)
	{
		ft_printf("Error: memory allocation failed for char_matrix_stash\n");
		return (0);
	}
	ft_printf("Allocated char_matrix_stash at \
	%p\n", (void *)map->char_matrix_stash);
	row = 0;
	while (row < map->y)
	{
		map->char_matrix_stash[row] = NULL;
		row++;
	}
	return (1);
}

int	alloc_c_z_matrix(t_map *map)
{
	int	row;

	map->c_z_matrix = (char ***)malloc(sizeof(char *) * map->y);
	if (!map->c_z_matrix)
	{
		ft_printf("Memory allocation for c_z_matrix failed\n");
		return (0);
	}
	row = 0;
	while (row < map->y)
	{
		map->c_z_matrix[row] = NULL;
		row++;
	}
	return (1);
}

int	alloc_c_colours_matrix(t_map *map)
{
	int	i;
	int	j;

	map->c_colours_matrix = malloc(sizeof(char **) * map->y);
	if (!map->c_colours_matrix)
	{
		return (0);
	}
	i = 0;
	while (i < map->y)
	{
		map->c_colours_matrix[i] = malloc(sizeof(char **) * map->x);
		if (!map->c_colours_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row \
			%d for c_colours_matrix\n", i);
			free_c_colours_matrix(map);
			return (0);
		}
		j = 0;
		while (j < map->x)
		{
			map->c_colours_matrix[i][j] = NULL;
			j++;
		}
		i++;
	}
	return (1);
}

void	char_matrix_alloc(t_map *map)
{
	if (!alloc_char_matrix_stash(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);
	}
	if (!alloc_c_z_matrix(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);
	}
	if (!alloc_c_colours_matrix(map))
	{
		free_t_map(map);
		exit(EXIT_FAILURE);
	}
}
