/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:23:13 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/07 17:30:26 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void        ft_draw(t_fractol *fractol)
{
    double minRe = -2.0;
    double maxRe = 1.0;
    double minIm = -1.2;
    double maxIm;
    maxIm = minIm + (maxRe - minRe) * fractol->image_height / fractol->image_width;
    double re_fractol = (maxIm - minRe) / (fractol->image_width - 1);
    double im_fractol = (maxIm - minIm) / (fractol->image_height - 1);
    double c_re;
    double c_im;
    double z_re;
    double z_re2;
    double z_im;
    double z_im2;
    t_bool is_inside;
    int n;
    int max_iter = 30;
    int y;
    int x;

    y = 0;
    while (y < fractol->image_height)
    {
        c_im = maxIm - fractol->y * im_fractol;
        x = 0;
        while (x < fractol->image_width)
        {
            c_re = minRe + x * re_fractol;
            z_re = c_re;
            z_im = c_im;
            is_inside = true;
            n = 0;
            while (n < max_iter)
            {
                z_re2 = z_re * z_re;
                z_im2 = z_im * z_im;
                if (z_re2 + z_im2 > 4)
                {
                    is_inside = false;
                    break ;
                }
                z_im = 2 * z_re * z_im + c_im;
                z_re = z_re2 - z_im2 + c_re;
                if (is_inside)
                    mlx_pixel_put(fractol->mlx, fractol->win, x, y, 0xFFFFFF);
                n++;
            }
            x++;
        }
        y++;
    }
}