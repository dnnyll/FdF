/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:06:15 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/08 11:06:57 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    cleanup_window(t_app *app)
{
    if (app->win.win)
        mlx_destroy_window(app->win.mlx, app->win.mlx);
    if(app->win.mlx)
    {
        mlx_destroy_display(app->win.mlx);
        free(app->win.mlx);
    }
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

