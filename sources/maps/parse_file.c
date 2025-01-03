/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:03 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/03 17:20:55 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definie_a_library.h"

void    parse_map_file(t_map, char *filename)
{
    int fd;
    
    fd = open(fn, O_RDONLY);
    if (fd < 0)
    {
        free_map_mem(map);
        exit_with_perr(fn);
    }
    read_fill_map(map, fd);
    close(fd);
}