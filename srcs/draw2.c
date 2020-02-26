/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:40:17 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/26 17:16:38 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

int     calculate_color(int i, int max_i)
{
    double t;
    int color;

    t = (double)i / (double)max_i;
    color = 0;
    int red = (int)(9 * (1 - t) * pow(t, 3) * 255);
    int green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    int blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
    
    color += red + green + blue;
    return (color);
}

// t_complex   init_complex(double re, double im)
// {
//     t_complex complex;

//     complex.re = re;
//     complex.im = im;
//     return (complex);
// }

# include <stdint.h>

t_color	get_color(int iteration, t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)iteration / fractol->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

void    put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
    int i;

    i = (x * fractol->bits_per_pixel / 8)
        + (y * fractol->line_size);
    fractol->pixels_arr[i] = color.channel[3];
    fractol->pixels_arr[++i] = color.channel[2];
    fractol->pixels_arr[++i] = color.channel[1];
    fractol->pixels_arr[++i] = color.channel[0];
}

void    ft_draw2(t_fractol *fractol)
{
    t_color     color;
    t_complex min;
    t_complex factor;
    min = init_complex(-2.0, -2.0);
    t_complex max;
    t_complex c;
    t_complex z;
    max.re = 2.0;
    max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
    factor = init_complex((max.re - min.re) / (WIDTH - 1), (max.im - min.im) / (HEIGHT - 1));
    int max_iterator = 50;
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        c.im = max.im - y * factor.im;
        x = 0;
        while (x < WIDTH)
        {
            c.re = min.re + x * factor.re;
            z = init_complex(c.re, c.im);
            int i = 0;
            while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < max_iterator)
            {
                z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re, 2.0 * z.re * z.im + c.im);
                i++;
            }
            color = get_color(i, fractol);
            mlx_pixel_put(fractol, fractol->win, x, y, GREEN);
            x++;
        }
        y++;
    }
    
}