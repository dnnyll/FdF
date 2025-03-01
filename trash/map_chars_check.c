/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:34:43 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/26 19:22:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_digit_or_space(char c)
{
	return (ft_isdigit(c) || ft_isspace(c));
}

int	check_hex_or_comma(t_map *map, int *i, int fd)
{
	if (map->line[*i] == '0' && (map->line[*i + 1] == 'x' || \
	map->line[*i + 1] == 'X'))
	{
		valid_hex_check(map, *i, fd);
		*i += 3;
		return (1);
	}
	else if (map->line[*i] == ',')
	{
		if (map->line[*i + 1] == '0' && (map->line[*i + 2] == 'x' || \
		map->line[*i + 2] == 'X'))
		{
			valid_hex_check(map, *i, fd);
			*i += 3;
			return (1);
		}
		else
		{
			ft_printf("Error: Invalid format after ',' at position %d\n", *i);
			stop_map_inconsist(map);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

void	valid_char_check(t_map *map, int fd)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (check_digit_or_space(map->line[i])) 
			i++;
		else if (check_hex_or_comma(map, &i, fd))
			continue ;
		else
		{
			ft_printf("Error: Invalid character '%c' at position %d\n", map->line[i], i);
			stop_map_inconsist(map);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}
}



// void valid_char_check(t_map *map, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (map->line[i])
// 	{
// 		if (ft_isdigit(map->line[i])) 
// 			i++;
// 		else if (ft_isspace(map->line[i])) 
// 			i++;
// 		else if (map->line[i] == '0' && (map->line[i + 1] == 'x' || map->line[i + 1] == 'X'))
// 		{
// 			valid_hex_check(map, i, fd);
// 			i += 3;
// 		}
// 		else if (map->line[i] == ',')
// 		{
// 			if (map->line[i + 1] == '0' && (map->line[i + 2] == 'x' || map->line[i + 2] == 'X'))
// 			{
// 				valid_hex_check(map, i, fd);
// 				i += 3;
// 			}
// 			else
// 			{
// 				ft_printf("Error: Invalid format after ',' at position %d\n", i);
// 				stop_map_inconsist(map);
// 				close (fd);
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		else
// 		{
// 			ft_printf("Error: Invalid character '%c' at position %d\n", map->line[i], i);
// 			stop_map_inconsist(map);
// 			close(fd);
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// }

void	valid_hex_check(t_map *map, int i, int fd)
{
	int	j;
	int base_index;

	if (map->line[i + 1] == '0' && (map->line[i + 2] == 'x' || map->line[i + 2] == 'X'))
	{
		i += 3;
		j = 0;
		while (j < 6)
		{
			base_index = get_base_i(map->line[i + j], "0123456789abcdefABCDEF");
			if (base_index == -1)
			{
				ft_printf("Error: Invalid colour format\n");
				stop_map_inconsist(map);
				close(fd);
				exit(EXIT_FAILURE);
			}
			j++;
		}
	}
}
