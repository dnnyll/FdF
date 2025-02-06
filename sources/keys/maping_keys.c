
#include "fdf.h"


// This function calls maping_keys and handles additional key events (like ESC)
int handle_key(int keycode, t_map *map)
{
	// Call maping_keys to adjust map properties based on the key pressed
	maping_keys(keycode, map);

	// Handle the ESC key to close the map and exit the program
	// if (keycode == KEY_ESC)
	// {
	// 	mlx_destroy_map(map->mlx_ptr, map->win_ptr);
	// 	exit(0);  // Exit the program
	// }

	// Redraw the grid with updated map properties
	draw_grid(map->mlx_ptr, map->win_ptr, map);

	return (0);  // Return 0 to indicate that the event was handled
}


// This function modifies the map's properties based on the key pressed
void maping_keys(int keycode, t_map *map)
{
	// Modify map properties based on the key pressed

	if (keycode == KEY_W) // Move up or zoom in
	{
		map->iso->zoom += 10;  // Modify zoom level
		map->iso->alpha += 5.0 * (map->iso->pi_val / 180.0); // Tilt up (increase alpha)
	}
	else if (keycode == KEY_S) // Move down or zoom out
	{
		map->iso->zoom -= 10;  // Modify zoom level
		map->iso->alpha -= 5.0 * (map->iso->pi_val / 180.0); // Tilt down (decrease alpha)
	}
	else if (keycode == KEY_A) // Move left or rotate left (beta - 5°)
	{
		map->iso->x_shift -= 10;  // Move left (x shift)
		map->iso->beta -= 5.0 * (map->iso->pi_val / 180.0); // Rotate left (decrease beta)
	}
	else if (keycode == KEY_D) // Move right or rotate right (beta + 5°)
	{
		map->iso->x_shift += 10;  // Move right (x shift)
		map->iso->beta += 5.0 * (map->iso->pi_val / 180.0); // Rotate right (increase beta)
	}

	// Recalculate cos and sin values based on updated alpha and beta
	map->iso->cos_alpha = cos(map->iso->alpha);
	map->iso->sin_alpha = sin(map->iso->alpha);
	map->iso->cos_beta = cos(map->iso->beta);
	map->iso->sin_beta = sin(map->iso->beta);

	// Update cos and sin for the projection
	map->iso->cos = map->iso->cos_beta;  // Update cosine for projection
	map->iso->sin = map->iso->sin_alpha;  // Update sine for projection
}
