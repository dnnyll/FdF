/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:13:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/18 14:33:13 by daniefe2         ###   ########.fr       */
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
	int	i;
	int	j;
	
	i = 0;
	if (get_base_len(base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
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

int	get_base_i(char c, const char *base)
{
	int	i;
	
	i = 0;
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
	int	base_len;
	int	result;
	int	sign;
	int	i;

	base_len = get_base_len(base);
	result = 0;
	sign = 1;
	if (!is_valid_base(base))
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' 
	{
		sign = -1;
		str++;
	}
	|| *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str)
	{
		i = get_base_i(*str, base);
		if (i == -1)
			break ;
		result = result * base_len + i;
		str++;
	}
	return (result * sign);
}
