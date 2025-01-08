/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:14:31 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/08 11:11:40 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int handle_key(int keycode, t_app *app)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(app->win.mlx, app->win.win);
        exit(0);
    }
    return (0);
}

// #include "fdf.h"

// int handle_key(int keycode, t_app *app)
// {
//     if (keycode == 53) // Escape key
//     {
//         cleanup_windows(app);
//         // Returning 0 to let the main loop know we're done
//         return (0);
//     }
//     return (1);
// }
