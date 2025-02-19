/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:22:58 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/19 14:05:10 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/Libft/libft.h"
#include <math.h>

#define KEY_ESC 0xff1b
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100

typedef	struct s_map
{
	void	*mlx_ptr;
	int		x;
	int		y;
	int		z;
	int		scaling_factor;
	int		**z_matrix;
	int		**colours_matrix;
	int		***coordinates_grid;
	char	*line;
	char	**char_matrix_stash;
	char	***c_z_matrix;
	char	***c_colours_matrix;
	double	**conversion_grid;
	struct s_iso *iso;
	struct s_colour *colour;
	struct s_window *window;
	struct s_render *render;
}
t_map;

typedef	struct s_window
{
	void	*win_ptr;
	int		win_width;
	int		win_height;
}
t_window;

typedef	struct s_render
{
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	char	*buffer;
}
t_render;

typedef struct	s_colour
{
	int	red;
	int	green;
	int	blue;
	int	default_colour;
	int	current_colour;
	int	x_colour_grid;
	int	y_colour_grid;
	int	start_colour;
	int	end_colour;
	int	**rgb_grid;
}t_colour;

typedef	struct	s_iso
{
	double	min_x_iso;
	double	min_y_iso;
	double	max_x_iso;
	double	max_y_iso;
	double	pi_val;
	double	alpha;
	double	beta;
	double	cos_alpha;
	double	sin_alpha;
	double	cos_beta;
	double	sin_beta;
	double	cos;
	double	sin;
	double	x_iso;
	double	y_iso;
	int		x_scaled;
	int		y_scaled;
	int		z_scaled;
	int		offset_x;
	int		offset_y;
	int		sum_x_points;
	int		sum_y_points;
	int		center_x;
	int		center_y;


	double	x_shift;
	double	y_shift;
	double	zoom;

	double	x1;
	double	y1;
	double	x2;
	double	y2;

	int		dif_x;
	int		dif_y;
	int		step_drct_x;
	int		step_drct_y;
	int		err;
	int		temp_err;
}
t_iso;
	


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

void	scaling_coordinates(t_map *map);
void	iso_conversion_grid(t_map * map);
void	coordinates_shifting(t_map *map);
void	axis_point_calculation(t_map *map);
void	center_calculation(t_map *map);
void	draw_line(void *mlx, void *win, t_map *map, int current_colour);
int		dif_check(double a, double b, double epsilon);
void	draw_grid(void *mlx_ptr, void *win_ptr, t_map *map);
void	draw_vertical_lines(void *mlx_ptr, void *win_ptr, t_map *map);
void	draw_horizontal_lines(void *mlx_ptr, void *win_ptr, t_map *map);
double	find_x_iso_min(t_map *map);
double	find_y_iso_min(t_map *map);

int		render(t_map *map);
void	render_img (t_map *map);
void	put_pixel(t_map *map);
void	bresenham(t_map *map);

// void	iso_convertion(t_map *map);

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
void	free_rgb_grid(t_map *map);


void	alloc_coordinates_grid(t_map *map);
void	free_coordinates_grid(t_map *map);
void	alloc_conversion_grid(t_map *map);
void	free_conversion_grid(t_map *map);
t_map	*allocate_map(void);
t_map	*initialize_map(void);
void	initialize_other_fields(t_map *map);
void	initialize_iso_fields(t_iso *iso);
void	free_map_resources(t_map *map);

void	initialize_matrices(t_map *map);
void	init_row_pointers(t_map *map);
void	init_cell_pointers(t_map *map);

int		alloc_char_matrix_stash(t_map *map);
int		alloc_c_z_matrix(t_map *map);
int		alloc_c_colours_matrix(t_map *map);
void	char_matrix_alloc(t_map *map);


int		alloc_z_matrix(t_map *map);
int		alloc_colours_matrix(t_map *map);
void	int_matrix_alloc(t_map *map);

//		-=""printers			/////////////////////////////////////////////
// void	print_char_values_matrix(t_map *map);
// void	print_char_colours_matrix(t_map *map);
// void	print_int_values_matrix(t_map *map);
// void	print_int_colours_matrix(t_map *map);
// void	print_rgb_grid(t_map *map);
// void	print_coordinates_grid(t_map *map);
// void	print_conversion_grid(t_map *map);
// void	print_c_z_matrix(t_map *map);
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



//		-=""key handling			//////////////////////////////////////////
int		key_hook(int keycode, void *param);
int		close_window(void *param);


void	rgb_grid_populate(t_map *map);
void	rgb_management(t_map *map, int row, int col);
void	malloc_rgb_grid(t_map *map);




#endif