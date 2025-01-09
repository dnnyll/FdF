/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:57:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/09 10:20:55 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*initialize_map(void)
{
	t_map *map;
	map = malloc(sizeof(t_map))
	if(!map)
	{
		perror("Memory allocation failed for map");
		exit(EXIT_FAILURE);
	}
	map->width = 0;
	map->height = 0;
	map->data = NULL;
	return map;
}
// t_map	*initialize_map(char *filename)
// {
// 	t_map	*map;
	
// 	int		fd;
// 	char	*position;
// 	char	**split_result;
	
// 	map = (t_map *)ft_calloc(1, sizeof(t_map));
// 	if (!map)
// 	{
// 		// free_map_mem
// 		// error exit
//         ft_printf("Error allocating memory for map");
//         exit (EXIT_FAILURE);
// 	}
// 	fd = open(filename, O_RDONLY);
//     if (fd < 0)
//     {
//         // free_map_mem
//         // error exit
//         ft_printf("Error opening file");
//         exit (EXIT_FAILURE);
//     }
// 	position = get_next_line(fd);

// 	while (position)
// 	{
// 		map->height++;
// 		free(position);
// 		position = get_next_line(fd);	
// 	}
// 	free(position);
// 	split_result = ft_split(position, ' ');
// 	while (split_result[map->width])
// 		map->width++;
// 	free(position);
// 	close(fd);
// 	return(map);
// }

