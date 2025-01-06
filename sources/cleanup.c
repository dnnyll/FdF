/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:06:15 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/06 13:17:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    cleanup(t_mlx *mlx)
{
    if (mlx->mlx_window)
        mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
    exit (0);
}

// void cleanup_windows(t_app *app)
// {
//     if (!app)
//         return;
//     if (app->win.img)
//         mlx_destroy_image(app->win.mlx, app->win.img);
//     if (app->win.win)
//         mlx_destroy_window(app->win.mlx, app->win.win);
//     if (app->win.mlx)
//     {
//         mlx_destroy_display(app->win.mlx);
//         free(app->win.mlx);
//     }
//     app->win.img = NULL;
//     app->win.win = NULL;
//     app->win.mlx = NULL;
// }

