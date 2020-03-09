/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpendicular_buffalo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:36:30 by user              #+#    #+#             */
/*   Updated: 2020/03/09 20:21:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			perpendicular_buffalo_init(t_fractol *fractol)
{
	fractol->max_iteration = 100;
	fractol->min.re = -2.0;
	fractol->min.im = -1.5;
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im +
		(fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->color = 265;
}

static void		perpendicular_buffalo(t_fractol *fractol)
{
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
		fractol->z.im = -2 * fractol->z.re * fabs(fractol->z.im) + fractol->c.im;
		fractol->z.re = fabs(fractol->z_re2 - fractol->z_im2) + fractol->c.re;
		fractol->iteration++;
	}
}

void			perpendicular_buffalo_draw(t_fractol *fractol)
{
	fractol->re_factor = (fractol->max.re - fractol->min.re) / (WIDTH - 1);
	fractol->im_factor = (fractol->max.im - fractol->min.im) / (HEIGHT - 1);

	fractol->y = fractol->start;
	while (fractol->y < fractol->end)
	{
		fractol->c.im = fractol->max.im - (fractol->y * fractol->im_factor);
		fractol->x = 0;
		while (fractol->x < WIDTH)
		{
			fractol->c.re = fractol->min.re + (fractol->x * fractol->re_factor);
			fractol->z.re = fractol->c.re;
			fractol->z.im = fractol->c.im;
			fractol->inside = 1;
			perpendicular_buffalo(fractol);
			if (fractol->inside)
				put_pxl_to_img(fractol, fractol->x, fractol->y, WHITE);
			else
				put_pxl_to_img(fractol, fractol->x, fractol->y, (fractol->color * fractol->iteration));
			fractol->x++;
		}
		fractol->y++;
	}
}

void			perpendicular_buffalo_pthread(t_fractol *fractol)
{
	t_fractol	tab[THREADS];
	pthread_t	threads[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		tab[i] = *fractol;
		tab[i].start = i * (HEIGHT / THREADS);
		tab[i].end = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL, (void *(*)(void *))perpendicular_buffalo_draw, (void *)&tab[i]))
			exit(0);
		i++;
	}
	while (i-- > 0)
	{
		if (pthread_join(threads[i], NULL))
			exit(0);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
