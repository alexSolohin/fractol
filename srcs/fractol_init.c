/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:39:10 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/25 17:51:09 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

//unused file

// int     ft_fractol_init_img(t_fractol *fractol)
// {
//     int endian;

//     if (!(fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT)))
//         exit(-1);
//     fractol->bits_per_pixel = 32;
//     fractol->line_size = fractol->bits_per_pixel * WIDTH;
//     endian = ENDIAN;
//     fractol->pixels_arr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_size, &endian);
//     return (0);
// }


void        ft_fractol_init(t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
    fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    
}