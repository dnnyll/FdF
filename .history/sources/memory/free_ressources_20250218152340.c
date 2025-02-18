/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:37:44 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 15:23:40 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map_resources(t_map *map)
{
	if (!map)
		return ;
	free(map->iso);
	free(map->colour);
	free(map->window);
	free(map);
}
