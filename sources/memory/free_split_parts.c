/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split_parts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:16:08 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/24 10:56:09 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split_parts(char **parts)
{
	int	index;

	if (!parts)
		return ;

	index = 0;
	while (parts[index])
	{
		free (parts[index]); // Free each string in the array
		index++;
	}
	free(parts); // Free the array itself
}

