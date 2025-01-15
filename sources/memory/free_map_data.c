/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:17:44 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/15 13:21:18 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Frees all struct map data
#include "fdf.h"

void	free_map_data(t_map *map)
{
	int	index;
	
	if (map)
	{
		if (map->data)
		{
			index = 0;
			while (index < map->height)
			{
				free (map->data[index]);
				index++;
			}
			free (map->data);
		}
	}
}