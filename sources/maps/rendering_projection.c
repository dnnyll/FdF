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

// Function to draw a line using Bresenham's line algorithm
void draw_line(void *mlx, void *win, t_map *map)
{
	//casting floats into ints
	map->iso->x1 = (int)(map->conversion_grid[0][0]);
	map->iso->y1 = (int)(map->conversion_grid[0][1]);
	map->iso->x2 = (int)(map->conversion_grid[1][0]);
	map->iso->y2 = (int)(map->conversion_grid[1][1]);
	printf("conversion_grid[0][0]: %f\n", map->conversion_grid[0][0]);
	printf("conversion_grid[0][1]: %f\n", map->conversion_grid[0][1]);
	printf("conversion_grid[1][0]: %f\n", map->conversion_grid[1][0]);
	printf("conversion_grid[1][1]: %f\n", map->conversion_grid[1][1]);
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
	float epsilon = 0.1f;
	while (1)
	{
		// Boundary check: Skip drawing if outside the window
		if (map->iso->x1 >= 0 && map->iso->x1 < map->iso->window_width &&
			map->iso->y1 >= 0 && map->iso->y1 < map->iso->window_height)
		{
			mlx_pixel_put(mlx, win, map->iso->x1, map->iso->y1, 0xFFFFFF); // White color
		}
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
	printf("dif_x: %d, dif_y: %d\n", map->iso->dif_x, map->iso->dif_y);
	printf("Window size: %d x %d\n", map->iso->window_width, map->iso->window_height);
	printf("Drawing at x: %f, y: %f\n", map->iso->x1, map->iso->y1);
}

// Function to check if the difference between two floating-point values is within a threshold
void	draw_grid(void *mlx_ptr, void *win_ptr, t_map *map)
{
	draw_horizontal_lines(mlx_ptr, win_ptr, map);
	draw_vertical_lines(mlx_ptr, win_ptr, map);
}

void draw_horizontal_lines(void *mlx_ptr, void *win_ptr, t_map *map)
{
    int i, j;

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
            draw_line(mlx_ptr, win_ptr, map);
            j++;
        }
        i++;
    }
}

void draw_vertical_lines(void *mlx_ptr, void *win_ptr, t_map *map)
{
    int i, j;

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
            draw_line(mlx_ptr, win_ptr, map);
            j++;
        }
        i++;
    }
}
int dif_check(float a, float b, float epsilon)
{
    return (fabs(a - b) < epsilon);
}
