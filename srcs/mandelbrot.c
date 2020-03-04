/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:18:54 by user              #+#    #+#             */
/*   Updated: 2020/03/04 13:56:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    mandelbrot_init(t_fractol *fractol)
{
    fractol->max_iteration = 50;
    fractol->zoom = 300;
    // fractol->x1 = -2.05;
    // fractol->y1 = -1.3;
    fractol->color = 265;
}

void    mandelbrot_calc(t_fractol *fractol)
{   
    fractol->min.re = -2.0;
    fractol->max.re = 1.0;
    fractol->min.im = -1.2;
    fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
    fractol->re_factor = (fractol->max.re - fractol->min.re) / (WIDTH);
    fractol->im_factor = (fractol->max.im - fractol->min.im) / (HEIGHT);
    fractol->max_iteration = 300;

    fractol->y = 0;
    while (fractol->y < HEIGHT)
    {
        fractol->c.im = fractol->max.im - fractol->y * fractol->im_factor;
        fractol->x = 0;
        while (fractol->x < WIDTH)
        {
            fractol->c.re = fractol->min.re + fractol->x * fractol->re_factor;
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
                mlx_pixel_put(fractol->mlx, fractol->win, fractol->x, fractol->y, GREEN);
            else
                mlx_pixel_put(fractol->mlx, fractol->win, fractol->x, fractol->y, WHITE);
                
            fractol->x++;
        }
        fractol->y++;
    }
    // for(int y=0; y<HEIGHT; ++y)
    // {
    //     double c_im = fractol->max_im - y*fractol->im_factor;
    //     for(int x=0; x<WIDTH; ++x)
    //     {
    //         double c_re = fractol->min_re + x*fractol->re_factor;

    //         double Z_re = c_re, Z_im = c_im;
    //         int isInside = 1;
    //         for(int n=0; n < fractol->max_iteration; ++n)
    //         {
    //             double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
    //             if(Z_re2 + Z_im2 > 4)
    //             {
    //                 isInside = 0;
    //                 break;
    //             }
    //             Z_im = 2*Z_re*Z_im + c_im;
    //             Z_re = Z_re2 - Z_im2 + c_re;
    //         }
    //         if(isInside)
    //             mlx_pixel_put(fractol->mlx, fractol->win, x, y, GREEN);
    //         else
    //             mlx_pixel_put(fractol->mlx, fractol->win, x, y, WHITE);
            
    //     }
    // }   
}

void    *mandelbrot(void *tab)
{
    t_fractol *fractol;
    int tmp;

    fractol = (t_fractol *)tab;
    fractol->x = 0;
    tmp = fractol->y;
    while (fractol->x < WIDTH)
    {
        fractol->y = tmp;
        while (fractol->y < fractol->y_max)
        {
            mandelbrot_calc(fractol);
            fractol->y++;
        }
        fractol->x++;
    }
    return (fractol);
}

void    mandelbrot_pthread(t_fractol *fractol)
{
    t_fractol tab[10];
    pthread_t   t[10];
    int i;

    i = 0;
    while (i < 10)
    {
        ft_memcpy((void*)&tab[i], (void*)fractol, sizeof(t_fractol));
        tab[i].y = 10 * i;
        tab[i].y_max = 10 * (i + 1);
        pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
        i++;
    }
    while (i--)
    {
        pthread_join(t[i], NULL);
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}