/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:34:43 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/26 16:46:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	valid_hex_check(t_map *map, int i)
{
	int	j;
	int base_index;

	if (map->line[i + 1] == '0' && (map->line[i + 2] == 'x' || map->line[i + 2] == 'X'))
	{
		i += 3;  // Skip past "0x" or "0X"
		j = 0;
		while (j < 6)  // 6 characters for the color code
		{
			base_index = get_base_i(map->line[i + j], "0123456789abcdefABCDEF");
			if (base_index == -1)  // Invalid character
			{
				ft_printf("Error: Invalid colour format\n");
				stop_map_inconsist(map);
				exit(EXIT_FAILURE);
			}
			j++;
		}
	}
	else 
	{
		ft_printf("Error: Invalid format after ','\n");
		stop_map_inconsist(map);
		exit(EXIT_FAILURE);
	}
}
void valid_char_check(t_map *map)
{
	int i = 0;

	while (map->line[i])
	{
		if ((ft_isdigit(map->line[i])) || (map->line[i] == ' ') || (map->line[i] == '-'))
			i++; // Move forward normally
		else if (map->line[i] == ',')
		{
			// Ensure enough space for ",0x######"
			if (!map->line[i + 1] || !map->line[i + 2])
			{
				ft_printf("Error: Incomplete color format\n");
				stop_map_inconsist(map);
				exit(EXIT_FAILURE);
			}
			valid_hex_check(map, i);
			i += 9; // Move forward after valid color
		}
		else
		{
			ft_printf("Error: Invalid character in map\n");
			stop_map_inconsist(map);
			exit(EXIT_FAILURE);
		}
	}
}