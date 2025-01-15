/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:17:01 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/15 16:26:53 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_occurence(t_map *map, const char *filename)
{
	char *line;
	int	tracker;
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		free(map);
		exit(EXIT_FAILURE);
	}
	tracker = 0;
	line = get_next_line(fd);
	while(line)
	{
		ft_printf("inside while loop.\n");
		if(ft_split(line, ','))
		{
			ft_printf("ft_split.\n");
			map->color_stash = allocate_color_data_char(map);
			map->color_stash[tracker] = malloc(sizeof(char *) * 10 + 1); //this is not a correct allocation, refer to memory allocation functions for **
			ft_printf("color_stash allocation completed.\n");
			map->color_stash[tracker] = ft_substr(filename, 0, 10);
			ft_printf("color_stash[%d]: %s\n", map->color_count, map->color_stash);
		}
		tracker++;
		map->color_count++;
		line = get_next_line(fd);
	}
}
char	**allocate_color_data_char(t_map *map)
{
	int	index;

	map->color_stash = malloc(sizeof(char *) * map->height);
	if(!map->color_stash)
	{
		free(map->color_stash);
		ft_printf("failed allocating memory for map->data_char (rows)");
		exit(EXIT_FAILURE);
	}
	index = 0;
	while (index < map->height)
	{
		map->color_stash[index] = malloc(sizeof(char) * map->width);
		if(!map->color_stash[index])
		{
			free(map->color_stash);
			ft_printf("failed allocating memory for map->data_char[index] (row content)");
			exit(EXIT_FAILURE);
		}
		index++;
	}
	ft_printf("allocate_map_data_char successful\n");
	return(map->color_stash);
}