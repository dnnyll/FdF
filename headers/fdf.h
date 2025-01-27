/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:22:58 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/27 11:31:50 by daniefe2         ###   ########.fr       */
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

// structure to hold the window and mlx pointers
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

// map parsing structure
typedef	struct s_map
{
	int		x;
	int		y;
	int		z;
	int		**z_matrix;
	int		**colours_matrix;
	char	*line;
	char	**char_matrix_stash;
	char	***c_z_matrix;
	char	***c_colours_matrix;

	int		***coordinates_grid;
}
t_map;

//		-=""window management	/////////////////////////////////////////////
int		initialize_mlx(t_app *app);
void	render(t_app *app);
int		handle_key(int keycode, t_app *app);
int		handle_close(t_app *app);
void	cleanup_window(t_app *app);

//		-=""map management		///////////////////////////////////////////////
t_map	*initialize_map(void);
void	initialize_map_fields(t_map *map);
void	read_map_size(t_map *map, char *filename);
void	read_map_width(t_map *map, char *line);
void	read_map_repeat(t_map *map, char *filename);
void	store_map_lines(t_map *map, int fd);
void	process_lines(t_map *map);
void	process_parts(t_map *map, int row, int col);
void	char_matrix_alloc(t_map *map);
int		count_line_elements(char **parts);
void	free_split_result(char **parts);

//		-=""memory management
void	int_matrix_alloc(t_map *map);
void	char_matrix_alloc(t_map *map);
void	int_matrix_alloc(t_map *map);
void	free_t_map(t_map *map);
void	free_char_matrix_stash(t_map *map);
void	free_c_z_matrix(t_map *map);
void	free_c_colours_matrix(t_map *map);
void	free_t_map(t_map *map);
void	free_colours_matrix(t_map *map);
void	free_z_matrix(t_map *map);
void	free_split_parts(char **parts);

void	alloc_coordinates_grid(t_map *map);
void	free_coordinates_grid(t_map *map);

//		-=""printers			/////////////////////////////////////////////
void	print_char_values_matrix(t_map *map);
void	print_char_colours_matrix(t_map *map);
void	print_int_values_matrix(t_map *map);
void	print_int_colours_matrix(t_map *map);

void	print_coordinates_grid(t_map *map);

//		-=""conversions			///////////////////////////////////////////////
void 	matrix_converter(t_map *map);
int		colour_converter(const char *hex_parts);
void	populate_int_values(t_map *map);
void	populate_int_colours(t_map *map);
int		ft_atoi_base(const char *parts, const char *base);
int		ft_isspace(char c);
int		get_base_len(const char *base);
int		is_valid_base(const char *base);
int		get_base_index(char c, const char *base);

#endif