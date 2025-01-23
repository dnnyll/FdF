/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:13:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/23 10:21:59 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	get_base_len(const char *base)
{
	int	len = 0;

	while (base[len])
		len++;
	return (len);
}

int	is_valid_base(const char *base)
{
	int	i = 0;

	if (get_base_len(base) < 2)
		return (0);
	while (base[i])
	{
		int	j = i + 1;
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_base_index(char c, const char *base)
{
	int	i = 0;

	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	base_len = get_base_len(base);
	int	result = 0;
	int	sign = 1;

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
