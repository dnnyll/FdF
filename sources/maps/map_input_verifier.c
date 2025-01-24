/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_verifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:10:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/23 11:49:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_map_line(t_map *map)
{
	char	**parts;
	int		index;
	int		count;

	parts = ft_split(line, ' ');
	if (!parts)
		return (0);
	count = count_line_elements(parts);
	if (count != map->x)
	{
		free_split_result(parts);
		return (0);
	}
	index = 0;
	while (parts[index])
	{
		if (!is_valid_map_value(parts[index]))
		{
			free_split_result(parts);
			return (0);
		}
		index++;
	}
	free_split_result(parts);
	return (1);
}

int	is_valid_map_value(char *value)
{
	char	*comma_pos;

	comma_pos = ft_strchr(value, ',');
	if (comma_pos)
	{
		*comma_pos = '\0';
		if (!is_valid_int(value) || !is_valid_hex_color(comma_pos + 1))
			return (0);
		*comma_pos = ',';
	}
	else
	{
		if (!is_valid_int(value))
			return (0);
	}
	return (1);
}

int	is_valid_int(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_hex_color(char *str)
{
	if (ft_strncmp(str, "0x", 2) != 0)
		return (0);
	str += 2;
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') ||
		   (*str >= 'a' && *str <= 'f') ||
		   (*str >= 'A' && *str <= 'F')))
			return (0);
		str++;
	}
	return (1);
}
