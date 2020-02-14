/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:10:40 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/11 15:54:42 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define FT_ABS(x) (((x) < 0) ? (-(x)) : (x))
# define WIDTH 1200
# define HEIGHT 800
# define IMG_WIDTH 700
# define IMG_HEIGHT 400
# define ENDIAN 0
# define RED 0xFF0000
# define GREEN 0xFF00
# define BLUE 0xFF
#include <math.h>

typedef enum		e_bool
{
	false,
	true
}                   t_bool;

typedef struct      s_complex
{
    double          re;
    double          im;
}                   t_complex;


typedef struct  s_point
{
    int         x;
    int         y;
    unsigned    rgb;
}               t_point;


typedef struct s_mouse
{
    int         left_key;
    int         right_key;
    int         third_key;
    int         x0;
    int         y0;
    int         x1;
    int         y1;    
}               t_mouse;

typedef struct s_fractol
{
    int         x;
    int         y;
    int         image_width;
    int         image_height;
    void        *mlx;
    void        *win;
    void        *img;
    int         bits_per_pixel;
    int         line_size;
    char        *pixels_arr;
    int         error;
    int         error2;
    double      min_re;
    double      max_re;
    double      min_im;
    double      max_im;
    double      re_factor;
    double      im_factor;
    double      c_im;
    double      c_re;
    double      z_re;
    double      z_re2;
    double      z_im;
    double      z_im2;
}               t_fractol;

void        ft_fractol_init(t_fractol *fractol);
void        ft_draw(t_fractol *fractol);

#endif