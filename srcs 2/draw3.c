/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:14:05 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/26 16:49:14 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
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

// t_complex   init_complex(double re, double im)
// {
//     t_complex complex;

//     complex.re = re;
//     complex.im = im;
//     return (complex);
// }

void    draw_fractal(t_fractol *fractol)
{
    int x;
    int y;
    t_color     color;


    y = fractol->start_line;
    while (y < fractol->finish_line)
    {
        fractol->c.im = fractol->max.im - y * fractol->factor.im;
        x = 0;
        while (x < WIDTH)
        {
            fractol->c.re = fractol->min.re + x * fractol->factor.re;
            color = get_color(iterate_mandelbrot(fractol), fractol);
            put_pixel(fractol, x, y, color);
            x++;
        }
        y++;
    }
    
}

void     ft_draw3(t_fractol *fractol)
{
    int i;

    fractol->factor = init_complex(
            (fractol->max.re - fractol->min.re) / (WIDTH - 1),
            (fractol->max.im - fractol->min.im) / (HEIGHT - 1));
    i = 0;
    while (i < 10)
    {
        fractol->start_line = i * (HEIGHT / 10);
        fractol->finish_line = (i + 1) * (HEIGHT / 10);
        i++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}