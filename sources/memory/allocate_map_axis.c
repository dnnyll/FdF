/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map_axis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:25:56 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/14 15:11:44 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**allocate_map_axis(t_map *map)
{
	int	i;
	int	j;
	char **lines;
	
	i = 0;
	lines = (char **)malloc((sizeof(char *) * map->height));
	if(!lines)
	{
		ft_printf("Error: allocating memory for lines array failed\n");
		return (NULL);
	}
	while (i < map->height)
	{
		lines[i] = (char *)malloc((map->width + 1) * sizeof(char));
		if (!lines[i])
		{
			ft_printf("Error: Memory allocation for lines[%d] failed\n", i);
			j = 0;
			while (j < i)
			{
				free(lines[j]);
				j++;
			}
			free(lines);
			return (NULL);
		}
		i++;
	}	
	return(lines);
}
