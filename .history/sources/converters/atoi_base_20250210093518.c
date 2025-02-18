/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:13:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/23 11:42:43 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	get_base_len(const char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	is_valid_base(const char *base)
{
	int	index;

	index = 0;
	if (get_base_len(base) < 2)
		return (0);
	while (base[index])
	{
		int	jndex = index + 1;
		if (base[index] == '+' || base[index] == '-' || ft_isspace(base[index]))
			return (0);
		while (base[jndex])
		{
			if (base[index] == base[jndex])
				return (0);
			jndex++;
		}
		index++;
	}
	return (1);
}

int	get_base_index(char c, const char *base)
{
	int	index;
	
	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	base_len;
	int	result;
	int	sign;

	base_len = get_base_len(base);
	result = 0;
	sign = 1;
	if (!is_valid_base(base))
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str)
	{
		int	index = get_base_index(*str, base);
		if (index == -1)
			break ;
		result = result * base_len + index;
		str++;
	}
	return (result * sign);
}
