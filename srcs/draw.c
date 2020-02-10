/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:23:13 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/10 16:08:09 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"



void        ft_draw_line(t_point p0, t_point p1, t_fractol *fractol)
{
    const int	deltax = FT_ABS(p1.x - p0.x);
	const int	deltay = FT_ABS(p1.y - p0.y);
	const int	signx = p0.x < p1.x ? 1 : -1;
	const int	signy = p0.y < p1.y ? 1 : -1;
    
    fractol->error = deltax - deltay;
    mlx_pixel_put(fractol, fractol->win, p1.x, p1.y, GREEN);
    while (p0.x != p1.x || p0.y != p1.y)
    {
        mlx_pixel_put(fractol, fractol->win, p0.x, p0.y, GREEN);
        fractol->error2 = fractol->error * 2;
        if (fractol->error2 > -deltay)
        {
            fractol->error -= deltay;
            p0.x += signx;
        }
        if (fractol->error2 < deltax)
        {
            fractol->error += deltax;
            p0.y += signy;
        }
    }
}

t_point ft_point(int x, int y)
{
    t_point p;

    p.x = x;
    p.y = y;
    return (p);
}

void        ft_draw(t_fractol *fractol)
{
    
    //mondelbrot
    

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
        t_bool isInside = true;
        for(unsigned n=0; n<MaxIterations; ++n)
        {
            double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
            if(Z_re2 + Z_im2 > 4)
            {
                isInside = false;
                break;
            }
            Z_im = 2*Z_re*Z_im + c_im;
            Z_re = Z_re2 - Z_im2 + c_re;
        }
        if(isInside) { mlx_pixel_put(fractol, fractol->win, x, y, RED); }
    }
}
    
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
}