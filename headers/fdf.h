/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:22:58 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/08 15:53:35 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDH_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/Libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

// Structure to hold the window and mlx pointers
typedef struct s_window
{
    void    *mlx;
    void    *win;
}
t_window;

// Main application structure
typedef struct s_app
{
    t_window win;
}   
t_app;

typedef struct s_map
{
    int **data;
    int rows;
    int cols;
    int height;
    int width;
}
t_map;

int initialize_mlx(t_app *app);
void render(t_app *app);
int handle_key(int keycode, t_app *app);
int handle_close(t_app *app);
void cleanup_window(t_app *app);
t_map	*initialize_map(char *filename);
void    parse_map_file(t_map *map, char filename);


#endif