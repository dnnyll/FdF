/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:22:58 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/21 16:20:05 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDH_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/Libft/libft.h"
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <errno.h>
// #include <math.h>

// Structure to hold the window and mlx pointers
typedef	struct s_window
{
	void	*mlx;
	void	*win;
}
t_window;

// Main application structure
typedef	struct s_app
{
	t_window win;
}
t_app;

// typedef	struct s_coordinates
// {


// }
// t_coordinates;

typedef	struct s_map
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		*colour_row;
	int		**z_matrix;
	int		**colour_matrix;
	int		*z_row;
	char	**z_str;
	char	**colour_str;
	char	**row;
	char	*line;
	char	**comma_pos;
	// t_coordinates coordinates_matrix;
	// int		**data;
	// int		color_count;
	// int		*color_values;
	// char	**color_stash;
	int		height;
	int		width;
	// char 	**lines;
	// char 	**data_char;
}
t_map;

//		-=""verifier /////////////////////////////////////////////
void	print_map_matrix(t_map *map);

//		-=""window management /////////////////////////////////////////////
int	initialize_mlx(t_app *app);
void	render(t_app *app);
int	handle_key(int keycode, t_app *app);
int	handle_close(t_app *app);
void	cleanup_window(t_app *app);

//		-=""map management ///////////////////////////////////////////////
void	read_map_repeat(t_map *map, char *filename);
void	read_map_size(t_map *map, char *filename);
void parse_map_row(t_map *map);
void	read_map_width(t_map *map, char *line);
int	count_line_elements(char **array);
void	free_split_result(char **array);

t_map	*initialize_map(void);
t_map	*parse_map_file(const char *filename);
int	count_elements(char **array);
void	fill_map_data(t_map *map, const char *filename);

//		-=""color management /////////////////////////////////////////////
int		hex_to_int(char *hex_str);

void	color_occurence(t_map *map, const char *filename);
void	process_line_for_colors(t_map *map, char *line, int row);
void	convert_colors_to_int(t_map *map);


//		-=""memory management
void	matrix_alloc_height(t_map *map);
void	matrix_alloc_width(t_map *map);

void	allocate_map_data_int(t_map *map);
void	allocate_map_data_inttt(t_map *map);
char	**allocate_map_data_char(t_map *map);
char	**allocate_color_data_char(t_map *map);
void	free_map_data(t_map *map);
void	free_split_parts(char **parts);
void	matrix_memory_alloc(t_map *map);

//		-=""color management /////////////////////////////////////////////
void	print_z_matrix(t_map *map);

#endif