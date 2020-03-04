/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:10:40 by rmaxima           #+#    #+#             */
/*   Updated: 2020/03/04 19:39:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define THREADS 10
# define WIDTH 1200
# define HEIGHT 800
# define IMG_WIDTH 700
# define IMG_HEIGHT 400
# define ENDIAN 0
# define RED 0xFF0000
# define GREEN 0xFF00
# define BLUE 0x000066
# define IVKLEIN 0x3a75c4
# define WHITE 0xFFFFFF
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include "libft.h"
#include "mlx.h"

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

typedef struct s_colors
{
    int         colors[25];
}               t_colors;

typedef struct s_fractol
{
    int         max_iteration;
    int         iteration;
    int         x;
    int         y;
    int         color;
    int         image_width;
    int         image_height;
    double         zoom;
    t_complex       min;
    t_complex       max;
    t_complex       c;
    t_complex       z;
    t_complex       k;
    double         min_re;
    double         max_re;
    double         min_im;
    double         max_im;
    double         re_factor;
    double         im_factor;
    // double         c_im;
    // double         c_re;
    // double         z_re;
    // double         z_im;
    double         z_re2;
    double         z_im2;
    double         offset_x;
    double         offset_y;
    int         julia_mouse;
    double      tmp;
    int         start;
    int         end;
    void        *img_ptr;
    void        *mlx;
    void        *win;
    void        *img;
    int         endian;
    int         type;
    int         bits_per_pixel;
    int         line_size;
    char        *pixels_arr;
    int         inside;
}               t_fractol;

/*
**			<====================== start util ======================>
*/
int		    ft_close(void *param);
void        put_pxl_to_img(t_fractol *fractol, int x, int y, int color);
t_complex	init_complex(double re, double im);
/*
**			<====================== end util ======================>
*/
/*
**			<====================== start fractol.c ======================>
*/
void        fract_type(t_fractol *fractol);
void        fractol_init(t_fractol *fractol);
void        ft_mlx_win_init(t_fractol *fractol);
int         ft_name_fractol(char *av, t_fractol *fractol);
/*
**			<====================== end fractol.c ======================>
*/
/*
**			<====================== start controls.c ======================>
*/
int         key_press(int key, t_fractol *fractol);
int         mouse_hook(int key, int x, int y, t_fractol *fractol);

/*
**			<====================== end controls.c ======================>
*/
void    *mandelbrot(void *tab);
void    mandelbrot_pthread(t_fractol *fractol);
void    mandelbrot_init(t_fractol *fractol);
void    mandelbrot_draw(t_fractol *fractol);
/*
**			<====================== start julia.c ======================>
*/
void        julia_draw(t_fractol *fractol);
void        julia_init(t_fractol *fractol);
int         julia_motion(int x, int y, t_fractol *fractol);
/*
**			<====================== end julia.c ======================>
*/
#endif