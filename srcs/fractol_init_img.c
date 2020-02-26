/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:40:39 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/25 16:55:58 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdlib.h>

int ft_fractol_init_img(t_fractol *fractol)
{
    int endian;

    if (!(fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT)))
        exit(-1);
    fractol->bits_per_pixel = 32;
    fractol->line_size = fractol->bits_per_pixel * WIDTH;
    endian = ENDIAN;
    fractol->pixels_arr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, 
        &fractol->line_size, &endian);
    return (0);
}