/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:18:54 by user              #+#    #+#             */
/*   Updated: 2020/03/04 19:58:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    mandelbrot_init(t_fractol *fractol)
{
    fractol->max_iteration = 30;
    fractol->zoom = 1.2;
    fractol->min.re = -2.0;
    fractol->min.im = -1.0;
    fractol->color = 0x3a75c4;
}

void    mandelbrot_draw(t_fractol *fractol)
{   
    // fractol->min.re = -2.0;
    fractol->max.re = 1.0;
    // fractol->min.im = -1.0;
    fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
    fractol->re_factor = (fractol->max.re - fractol->min.re) / (WIDTH - 1);
    fractol->im_factor = (fractol->max.im - fractol->min.im) / (HEIGHT - 1);
    

    fractol->y = 0;//fractol->start;
    while (fractol->y < HEIGHT)
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
                fractol->z.im = 2 * fractol->z.re *fractol->z.im + fractol->c.im;
                fractol->z.re = fractol->z_re2 - fractol->z_im2 + fractol->c.re;
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
    mlx_string_put(fractol->mlx, fractol->win, 0, 0, GREEN,
		"Help");
}

// void    *mandelbrot(void *frac)
// {
//     t_fractol *fractol;
//     int i;

//     fractol = (t_fractol *)frac;

//     fractol->max.re = 1.0;
//     // fractol->min.im = -1.0;
//     fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
//     fractol->re_factor = (fractol->max.re - fractol->min.re) / (WIDTH - 1);
//     fractol->im_factor = (fractol->max.im - fractol->min.im) / (HEIGHT - 1);
//     fractol->y = 0;
//     i = fractol->x;
//     while (fractol->y < WIDTH)
//     {
//         fractol->c.im = (fractol->max.im * fractol->offset_x) - (fractol->y * fractol->im_factor);
//         fractol->x = i;
//         while (fractol->x < fractol->x_max)
//         {
//             fractol->c.re = (fractol->min.re * fractol->offset_y) + (fractol->x * fractol->re_factor);
//             fractol->z.re = fractol->c.re;
//             fractol->z.im = fractol->c.im;
//             fractol->inside = 1;
//             fractol->iteration = 0;
//             while (fractol->iteration < fractol->max_iteration)
//             {
//                 fractol->z_re2 = fractol->z.re * fractol->z.re;
//                 fractol->z_im2 = fractol->z.im * fractol->z.im;
//                 if (fractol->z_re2 + fractol->z_im2 > 4)
//                 {
//                     fractol->inside = 0;
//                     break;
//                 }
//                 fractol->z.im = 2 * fractol->z.re *fractol->z.im + fractol->c.im;
//                 fractol->z.re = fractol->z_re2 - fractol->z_im2 + fractol->c.re;
//                 fractol->iteration++;
//             }
//             if (fractol->inside)
//                 put_pxl_to_img(fractol, fractol->x, fractol->y, WHITE);
//             else
//                 put_pxl_to_img(fractol, fractol->x, fractol->y, (fractol->color * fractol->iteration));
//             fractol->x++;
//         }
//         fractol->y++;
//     }
//     return (frac);
// }


void    mandelbrot_pthread(t_fractol *fractol)
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
        pthread_create(&threads[i], NULL, (void *(*)(void *))mandelbrot_draw, (void *)&tab[i]);
        i++;
    }
    while (i-- > 0)
    {
        pthread_join(threads[i], NULL);
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}