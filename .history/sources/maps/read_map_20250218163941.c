/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:26:59 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 16:39:41 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Opens and reads the map input
//	Calculates the y and x of the map
//	Verifies if the input is valid?!?!?!
#include "fdf.h"

void	read_map_size(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error opening and reading file\n");
		free_t_map(map);
		return ;
	}
	map->line = get_next_line(fd);
	while (map->line)
	{
		read_map_width(map, map->line);
		map->y++;
		free(map->line);
		map->line = get_next_line(fd);
	}
	free(map->line);
	close(fd);
}
void	read_map_width(t_map *map, char *line)
{
	char	**parts;
	int		x;

	parts = ft_split(line, ' ');
	if (!parts)
	{
		ft_printf("Error splitting line\n");
		return;
	}
	x = count_line_elements(parts);
	if (map->x == 0)
		map->x = x;
	free_split_result(parts);
}

int	count_line_elements(char **parts)
{
	int	count;

	count = 0;
	while (parts && parts[count])
		count++;
	return (count);
}

void	free_split_result(char **parts)
{
	int	i;
	
	i = 0;
	if(!parts)
		return;
	while (parts[i])
		free(parts[i++]);
	free(parts);
}
