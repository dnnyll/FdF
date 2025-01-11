/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:51:50 by daniefe2          #+#    #+#             */
/*   Updated: 2024/12/13 07:46:47 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len +1);
	ft_strlcat(result, s2, s1_len + s2_len +1);
	return (result);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dst_len)
		return (size + src_len);
	i = 0;
	while (dst_len + i < size - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (size)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}
