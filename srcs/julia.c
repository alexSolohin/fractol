/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:38:41 by user              #+#    #+#             */
/*   Updated: 2020/03/04 18:42:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_motion(int x, int y, t_fractol *fractol)
{
    if (fractol->julia_mouse == 1)
    {
        fractol->k = init_complex(
            4 * ((double)x / WIDTH - 0.5),
            4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
    }
    julia_draw(fractol);
    return (0);
}

void    julia_init(t_fractol *fractol)
{
    fractol->max_iteration = 50;
    fractol->min.re = -2.0;
    fractol->min.im = -1.9;
    fractol->julia_mouse = 1;
    fractol->c.re = 0.285;
    fractol->c.im = 0.01;
}

void    julia_draw(t_fractol *fractol)
{
    fractol->y = 0;
    while (fractol->y < HEIGHT)
    {
        fractol->x = 0;
        while (fractol->x < WIDTH)
        {
            fractol->z.re = fractol->c.re;
            fractol->z.im = fractol->c.im;
            fractol->inside = 1;
            fractol->iteration = 0;
            while (fractol->iteration < fractol->max_iteration)
            {
                fractol->z_re2 = fractol->z.re * fractol->z.re;
                fractol->z_im2 = fractol->z.im * fractol->z.im;
                if (fractol->z_re2 + fractol->z_im2 > 4)
                {
                    fractol->inside = 0;
                    break;
                }
                fractol->z.im = 2 * fractol->z.re * fractol->z.im + fractol->k.im;
                fractol->z.re = fractol->z_re2 - fractol->z_im2 + fractol->k.re;
                fractol->iteration++;
            }
            if (fractol->inside)
                put_pxl_to_img(fractol, fractol->x, fractol->y, WHITE);
            else
                put_pxl_to_img(fractol, fractol->x, fractol->y, (fractol->color * fractol->iteration));
            fractol->x++;
        }
        fractol->y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);  
}
