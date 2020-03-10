/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:01:16 by user              #+#    #+#             */
/*   Updated: 2020/03/10 15:54:36 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"
#include <stdio.h>

static int		zoom(int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		i;

	mouse = init_complex(
		(double)x / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
			(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
	i = 1.4;
	fractol->min.re = (mouse.re + (fractol->min.re - mouse.re) * i);
	fractol->min.im = (mouse.im + (fractol->min.im - mouse.im) * i);
	fractol->max.re = (mouse.re + (fractol->max.re - mouse.re) * i);
	fractol->max.im = (mouse.im + (fractol->max.im - mouse.im) * i);
	fractol->max_iteration++;
	return (0);
}

static int		zoom_out(int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		i;

	mouse = init_complex(
		(double)x / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
			(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
	i = 0.4;
	fractol->min.re = (mouse.re + (fractol->min.re - mouse.re) * i);
	fractol->min.im = (mouse.im + (fractol->min.im - mouse.im) * i);
	fractol->max.re = (mouse.re + (fractol->max.re - mouse.re) * i);
	fractol->max.im = (mouse.im + (fractol->max.im - mouse.im) * i);
	return (0);
}

static void		move(int key, t_fractol *fractol)
{
	if (key == ARROW_RIGHT)
	{
		fractol->min.re -= (fractol->max.re - fractol->min.re) * 0.05;
		fractol->max.re -= (fractol->max.re - fractol->min.re) * 0.05;
	}
	else if (key == ARROW_LEFT)
	{
		fractol->min.re += (fractol->max.re - fractol->min.re) * 0.05;
		fractol->max.re += (fractol->max.re - fractol->min.re) * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im += (fractol->max.im - fractol->min.im) * 0.05;
		fractol->max.im += (fractol->max.im - fractol->min.im) * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im -= (fractol->max.im - fractol->min.im) * 0.05;
		fractol->max.im -= (fractol->max.im - fractol->min.im) * 0.05;
	}
}

int				key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == MAIN_PAD_P)
		fractol->color += 10;
	else if (key == MAIN_PAD_1 || key == MAIN_PAD_2 ||
				key == MAIN_PAD_3 || key == MAIN_PAD_4 || key == MAIN_PAD_5 ||
				key == MAIN_PAD_6 || key == MAIN_PAD_7 || key == MAIN_PAD_8 ||
				key == MAIN_PAD_9 || key == MAIN_PAD_0)
		colors(key, fractol);
	else if (key == MAIN_PAD_LESS)
		fractol->max_iteration -= 5;
	else if (key == MAIN_PAD_MORE)
		fractol->max_iteration += 5;
	else if (key == ARROW_DOWN || key == ARROW_LEFT || key == ARROW_RIGHT ||
			key == ARROW_UP)
		move(key, fractol);
	fract_type(fractol);
	return (0);
}

int				mouse_hook(int key, int x, int y, t_fractol *fractol)
{
	if (key == MOUSE_SCROLL_UP || key == MOUSE_RIGHT_BUTTON)
		zoom(x, y, fractol);
	else if ((key == MOUSE_SCROLL_DOWN || key == MOUSE_LEFT_BUTTON) &&
				!in_button(x, y) && y > 0)
		zoom_out(x, y, fractol);
	if (key == MOUSE_LEFT_BUTTON && in_button(x, y))
		fractol->button ^= 1;
	fract_type(fractol);
	return (0);
}
