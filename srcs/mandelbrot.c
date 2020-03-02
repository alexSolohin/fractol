/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:18:54 by user              #+#    #+#             */
/*   Updated: 2020/03/02 19:09:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    mandelbrot_init(t_fractol *fractol)
{
    fractol->max_iteration = 50;
    fractol->zoom = 300;
    fractol->x1 = -2.05;
    fractol->y1 = -1.3;
    fractol->color = 265;
}

void    mandelbrot_calc(t_fractol *fractol)
{
    
    
    double MinRe = -2.0;
    double MaxRe = 1.0;
    double MinIm = -1.2;
    double MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
    double Re_factor = (MaxRe-MinRe)/(WIDTH-1);
    double Im_factor = (MaxIm-MinIm)/(HEIGHT-1);
    unsigned MaxIterations = 30;

    for(unsigned y=0; y<HEIGHT; ++y)
    {
        double c_im = MaxIm - y*Im_factor;
        for(unsigned x=0; x<WIDTH; ++x)
        {
            double c_re = MinRe + x*Re_factor;

            double Z_re = c_re, Z_im = c_im;
            int isInside = 1;
            for(unsigned n=0; n<MaxIterations; ++n)
            {
                double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
                if(Z_re2 + Z_im2 > 4)
                {
                    isInside = 0;
                    break;
                }
                Z_im = 2*Z_re*Z_im + c_im;
                Z_re = Z_re2 - Z_im2 + c_re;
            }
            if(isInside)
                mlx_pixel_put(fractol->mlx, fractol->win, x, y, GREEN);
            else
                mlx_pixel_put(fractol->mlx, fractol->win, x, y, WHITE);
            
        }
    }   
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