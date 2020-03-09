/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:38:41 by user              #+#    #+#             */
/*   Updated: 2020/03/09 15:13:11 by user             ###   ########.fr       */
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
    fract_type(fractol);
    return (0);
}

void    julia_init(t_fractol *fractol)
{
    fractol->max_iteration = 100;
    fractol->min.re = -2.0;
    fractol->min.im = -1.5;
    fractol->max.re = 2.0;
    fractol->max.im = fractol->min.im + 
        (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
    fractol->k = init_complex(-0.4, 0.6);
    fractol->julia_mouse = 1;
    fractol->color = 265;
}

void    julia_draw(t_fractol *fractol)
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
}

void    julia_pthread(t_fractol *fractol)
{
    t_fractol   tab[THREADS];
    pthread_t   threads[THREADS];
    int i;

    i = 0;
    while (i < THREADS)
    {
        tab[i] = *fractol;
        tab[i].start = i * (HEIGHT / THREADS);
        tab[i].end = (i + 1) * (HEIGHT / THREADS);
        if (pthread_create(&threads[i], NULL, (void *(*)(void *))julia_draw, (void *)&tab[i]))
            exit(0);
        i++;
    }
    while (i-- > 0)
        if (pthread_join(threads[i], NULL))
            exit(0);
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0); 
}
