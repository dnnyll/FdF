/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:44:05 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/17 11:50:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_int(const char *hex_str)
{
	int	index;
	int	result;

	index = 2; // skips 0x
	result = 0;

	while(hex_str[index] != '\0')
	{
		result *= 16;
		if (ft_isdigit(hex_str[index]))
			result += hex_str[index] - 0;
		else if (ft_isalpha(hex_str[index]))
		{
			if (hex_str[index] >='a' && hex_str[index] <= 'f')
				result += hex_str[index] - 'a' + 10;
			if (hex_str[index] >='A' && hex_str[index] <= 'F')
				result += hex_str[index] - 'A' + 10;
		}
		else
		{
			ft_printf("Error: invalid hexadecimal character: %c\n.", hex_str[index]);
			return (-1);
		}
		index++;
	}
	return (result);
}

void	convert_colors_to_int(t_map *map)
{
	int	color_value;
	int	row = 0;

	while (row < map->height)
	{
		ft_printf("Row %d contains: %s\n", row, map->color_stash[row]);
		if (map->color_stash[row] && ft_strncmp(map->color_stash[row], "0x", 2) == 0)
		{
			color_value = hex_to_int(map->color_stash[row]);
			if (color_value >= 0)
			{
				ft_printf("debugging color %s to integer: %d\n", map->color_stash[row], map->color_values[row]);
				map->color_values[row] = color_value;
				ft_printf("Converted color %s to integer: %d\n", map->color_stash[row], map->color_values[row]);
			}
			else
			{
				ft_printf("Error converting color: %s\n", map->color_stash[row]);
			}
		}
		else
		{
			ft_printf("No valid color code found at row %d\n", row);
		}
		row++;
	}
}
