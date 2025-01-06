/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:22:58 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/06 15:23:02 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDH_H

#include "../lib/minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *mlx_window;
}
t_mlx;

int initialize_mlx(t_mlx *mlx);
void render(t_mlx *mlx);
int handle_key(int keycode, t_mlx *mlx);
void cleanup(t_mlx *mlx);

#endif