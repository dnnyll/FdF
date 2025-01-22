/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:35:37 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/22 12:19:01 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*file;

	if (argc != 2)
	{
		ft_printf("Error opening file");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	map = initialize_map();
	ft_printf("main->initialize_map completed.\n");
	read_map_size(map, file);
	ft_printf("main->read_map_size completed.\n");
	read_store_map_lines(map, file);
	// print_z_matrix(map);
	// ft_printf("main->prrint_z_matrix completed.\n");

	// map = parse_map_file(file);
	// ft_printf("main->parse_map completed.\n");
//	print_map_matrix(map);
	// fill_map_data(map, file);
	// ft_printf("main->fill_map_data completed.\n");
	// color_occurence(map, file);
	// ft_printf("main->color_occurence completed.\n");
	// free_map_data(map);
	// ft_printf("main->free_map_data completed.\n");
	// convert_colors_to_int(map);
	// ft_printf("main->onvert_colors_to_int completed.\n");

	return (0);
}

// int	main(void)
// {
// 	t_app app;

// 	if (!initialize_mlx(&app))
// 		return (1);
// 	mlx_key_hook(app.win.win, handle_key, &app);
// 	mlx_hook(app.win.win, 17, 0, handle_close, &app);
// 	mlx_loop(app.win.mlx);
// 	return (0);
// }

// int	main(void)
// {
// 	t_mlx mlx;

// 	if(!initialize_mlx(&mlx))
// 		return (1);
// 	mlx_loop(mlx.mlx_ptr);
// 	return (0);
// }

// #include "../minilibx-linux/mlx.h"
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// #define KEY_ESC 0xff1b
// #define KEY_W 119
// #define KEY_S 115
// #define KEY_A 97
// #define KEY_D 100
// #define	MAX_PIXELS 125


// typedef struct s_data
// {
// 	void	*mlx_ptr;
// 	void	*mlx_window;
// 	int		pixels[MAX_PIXELS][2];
// 	int		num_pixels;
// 	int		x;
// 	int		y;
// }
// t_data;

// // static void	cleanup_window(t_appapp)
// // {
// // 	if (!app)
// // 		return ;
// // 	if (app->win.img)
// // 	mlx_destroy_image(app->mlx_window)
// // }
// int key_hook(int keycode, t_data *data)
// {
// 	printf("Keycode: %d\n", keycode); // Debug message for keycode
// 	// Initialize starting position if needed
// 	if (data->num_pixels == 0)
// 	{
// 		data->pixels[0][0] = 250; // Starting x position
// 		data->pixels[0][1] = 250; // Starting y position
// 		data->num_pixels++;
// 		mlx_pixel_put(data->mlx_ptr, data->mlx_window, 250, 250, 0xFFFFFF);
// 		printf("First pixel at (250, 250)\n");
// 		return (0);
// 	}

// 	// Get the current position
// 	int curr_x = data->pixels[data->num_pixels - 1][0];
// 	int curr_y = data->pixels[data->num_pixels - 1][1];
// 	printf("1");
// 	// Update position based on key press
// 	if (keycode == KEY_W)      // Move up
// 	{
// 		curr_y -= 10;
// 		printf("KEY_W used successfully.");
// 	}
// 	else if (keycode == KEY_S) // Move down
// 	{
// 		curr_y += 10;
// 		printf("KEY_S used successfully.");
// 	}
// 	else if (keycode == KEY_A) // Move left
// 	{
// 		curr_x -= 10;
// 		printf("KEY_A used successfully.");
// 	}
// 	else if (keycode == KEY_D) // Move right
// 	{
// 		curr_x += 10;
// 		printf("KEY_D used successfully.");
// 	}

// 	// Draw the new pixel
// 	if (data->num_pixels < MAX_PIXELS)
// 	{
// 		data->pixels[data->num_pixels][0] = curr_x;
// 		data->pixels[data->num_pixels][1] = curr_y;
// 		data->num_pixels++;
// 		mlx_pixel_put(data->mlx_ptr, data->mlx_window, curr_x, curr_y, 0x2F677F);
// 		printf("Drawn pixel at (%d, %d)\n", curr_x, curr_y);
// 	}
// 	// Closes window by pressing Esc
// 	if (keycode == KEY_ESC)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
// 		printf("ESC_KEY used successfully.");
// 		exit (0);
// 	}
// 	return (0);
// }
// int	close_window(t_data *data)
// {
// 	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
// 	printf("Window manually closed.");
// 	exit (0);
// }
// int	main (void)
// {
// 	t_data data;
// 	data.mlx_ptr = mlx_init();
// 	data.mlx_window = mlx_new_window(data.mlx_ptr, 500, 500, "default_window");
// 	data.num_pixels = 0;
// //	mlx_pixel_put(data.mlx_ptr, data.mlx_window, 250, 250, 0x2F677F);
// 	mlx_key_hook(data.mlx_window, key_hook, &data);
// 	mlx_hook(data.mlx_window, 17, 0, close_window, &data);
// 	mlx_loop(data.mlx_ptr);
// 	return(0);
// }