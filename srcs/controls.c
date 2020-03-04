/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:01:16 by user              #+#    #+#             */
/*   Updated: 2020/03/04 19:55:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"
#include <stdio.h>

int     zoom(int x, int y, t_fractol *fractol)
{
    t_complex mouse;
    double      i;

    mouse = init_complex(
        (double)x / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
			(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
    i = 1.0 / 0.8;
    fractol->min.re = (mouse.re + (fractol->min.re - mouse.re) * i);
    fractol->min.im = (mouse.im + (fractol->min.im - mouse.im) * i);
    fractol->max.re = (mouse.re + (fractol->max.re - mouse.re) * i);
    fractol->max.im = (mouse.im + (fractol->max.im - mouse.im) * i);
    return (0);
}

int     zoom_out(int x, int y, t_fractol *fractol)
{
    t_complex mouse;
    double      i;

    mouse = init_complex(
        (double)x / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
			(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
    i = 1.0 / 1.2;
    fractol->min.re = (mouse.re + (fractol->min.re - mouse.re) * i);
    fractol->min.im = (mouse.im + (fractol->min.im - mouse.im) * i);
    fractol->max.re = (mouse.re + (fractol->max.re - mouse.re) * i);
    fractol->max.im = (mouse.im + (fractol->max.im - mouse.im) * i);
    return (0);
}

void     move(int key, t_fractol *fractol)
{
    if (key == ARROW_LEFT)
	{
		fractol->offset_y -= 0.1;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->offset_y += 0.1;
	}
	else if (key == ARROW_UP)
	{
		fractol->offset_x -= 0.1;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->offset_x += 0.1;
	}
}

void     colors(int key, t_fractol *fractol)
{
    if (key == MAIN_PAD_1)
        fractol->color = 0x34558b;
    else if (key == MAIN_PAD_2)
        fractol->color = 0xd13b40;
    else if (key == MAIN_PAD_3)
        fractol->color = 0x4ec5a5;
    else if (key == MAIN_PAD_4)
        fractol->color = 0x565d47;
    else if (key == MAIN_PAD_5)
        fractol->color = 0xfd823e;
    else if (key == MAIN_PAD_6)
        fractol->color = 0x117893;
    else if (key == MAIN_PAD_7)
        fractol->color = 0xf0daa4;
    else if (key == MAIN_PAD_8)
        fractol->color = 0xeaac9d;
    else if (key == MAIN_PAD_9)
        fractol->color = 0xeff0f1;
    else if (key == MAIN_PAD_0)
        fractol->color = 0x7367F0;
}

int     key_press(int key, t_fractol *fractol)
{
    if (key == MAIN_PAD_ESC)
        exit(0);
    else if (key == MAIN_PAD_I)
        fractol->color += 10;
    else if (key == MAIN_PAD_1 || key == MAIN_PAD_2 || 
                key == MAIN_PAD_3 || key == MAIN_PAD_4 || key == MAIN_PAD_5 ||
                key == MAIN_PAD_6 || key == MAIN_PAD_7 || key == MAIN_PAD_8 ||
                key == MAIN_PAD_9 || key == MAIN_PAD_0)
        colors(key, fractol);
    else if (key == MAIN_PAD_0)
        fractol->max_iteration -= 50;
    else if (key == ARROW_DOWN || key == ARROW_LEFT || key == ARROW_LEFT ||
             key == ARROW_UP)
        move(key, fractol);
    mandelbrot_draw(fractol);
    return (0);
}



int     mouse_hook(int key, int x, int y, t_fractol *fractol)
{
    if (key == MOUSE_SCROLL_UP || key == MOUSE_LEFT_BUTTON)
        zoom(x, y, fractol);
    else if (key == MOUSE_SCROLL_DOWN || key == MOUSE_RIGHT_BUTTON)
        zoom_out(x, y, fractol);
    mandelbrot_draw(fractol);
    return (0);
}