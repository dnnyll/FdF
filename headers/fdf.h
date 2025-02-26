/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:22:58 by daniefe2          #+#    #+#             */
/*   Updated: 2025/02/26 16:23:31 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define KEY_ESC 0xff1b
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/Libft/libft.h"
# include <math.h>

typedef struct s_map
{
	int				result;
	int				sign;
	int				endian;
	char			*buffer;
	int				bpp;
	int				size_line;
	int				x;
	int				y;
	int				z;
	int				**z_matrix;
	int				**colours_matrix;
	char			*line;
	char			**char_matrix_stash;
	char			***c_z_matrix;
	char			***c_colours_matrix;
	int				***coordinates_grid;
	double			**conversion_grid;
	double			epsilon;
	int				scaling_factor;
	struct s_iso	*iso;
	struct s_colour	*colour;
	struct s_window	*window;
}t_map;
typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
}t_window;
typedef struct s_colour
{
	int	default_colour;
	int	**rgb_grid;
	int	x_colour_grid;
	int	y_colour_grid;
}t_colour;
typedef struct s_iso
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
	double	x_shift;
	double	y_shift;
	double	zoom;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	int		x_scaled;
	int		y_scaled;
	int		z_scaled;
	int		offset_x;
	int		offset_y;
	int		sum_x_points;
	int		sum_y_points;
	int		center_x;
	int		center_y;
	int		dif_x;
	int		dif_y;
	int		step_drct_x;
	int		step_drct_y;
	int		err;
	int		temp_err;
}t_iso;
//	-=	atoi_base			//////////////////////////////////////////////
int		ft_isspace(char c);
int		get_base_len(const char *base);
int		is_valid_base(const char *base);
int		get_base_i(char c, const char *base);
int		ft_atoi_base(t_map *map, const char *str, const char *base);
//	-=	bersenham			//////////////////////////////////////////////
void	setup_direction(t_map *map);
int		validate_and_set_pixel(t_map *map, int current_colour);
void	draw_line(void *mlx, void *win, t_map *map, int current_colour);
int		dif_check(double a, double b, double epsilon);
//	-=	convert_to_int			//////////////////////////////////////////
void	matrix_converter(t_map *map);
int		colour_converter(t_map *map, const char *hex_str);
void	populate_int_values(t_map *map);
void	populate_int_colours(t_map *map);
//	-=	coordinates_shifting			//////////////////////////////////
void	axis_point_calculation(t_map *map);
void	center_calculation(t_map *map);
void	coordinates_shifting(t_map *map);
//	-=	coodinates_grid			//////////////////////////////////////////
void	alloc_coordinates_row(t_map *map, int row);
void	alloc_coordinates_grid(t_map *map);
//	-=	initialize_map;			//////////////////////////////////////////
void	initialize_other_fields(t_map *map);
void	initialize_iso_fields(t_iso *iso);
void	initialize_map_fields(t_map *map);
t_map	*initialize_map(void);
//	-=	initialize_matrices			//////////////////////////////////////
void	initialize_matrices(t_map *map);
void	init_row_pointers(t_map *map);
void	init_cell_pointers(t_map *map);
//	-=	input_checks				//////////////////////////////////////
void	open_file_check(t_map *map, int fd);
void	valid_char_check(t_map *map);
void	empty_check(t_map *map, int fd);
void	valid_hex_check(t_map *map, int i);
int		ft_isxdigit(char c);
void	check_fdf_file(const char *filename);
//	-=	iso_conversion			//////////////////////////////////////////
void	scaling_coordinates(t_map *map);
void	alloc_conversion_grid(t_map *map);
void	iso_conversion_grid(t_map *map);
double	find_x_iso_min(t_map *map);
double	find_y_iso_min(t_map *map);
//	-=	map_parsing			//////////////////////////////////////////////
void	store_map_lines(t_map *map, int fd);
void	process_lines(t_map *map);
void	process_parts(t_map *map, int row, int col);
void	read_map_repeat(t_map *map, char *filename);
//	-=	operations			//////////////////////////////////////////////
void	operation_launch(t_map *map);
void	operation_free(t_map *map);
void	operation_mlx(t_map *map);
//	-=	read_map			//////////////////////////////////////////////
void	read_map_size(t_map *map, char *filename);
void	read_map_width(t_map *map, char *line, int fd);
int		is_empty_spaces(char *line);
int		count_line_elements(char **parts);
void	free_split_result(char **parts);
//	-=	rendering_projection			//////////////////////////////////
void	draw_grid(void *mlx_ptr, void *win_ptr, t_map *map);
void	draw_horizontal_lines(void *mlx_ptr, void *win_ptr, t_map *map);
void	draw_vertical_lines(void *mlx_ptr, void *win_ptr, t_map *map);
//	-=	set_pixel			//////////////////////////////////////////////
void	set_pixel(t_map *map, int current_colour);
//	-=	alloc_char_matrix	//////////////////////////////////////////////
int		alloc_char_matrix_stash(t_map *map);
int		alloc_c_z_matrix(t_map *map);
int		alloc_c_colours_matrix(t_map *map);
void	char_matrix_alloc(t_map *map);
//	-=	alloc_int_matrix	//////////////////////////////////////////////
int		alloc_z_matrix(t_map *map);
int		alloc_colours_matrix(t_map *map);
void	int_matrix_alloc(t_map *map);
//	-=	free_grids	//////////////////////////////////////////////////////
void	free_t_map(t_map *map);
void	free_conversion_grid(t_map *map);
void	free_rgb_grid(t_map *map);
void	free_coordinates_grid(t_map *map);
//	-=	free_matrix	//////////////////////////////////////////////////////
void	free_char_matrix_stash(t_map *map);
void	free_c_z_matrix(t_map *map);
void	free_c_colours_matrix(t_map *map);
void	free_z_matrix(t_map *map);
void	free_colours_matrix(t_map *map);
//	-=	free_ressources	//////////////////////////////////////////////////
void	free_map_ressources(t_map *map);
void	stop_map_inconsist(t_map *map);
//	-=	window_hooks	//////////////////////////////////////////////////
int		key_hook(int keycode, void *param);
int		close_window(void *param);
#endif