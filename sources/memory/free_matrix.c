/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:26:46 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 15:41:41 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void free_c_z_matrix(t_map *map)
{
	int i;
	int	j;
	
	i = 0;
	if (map->c_z_matrix)
	{
		while (map->c_z_matrix[i])
		{
			j = 0;
			while (map->c_z_matrix[i][j])
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
	int	i;
	int	j;

	i = 0;
	if (map->c_colours_matrix[i])
	{
		while (map->c_colours_matrix[i])
		{
			j = 0;
			while (j < map->x)
			{
				if (map->c_colours_matrix[i][j])
				{
					ft_printf("Freeing c_colours_matrix[%d][%d]: %p\n", i, j, map->c_colours_matrix[i][j]);
					free(map->c_colours_matrix[i][j]);
				}
				else
					ft_printf("Skipping NULL c_colours_matrix[%d][%d]\n", i, j);
				j++;
			}
			free(map->c_colours_matrix[i]);
			i++;
		}
		free(map->c_colours_matrix);
	}
}

void	free_z_matrix(t_map *map)
{
	int	i;
	
	i = 0;
	if (map->z_matrix)
	{
		while (i < map->y && map->z_matrix[i])
		{
			ft_printf("Freeing z_matrix row %d: %p\n", i, map->z_matrix[i]);
			free(map->z_matrix[i]);
			map->z_matrix[i] = NULL;
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
		while (i < map->y && map->colours_matrix[i])
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


void free_t_map(t_map *map)
{
	if (!map)
		return ;
	free_char_matrix_stash(map);
	free_z_matrix(map);
	free_colours_matrix(map);
	free_c_z_matrix(map);
	free_c_colours_matrix(map);
	 if (map->line)
		free(map->line);
	free(map);
}

