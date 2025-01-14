/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:30:30 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/08 10:41:55 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int initialize_mlx(t_app *app)
{
    app->win.mlx = mlx_init();
    if(!app->win.mlx)
        return (0);
    app->win.win = mlx_new_window(app->win.mlx, 800, 600, "FDF");
    if (!app->win.mlx)
    {
        free(app->win.mlx);
        return (0);
    }
    return (1);
}