/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:23:13 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/26 17:24:10 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

// t_complex   init_complex(double re, double im)
// {
//     t_complex complex;

//     complex.re = re;
//     complex.im = im;
//     return (complex);
// }

unsigned long createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int     calculate_color(int i, int max_i)
{
    double t;
    int color;

    t = (double)i / (double)max_i;
    color = 0;
    int red = (int)(9 * (1 - t) * pow(t, 3) * 255);
    int green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
    int blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
    
    
    return (createRGB(red, green, blue));
}

void        ft_draw(t_fractol *fractol)
{
       // first version
    unsigned max_iterations;
    unsigned x;
    unsigned y;
    unsigned n;
    // t_complex min;
    
    fractol->min_re = -2.0;
    fractol->max_re = 2.0;
    fractol->min_im = -2.0;
    fractol->max_im = fractol->min_im + (fractol->max_re - fractol->min_re) * HEIGHT/WIDTH;
    fractol->re_factor = (fractol->max_re - fractol->min_re) / (WIDTH - 1);
    fractol->im_factor = (fractol->max_im - fractol->min_im) / (HEIGHT - 1);
    max_iterations = 50;

    y = 0;
    while (y < HEIGHT)
    {
        fractol->c_im = fractol->max_im - y * fractol->im_factor;
        x = 0;
        while (x < WIDTH)
        {
            fractol->c_re = fractol->min_re + x*fractol->re_factor;
            fractol->z_re = fractol->c_re;
            fractol->z_im = fractol->c_im;
            t_bool is_inside = true;
            n = 0;
            while (n < max_iterations)
            {
                fractol->z_re2 = fractol->z_re * fractol->z_re;
                fractol->z_im2 = fractol->z_im * fractol->z_im;
                if(fractol->z_re2 + fractol->z_im2 > 4)
                {
                    is_inside = false;
                    break;
                }
                fractol->z_im = 2 * fractol->z_re * fractol->z_im + fractol->c_im;
                fractol->z_re = fractol->z_re2 - fractol->z_im2 + fractol->c_re;
                n++;
            }
            if (is_inside)
                mlx_pixel_put(fractol, fractol->win, x, y, GREEN);
            x++;
        }
        y++;
    }
}
    //mondelbrot
    
  
    
    //draw
    
    // int x;
    // int y;

    // y = 0;
    // while (y < HEIGHT - 1)
    // {
    //     x = 0;
    //     while (x < WIDTH - 1)
    //     {
    //         ft_draw_line(ft_point(x, y), ft_point(x + 1, y), fractol);
    //         ft_draw_line(ft_point(x, y), ft_point(x, y + 1), fractol);
    //         x++;
    //     }
    //     y++;
    // }

    //     void        ft_draw_line(t_point p0, t_point p1, t_fractol *fractol)
    //     {
    //     const int	deltax = FT_ABS(p1.x - p0.x);
    //     const int	deltay = FT_ABS(p1.y - p0.y);
    //     const int	signx = p0.x < p1.x ? 1 : -1;
    //     const int	signy = p0.y < p1.y ? 1 : -1;
        
    //     fractol->error = deltax - deltay;
    //     mlx_pixel_put(fractol, fractol->win, p1.x, p1.y, GREEN);
    //     while (p0.x != p1.x || p0.y != p1.y)
    //     {
    //         mlx_pixel_put(fractol, fractol->win, p0.x, p0.y, GREEN);
    //         fractol->error2 = fractol->error * 2;
    //         if (fractol->error2 > -deltay)
    //         {
    //             fractol->error -= deltay;
    //             p0.x += signx;
    //         }
    //         if (fractol->error2 < deltax)
    //         {
    //             fractol->error += deltax;
    //             p0.y += signy;
    //         }
    //     }
    // }

    // t_point ft_point(int x, int y)
    // {
    //     t_point p;

    //     p.x = x;
    //     p.y = y;
    //     return (p);
    // }


    //first version
    // unsigned max_iterations;
    // unsigned x;
    // unsigned y;
    // unsigned n;
    // t_complex min;
    
    // fractol->min_re = -2.0;
    // fractol->max_re = 2.0;
    // fractol->min_im = -2.0;
    // fractol->max_im = fractol->min_im + (fractol->max_re - fractol->min_re) * HEIGHT/WIDTH;
    // fractol->re_factor = (fractol->max_re - fractol->min_re) / (WIDTH - 1);
    // fractol->im_factor = (fractol->max_im - fractol->min_im) / (HEIGHT - 1);
    // max_iterations = 50;

    // y = 0;
    // while (y < HEIGHT)
    // {
    //     fractol->c_im = fractol->max_im - y * fractol->im_factor;
    //     x = 0;
    //     while (x < WIDTH)
    //     {
    //         fractol->c_re = fractol->min_re + x*fractol->re_factor;
    //         fractol->z_re = fractol->c_re;
    //         fractol->z_im = fractol->c_im;
    //         t_bool is_inside = true;
    //         n = 0;
    //         while (n < max_iterations)
    //         {
    //             fractol->z_re2 = fractol->z_re * fractol->z_re;
    //             fractol->z_im2 = fractol->z_im * fractol->z_im;
    //             if(fractol->z_re2 + fractol->z_im2 > 4)
    //             {
    //                 is_inside = false;
    //                 break;
    //             }
    //             fractol->z_im = 2 * fractol->z_re * fractol->z_im + fractol->c_im;
    //             fractol->z_re = fractol->z_re2 - fractol->z_im2 + fractol->c_re;
    //             n++;
    //         }
    //         if (is_inside)
    //             mlx_pixel_put(fractol, fractol->win, x, y, GREEN);
    //         x++;
    //     }
    //     y++;