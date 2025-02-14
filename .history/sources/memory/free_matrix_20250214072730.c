/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:26:46 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/14 07:27:30 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_t_map(t_map *map)
{
	if (map->line)
		free(map->line);
	if (map->char_matrix_stash)
		free_char_matrix_stash(map);
	if (map->z_matrix)
		free_z_matrix(map);
	if	(map->colours_matrix)
		free_colours_matrix(map);
	if (map->c_z_matrix)
		free_c_z_matrix(map);
	if (map->c_colours_matrix)
		free_c_colours_matrix(map);
	if (map->z_matrix)	
		free_z_matrix(map);
	if (map->conversion_grid)
		free_conversion_grid(map);
	if (map->colour->rgb_grid)
		free_rgb_grid(map);
	if (map->coordinates_grid)
		free_coordinates_grid(map);
	free(map);
}

void free_char_matrix_stash(t_map *map)
{
	int i = 0;
	while (i < map->y && map->char_matrix_stash[i])
	{
		ft_printf("Freeing char_matrix_stash row %d: %p\n", i, map->char_matrix_stash[i]);
		free(map->char_matrix_stash[i]);
		map->char_matrix_stash[i] = NULL;
		i++;
	}
	free(map->char_matrix_stash);
	map->char_matrix_stash = NULL;
}

void	free_c_z_matrix(t_map *map)
{
	int row;
	int	col;
	
	row = 0;
	if (!map->c_z_matrix)
	{
		return ;
	}
	while (row < map->y)
		{
			col = 0;
			while (col < map->x)
			{
				ft_printf("Freeing c_z_matrix[%d][%d]: %p\n", i, j, map->c_z_matrix[i][j]);
				free(map->c_z_matrix[i][j]);
				j++;
			}
			free(map->c_z_matrix[i]);
			i++;
		}
		free(map->c_z_matrix);
	}
}
void	free_c_colours_matrix(t_map *map)
{
	int i;
	int j;

	i = 0;
	if (map->c_colours_matrix)
	{
		while (i < map->y)
		{
			if (map->c_colours_matrix[i])
			{
				j = 0;
				while (j < map->x)
				{
					if (map->c_colours_matrix[i][j])
						free(map->c_colours_matrix[i][j]);
					j++;
				}
				free(map->c_colours_matrix[i]);
			}
			i++;
		}
		free(map->c_colours_matrix);
	}
}


void free_z_matrix(t_map *map)
{
	int i;

	i = 0;
	if (map->z_matrix)
	{
		while (i < map->y)
		{
			if (map->z_matrix[i])
			{
				ft_printf("Freeing z_matrix row %d: %p\n", i, map->z_matrix[i]);
				free(map->z_matrix[i]);
			}
		i++;
		}
		free(map->z_matrix);
		map->z_matrix = NULL;
	}
}



void	free_colours_matrix(t_map *map)
{
	int	i;

	i = 0;
	if (map->colours_matrix)
	{
		while (i < map->y)
		{
			ft_printf("Freeing colours_matrix row %d: %p\n", i, map->colours_matrix[i]);
			free(map->colours_matrix[i]);
			map->colours_matrix[i] = NULL;
			i++;
		}
		free(map->colours_matrix);
		map->colours_matrix = NULL;
	}
}

void	free_conversion_grid(t_map *map)
{
	int	i;
	
	i = 0;
	if (map->conversion_grid)
	{
		while (i < map->y && map->conversion_grid[i])
		{
			ft_printf("Freeing conversion_grid row %d: %p\n", i, map->conversion_grid[i]);
			free(map->conversion_grid[i]);
			map->conversion_grid[i] = NULL;
			i++;
		}
		free(map->conversion_grid);
		map->conversion_grid = NULL;
	}
}
void	free_rgb_grid(t_map *map)
{
	int	i;
	
	i = 0;
	if (map->colour->rgb_grid)
	{
		while (i < map->y && map->colour->rgb_grid[i])
		{
			ft_printf("Freeing rgb_grid row %d: %p\n", i, map->colour->rgb_grid[i]);
			free(map->colour->rgb_grid[i]);
			map->colour->rgb_grid[i] = NULL;
			i++;
		}
		free(map->colour->rgb_grid);
		map->colour->rgb_grid = NULL;
	}
}

void	free_coordinates_grid(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	if (!map->coordinates_grid)
	{
		ft_printf("No memory to free for coordinates_grid.\n");
		return;
	}
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			printf("Freeing coordinates_grid[%d][%d] at %p\n", row, col, (void *)map->coordinates_grid[row][col]);
			free(map->coordinates_grid[row][col]);
			col++;
		}
		printf("Freeing coordinates_grid[%d] at %p\n", row, (void *)map->coordinates_grid[row]);
		free(map->coordinates_grid[row]);
		row++;
	}
	printf("Freeing coordinates_grid at %p\n", (void *)map->coordinates_grid);
	free (map->coordinates_grid);
}

// void free_coordinates_grid(t_map *map)
// {
// 	int row;
// 	int col;
	
// 	if (!map->coordinates_grid)
// 		return;
// 	row = 0;
// 	while (row < map->y)
// 	{
// 		if (!map->coordinates_grid[row])
// 		{
// 			row++;
// 				continue;
// 		}
// 		col = 0;
// 		while (col < map->x)
// 		{
// 		free(map->coordinates_grid[row][col]);
// 		col++;
// 		}
// 		free(map->coordinates_grid[row]);
// 		row++;
// 	}
// 	free(map->coordinates_grid);
// }
