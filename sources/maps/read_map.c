/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:26:59 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/26 11:41:06 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map_size(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == 0)
	{
		ft_printf("Error opening and reading file\n");
		free_t_map(map);
		exit (EXIT_FAILURE);
	}
	map->line = get_next_line(fd);
	while (map->line)
	{
		read_map_width(map, map->line, fd);
		map->y++;
		free(map->line);
		map->line = get_next_line(fd);
	}
	free(map->line);
	if (map ->x == 0 && map->y == 0)
	{
		ft_printf("Error: Empty map!");
		close(fd);
		exit (EXIT_FAILURE);
	}
	close(fd);
}

void	read_map_width(t_map *map, char *line, int fd)
{
	char	**parts;
	int		x;

	parts = ft_split(line, ' ');
	if (!parts || is_empty_spaces(line))
	{
		ft_printf("Error: splitting line, empty or space-only line\n");
		stop_map_inconsist(map);
		free_split_result(parts);
		close(fd);
		exit (EXIT_FAILURE);
	}
	x = count_line_elements(parts);
	if (map->x == 0)
		map->x = x;
	else if (x != map->x)
	{
		ft_printf("Error: Inconsistent map width.\n");
		free_split_result(parts);
		stop_map_inconsist(map);
		close (fd);
		exit (EXIT_FAILURE);
	}
	free_split_result(parts);
}

int	is_empty_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
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
	if (!parts)
		exit (EXIT_FAILURE);
	while (parts[i])
		free(parts[i++]);
	free(parts);
}
