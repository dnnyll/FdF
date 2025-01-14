/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:15:31 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/11 16:30:16 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"  // Ensure this includes the definition of 't_map'

// Your free_map_data function definition
void free_map_data(t_map *map)
{
    int i;

    if (map)
    {
        if (map->data)
        {
            i = 0;
            while (i < map->height)
            {
                free(map->data[i]);
                i++;
            }
            free(map->data);
        }
    }
}
