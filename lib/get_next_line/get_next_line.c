/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 07:27:18 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/13 14:15:40 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//	reads text according to BUFFER_SIZE
//	sets temp to be same as leftover so we dont lose the postion of leftover
//	combines buffer and temp into leftover
//	searches for a \n to decide if it leaves the loop or remains in it
//	returns whats leftover that corresponds to all the text read and appended

static char	*read_and_fill(int fd, char *buffer, char *leftover)
{
	char	*temp;
	ssize_t	read_line;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (free (leftover), NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (!leftover)
			leftover = ft_strdup ("");
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

//	Iterates through the text until if finds the \n;
//	Extracts text after\n at next_line_start and puts it into remaining_text
//	Remaining text will be sent to get_next_line's leftover
static char	*extract(char *current_line)
{
	char	*next_line_start;
	char	*remaining_text;

	next_line_start = current_line;
	if (*next_line_start == '\0')
		return (NULL);
	while (*next_line_start != '\n' && *next_line_start != '\0')
		next_line_start++;
	if (*next_line_start == '\n')
		next_line_start++;
	remaining_text = ft_substr(next_line_start, 0, ft_strlen(next_line_start));
	if (*remaining_text == '\0')
	{
		free(remaining_text);
		remaining_text = NULL;
	}
	*next_line_start = '\0';
	return (remaining_text);
}

//	checks if input values are valid
//	calls read_and_fill to get line value
//	lefover recovers remaining_text when calling extract
char	*get_next_line(int fd)
{
	char		*text_read;
	char		*buffer;
	static char	*stash;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free (buffer);
		free (stash);
		return (buffer = NULL, stash = NULL, NULL);
	}
	text_read = read_and_fill(fd, buffer, stash);
	free (buffer);
	buffer = NULL;
	if (!text_read)
		return (NULL);
	stash = extract(text_read);
	return (text_read);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub_s;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_len < start)
		len = 0;
	if (s_len - start < len)
		len = s_len - start;
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s1) + 1;
	result = malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, size);
	return (result);
}
//	the output lines will contain \n\0 at the end, last line only \0
// int	main(void)
// {
// 	int     fd;
// 	char    *line;

// 	fd = open("thetext.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error\n");
// 		return (0);
// 	}
// 	while ((line = get_next_line(fd)))
// 		printf("%s", line);
// 	return (0);
// }
