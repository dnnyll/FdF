/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   rendering_projection.c							 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: daniefe2 <daniefe2@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/03 13:29:52 by daniefe2		  #+#	#+#			 */
/*   Updated: 2025/02/03 17:40:34 by daniefe2		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fdf.h"

// 


// void	draw_grid(void *mlx_ptr, void *win_ptr, t_map *map)
// {
// 	draw_horizontal_lines(mlx_ptr, win_ptr, map);
// 	draw_vertical_lines(mlx_ptr, win_ptr, map);
// }

// void draw_horizontal_lines(void *mlx_ptr, void *win_ptr, t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	current_colour;

// 	i = 0;
// 	while (i < map->y)
// 	{
// 		j = 0;
// 		while (j < map->x - 1)
// 		{
// 			map->iso->x1 = (int)roundf(map->conversion_grid[i][j * 2]);
// 			map->iso->y1 = (int)roundf(map->conversion_grid[i][j * 2 + 1]);
// 			map->iso->x2 = (int)roundf(map->conversion_grid[i][(j + 1) * 2]);
// 			map->iso->y2 = (int)roundf(map->conversion_grid[i][(j + 1) * 2 + 1]);
// 			// i, j, map->iso->x1, map->iso->y1, map->iso->x2, map->iso->y2);
// 			current_colour = map->colours_matrix[i][j];
// 			// get_rgb_values(current_colour) ==> struct {r= 1, g = 45, b =5}
// 			// get_gradient_values(struct rgb, )
// 			// int current_colour = turn_rgb_to_int(struct rgb)
// 			draw_line(mlx_ptr, win_ptr, map, current_colour);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void draw_vertical_lines(void *mlx_ptr, void *win_ptr, t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < map->y - 1)
// 	{
// 		j = 0;
// 		while (j < map->x)
// 		{
// 			map->iso->x1 = (int)roundf(map->conversion_grid[i][j * 2]);
// 			map->iso->y1 = (int)roundf(map->conversion_grid[i][j * 2 + 1]);
// 			map->iso->x2 = (int)roundf(map->conversion_grid[i + 1][j * 2]);
// 			map->iso->y2 = (int)roundf(map->conversion_grid[i + 1][j * 2 + 1]);
// 			int	current_colour = map->colours_matrix[i][j];
// 			draw_line(mlx_ptr, win_ptr, map, current_colour);
// 			j++;
// 		}
// 		i++;
// 	}
// }




