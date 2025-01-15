/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map_data_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:55:03 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/15 13:57:15 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//allocates memory for rows based on height
//allocates memory for elements contained in every row based on width
void	allocate_map_data_int(t_map *map)
{
	int	index;

	map->data = malloc(sizeof(int *) * map->height);
	if(!map->data)
	{
		free(map->data);
		ft_printf("failed allocating memory for map->data (rows)");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < map->height)
	{
		map->data[index] = malloc(sizeof(int) * map->width);
		if(!map->data[index])
		{
			free(map->data);
			ft_printf("failed allocating memory for map->data[index] (row content)");
			exit(EXIT_FAILURE);
		}
		index++;
	}
	ft_printf("allocate_map_data successful\n");
}


