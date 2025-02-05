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

// void	init_draw_line(t_map *map)
// {
// 	map->iso->x1 = (int)roundf(map->conversion_grid[0][0]);
// 	map->iso->y1 = (int)roundf(map->conversion_grid[0][1]);
// 	map->iso->x2 = (int)roundf(map->conversion_grid[1][0]);
// 	map->iso->y2 = (int)roundf(map->conversion_grid[1][1]);
// }
// void draw_line(void *mlx, void *win, t_map *map)
// {
//     // Calculate the differences
//     map->iso->dif_x = map->iso->x2 - map->iso->x1;
//     if (map->iso->dif_x < 0)  // Absolute value of dif_x
//         map->iso->dif_x = -map->iso->dif_x;
    
//     map->iso->dif_y = map->iso->y2 - map->iso->y1;
//     if (map->iso->dif_y < 0)  // Absolute value of dif_y
//         map->iso->dif_y = -map->iso->dif_y;

//     // Set step directions
//     if (map->iso->x1 < map->iso->x2)
//         map->iso->step_drct_x = 1;
//     else
//         map->iso->step_drct_x = -1;

//     if (map->iso->y1 < map->iso->y2)
//         map->iso->step_drct_y = 1;
//     else
//         map->iso->step_drct_y = -1;

//     // Initial error term (used for determining step direction)
//     map->iso->err = map->iso->dif_x - map->iso->dif_y;

//     float epsilon = 0.0001f;

//     while (1)
//     {
//         // Debug: Check if the current point is out of bounds
//         if (map->iso->x1 < 0 || map->iso->x1 >= map->iso->window_width ||
//             map->iso->y1 < 0 || map->iso->y1 >= map->iso->window_height)
//         {
//             printf("Exiting at (%f, %f) - Out of bounds\n", map->iso->x1, map->iso->y1);
//             exit(EXIT_FAILURE);
//         }

//         // Debug: Log current coordinates and error term
//         printf("x1: %f, y1: %f, err: %d\n", map->iso->x1, map->iso->y1, map->iso->err);
        
//         // Draw the pixel at current (x1, y1)
//         mlx_pixel_put(mlx, win, map->iso->x1, map->iso->y1, 0xFFFFFF); // White color

//         // If we've reached the destination, break the loop
//         if (dif_check(map->iso->x1, map->iso->x2, epsilon) && 
//             dif_check(map->iso->y1, map->iso->y2, epsilon))
//         {
//             printf("Line finished at (%f, %f)\n", map->iso->x1, map->iso->y1);
//             break;
//         }

//         // Calculate the temporary error term
//         map->iso->temp_err = 2 * map->iso->err;

//         // Debug: Log temp error before calculating the next step
//         printf("Temp error: %d\n", map->iso->temp_err);

//         // If the error is large enough in the x-direction, move in the x-direction
//         if (map->iso->temp_err > -map->iso->dif_y)
//         {
//             map->iso->err -= map->iso->dif_y;
//             map->iso->x1 += map->iso->step_drct_x;  // Step in the x-direction
//             printf("Moved in x-direction to (%f, %f)\n", map->iso->x1, map->iso->y1);
//         }

//         // If the error is large enough in the y-direction, move in the y-direction
//         if (map->iso->temp_err < map->iso->dif_x)
//         {
//             map->iso->err += map->iso->dif_x;
//             map->iso->y1 += map->iso->step_drct_y;  // Step in the y-direction
//             printf("Moved in y-direction to (%f, %f)\n", map->iso->x1, map->iso->y1);
//         }
//     }

//     // Final debugging: Print final coordinates
//     printf("Line drawn from (%f, %f) to (%f, %f)\n", map->iso->x1, map->iso->y1, map->iso->x2, map->iso->y2);
// }

void draw_line(void *mlx, void *win, t_map *map)
{
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
	double epsilon = 0.0000001;
	while (1)
	{
		if (map->iso->x1 < 0 || map->iso->x1 >= map->iso->window_width ||
		map->iso->y1 < 0 || map->iso->y1 >= map->iso->window_height)
		{
			printf("Exiting at (%f, %f) - Out of bounds\n", map->iso->x1, map->iso->y1);
			exit(EXIT_FAILURE);
		}
		// Boundary check: Skip drawing if outside the window
		// if (map->iso->x1 >= 0 && map->iso->x1 < map->iso->window_width &&
		// 	map->iso->y1 >= 0 && map->iso->y1 < map->iso->window_height)
		// {
		// 	mlx_pixel_put(mlx, win, map->iso->x1, map->iso->y1, 0xFFFFFF); // White color
		// }
		// Draw the pixel at current (x1, y1)
		mlx_pixel_put(mlx, win, map->iso->x1, map->iso->y1, 0xFFFFFF); // White color

		// If we've reached the destination, break the loop
		if (dif_check(map->iso->x1, map->iso->x2, epsilon) && 
			dif_check(map->iso->y1, map->iso->y2, epsilon))
			break;

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
	// printf("dif_x: %d, dif_y: %d\n", map->iso->dif_x, map->iso->dif_y);
	// printf("Drawing at x: %f, y: %f\n", map->iso->x1, map->iso->y1);
	// printf("Drawing line from (%f, %f) to (%f, %f)\n", map->iso->x1, map->iso->y1, map->iso->x2, map->iso->y2);
}

// Function to check if the difference between two floating-point values is within a threshold
void	draw_grid(void *mlx_ptr, void *win_ptr, t_map *map)
{
	draw_horizontal_lines(mlx_ptr, win_ptr, map);
	draw_vertical_lines(mlx_ptr, win_ptr, map);
}

void draw_horizontal_lines(void *mlx_ptr, void *win_ptr, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y) // Iterate over rows
	{
		j = 0;
		while (j < map->x - 1) // Iterate over columns (except last one)
		{
			map->iso->x1 = (int)roundf(map->conversion_grid[i][j * 2]);
			map->iso->y1 = (int)roundf(map->conversion_grid[i][j * 2 + 1]);
			map->iso->x2 = (int)roundf(map->conversion_grid[i][(j + 1) * 2]);
			map->iso->y2 = (int)roundf(map->conversion_grid[i][(j + 1) * 2 + 1]);
			// printf("HORIZONTAL: Row: %d, Col: %d -> (%f, %f) to (%f, %f)\n",
			// i, j, map->iso->x1, map->iso->y1, map->iso->x2, map->iso->y2);
			draw_line(mlx_ptr, win_ptr, map);
			j++;
		}
		i++;
	}
}

void draw_vertical_lines(void *mlx_ptr, void *win_ptr, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y - 1) // Iterate over rows (except last one)
	{
		j = 0;
		while (j < map->x) // Iterate over columns
		{
			map->iso->x1 = (int)roundf(map->conversion_grid[i][j * 2]);
			map->iso->y1 = (int)roundf(map->conversion_grid[i][j * 2 + 1]);
			map->iso->x2 = (int)roundf(map->conversion_grid[i + 1][j * 2]);
			map->iso->y2 = (int)roundf(map->conversion_grid[i + 1][j * 2 + 1]);
			// printf("VERTICAL: Row: %d, Col: %d -> (%f, %f) to (%f, %f)\n",
			// i, j, map->iso->x1, map->iso->y1, map->iso->x2, map->iso->y2);
			draw_line(mlx_ptr, win_ptr, map);
			j++;
		}
		i++;
	}
}

// Check if two floats are approximately equal within an epsilon threshold
int dif_check(double a, double b, double epsilon)
{
	return fabs(a - b) < epsilon;  // If the absolute difference is less than epsilon, return true
}


