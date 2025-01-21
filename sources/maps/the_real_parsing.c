/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_real_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:18:53 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/21 10:08:25 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
    // 1. Open file and prepare to read
void parse_map(t_map *map, char *filename)
{
	int	fd;

	fd = open(read, filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error reading file\n");
	}

void	allocate_mem_matrices (t_map *data)
{
	int	index;


}
    

    // 2. Allocate memory for matrices based on width and height
	matrix = malloc((sizeof(char *)) * (map->height * map->width));
    // 3. For each line:
    //     - Split line into elements
    //     - Parse each element for `z` and color
    //     - Store values in matrices
    // 4. Close file and finalize
}

int parse_hex_color(char *color_str)
{
	
    // Convert the hexadecimal string to an integer
    // Handle "0x" prefix
}

void parse_line(char *line, int *z_row, int *color_row)
{
    // Split line into elements
    // Parse each element for `z` and color
    // Convert and store in respective rows
}
