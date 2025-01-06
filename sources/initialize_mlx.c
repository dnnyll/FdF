/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:30:30 by daniefe2          #+#    #+#             */
/*   Updated: 2025/01/06 12:54:22 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int initialize_mlx(t_mlx *mlx)
{
    mlx->mlx_ptr = mlx_init();
    if(!mlx->mlx_ptr)
        return (0);
    mlx->mlx_window = mlx_new_window(mlx->mlx_ptr, 800, 600, "FDF");
    if (!mlx->mlx_window)
        return (0);
    return (1);
}