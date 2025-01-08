/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:03 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/08 16:39:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    parse_map_file(t_map *map, char filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0);
    {
        // free_map_mem
        // error exit
        ft_printf("Error opening file");
        exit (EXIT_FAILURE);
    }
    read_fill_map(map, fd);
}
