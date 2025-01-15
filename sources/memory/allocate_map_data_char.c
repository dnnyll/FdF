/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map_data_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:09:25 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/15 11:20:08 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**allocate_map_data_char(t_map *map)
{
	int	index;

	map->data_char = malloc(sizeof(char *) * map->height);
	if(!map->data_char)
	{
		free(map->data_char);
		ft_printf("failed allocating memory for map->data_char (rows)");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < map->height)
	{
		map->data_char[index] = malloc(sizeof(char) * map->width);
		if(!map->data_char[index])
		{
			free(map->data_char);
			ft_printf("failed allocating memory for map->data_char[index] (row content)");
			exit(EXIT_FAILURE);
		}
		index++;
	}
	ft_printf("allocate_map_data_char successful\n");
	return(map->data_char);
}