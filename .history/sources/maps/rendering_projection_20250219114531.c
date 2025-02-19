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

void	draw_line(void *mlx, void *win, t_map *map, int current_colour)
{
	double	epsilon = 0.00000000001;
	// Calculate the differences
	map->iso->dif_x = map->iso->x2 - map->iso->x1;
	if (map->iso->dif_x < 0)  // Absolute value of dif_x
		map->iso->dif_x = -map->iso->dif_x;
		
	map->iso->dif_y = map->iso->y2 - map->iso->y1;
	if (map->iso->dif_y < 0)  // Absolute value of dif_y
		map->iso->dif_y = -map->iso->dif_y;

	// Set step directions
	if (map->iso->x1 < map->iso->x2)
		map->iso->step_drct_x = 1;
	else
		map->iso->step_drct_x = -1;

	if (map->iso->y1 < map->iso->y2)
		map->iso->step_drct_y = 1;
	else
		map->iso->step_drct_y = -1;
	// Initial error term (used for determining step direction)
	map->iso->err = map->iso->dif_x - map->iso->dif_y;
	while (1)
	{
		// // Clamp the values of x1 and y1
		// if (map->iso->x1 < 0) map->iso->x1 = 0;
		// else if (map->iso->x1 >= map->iso->window_width) map->iso->x1 = map->iso->window_width - 1;

		// if (map->iso->y1 < 0) map->iso->y1 = 0;
		// else if (map->iso->y1 >= map->iso->window_height) map->iso->y1 = map->iso->window_height - 1;

		// Now check if the coordinates are still valid (this should not trigger if clamping works)
		if (map->iso->x1 < 0 || map->iso->x1 >= map->window->win_width ||
			map->iso->y1 < 0 || map->iso->y1 >= map->window->win_height)
		{
			printf("Warning: Exiting at (%f, %f) - Out of bounds\n", map->iso->x1, map->iso->y1);
			exit(EXIT_FAILURE);
		}

		if (map->iso->x1 < 0 || map->iso->x1 >= map->window->win_width ||
		map->iso->y1 < 0 || map->iso->y1 >= map->window->win_height)
		{
			printf("Warning: Exiting at (%f, %f) - Out of bounds\n", map->iso->x1, map->iso->y1);
			exit(EXIT_FAILURE);
		}
		if (map->colour->x_colour_grid >= map->x || map->colour->y_colour_grid >= map->y)
		{
			printf("Error: Index out of bounds! x_colour_grid: %d, y_colour_grid: %d\n", 
				map->colour->x_colour_grid, map->colour->y_colour_grid);
			exit(EXIT_FAILURE);
		}

		// if (!map->colour->rgb_grid[map->colour->x_colour_grid][map->colour->y_colour_grid])
		// {
		// 	printf("Error: rgb_grid[%d][%d] is NULL\n", 
		// 		map->colour->x_colour_grid, map->colour->y_colour_grid);
		// 	exit(EXIT_FAILURE);
		// }
		// Ensure x_colour_grid is within bounds
		if (map->colour->x_colour_grid < 0)
			map->colour->x_colour_grid = 0;
		else if (map->colour->x_colour_grid >= map->x)
			map->colour->x_colour_grid = map->x - 1;
		// Ensure y_colour_grid is within bounds
		if (map->colour->y_colour_grid < 0)
			map->colour->y_colour_grid = 0;
		else if (map->colour->y_colour_grid >= map->y)
			map->colour->y_colour_grid = map->y - 1;
		put_pixel(map, (int)map->iso->x1, (int)map->iso->y1, current_colour);
		// If we've reached the destination, break the loop
		if (dif_check(map->iso->x1, map->iso->x2, epsilon) && 
			dif_check(map->iso->y1, map->iso->y2, epsilon))
		{
			break;
		}
		// Calculate the temporary error term
		map->iso->temp_err = 2 * map->iso->err;
		// If the error is large enough in the x-direction, move in the x-direction
		if (map->iso->temp_err > -map->iso->dif_y)
		{
			map->iso->err -= map->iso->dif_y;
			map->iso->x1 += map->iso->step_drct_x;  // Step in the x-direction
		}
		// If the error is large enough in the y-direction, move in the y-direction
		if (map->iso->temp_err < map->iso->dif_x)
		{
			map->iso->err += map->iso->dif_x;
			map->iso->y1 += map->iso->step_drct_y;  // Step in the y-direction
		}
	}
}
// Check if two floats are approximately equal within an epsilon threshold
int dif_check(double a, double b, double epsilon)
{
	return fabs(a - b) < epsilon;	// If the absolute difference is less than epsilon, return true
}

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




