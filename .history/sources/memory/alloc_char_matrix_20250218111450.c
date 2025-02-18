/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_char_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:36:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 11:14:50 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	alloc_char_matrix_stash(t_map *map)
{
	if (map->char_matrix_stash) // Prevent leak from previous allocation
	{
		ft_printf("WARNING: char_matrix_stash was already allocated at %p!\n", (void*)map->char_matrix_stash);	
		free_char_matrix_stash(map);
	}
	map->char_matrix_stash = malloc(sizeof(char *) * map->y);
	if (!map->char_matrix_stash)
	{
		        ft_printf("Error: memory allocation failed for char_matrix_stash\n");
		return (0);
	
	int row = 0;
	while (row < map->y)
	{
		map->char_matrix_stash[row] = NULL; // Initialize to NULL for safety
		row++;
	}
	return (1);
}

// int alloc_char_matrix_stash(t_map *map)
// {
//     map->char_matrix_stash = malloc(sizeof(char *) * map->y);
//     if (!map->char_matrix_stash)
//     {
//         ft_printf("Error: memory allocation failed for char_matrix_stash\n");
//         return 0;
//     }

//     int i = 0;
//     while (i < map->y)
//     {
//         map->char_matrix_stash[i] = NULL; // Initialize NULL to track unallocated rows
//         ft_printf("Allocated row pointer %d at %p\n", i, &map->char_matrix_stash[i]);
//         i++;
//     }
//     return 1;  
// }

// int	alloc_char_matrix_stash(t_map *map)
// {
// 	int	i;
	
// 	map->char_matrix_stash = malloc(sizeof(char *) * map->y);
// 	if (!map->char_matrix_stash)
// 	{
// 		ft_printf("Error: memory allocation failed for char_matrix_stash\n");
// 		return (0);
// 	}
		
// 	i = 0;
// 	while (i < map->y)
// 	{
// 		map->char_matrix_stash[i] = malloc(sizeof(char *) *map->x);
// 		if (!map->char_matrix_stash[i])
// 		{
// 			ft_printf("Error: memory allocation failed for row %d\n", i);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int alloc_c_z_matrix(t_map *map)
{
    map->c_z_matrix = (char ***)malloc(sizeof(char *) * map->y);
    if (!map->c_z_matrix)
    {
        ft_printf("Memory allocation for c_z_matrix failed\n");
        exit(0);
    }

    int row = 0;
    while (row < map->y)
    {
        map->c_z_matrix[row] = NULL;  // Initialize each row to NULL
        row++;
    }
	return 1;
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
		map->c_colours_matrix[i] = malloc(sizeof(char **) * map->x);  // FIXED: Allocate `char **` instead of `char *`
		if (!map->c_colours_matrix[i])
		{
			ft_printf("Error: memory allocation failed at row %d for c_colours_matrix\n", i);
			free_c_colours_matrix(map);  // Free previously allocated memory
			return 0;
		}

		// Initialize all columns to NULL (to prevent freeing uninitialized pointers)
		int j = 0;
		while (j < map->x)
		{
			map->c_colours_matrix[i][j] = NULL;
			j++;
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

