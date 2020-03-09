/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:10:40 by rmaxima           #+#    #+#             */
/*   Updated: 2020/03/09 15:16:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define THREADS 100
# define WIDTH 1200
# define HEIGHT 800
# define IMG_WIDTH 700
# define IMG_HEIGHT 400
# define ENDIAN 0
# define MENU_W WIDTH - 200
# define BUTTONS_NUM 11
# define B_H 35
# define B_TEXT_COLOR 0xDD999999
# define RED 0xFF0000
# define GREEN 0xFF00
# define BLUE 0x000066
# define IVKLEIN 0x3a75c4
# define WHITE 0xFFFFFF

#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <math.h>
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
    int             button;
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
void        print();
/*
**			<====================== end util ======================>
*/
/*
**			<====================== start fractol.c ======================>
*/
void        fract_type(t_fractol *fractol);
void        fractol_init(t_fractol *fractol);
void        ft_mlx_win_init(char *name, t_fractol *fractol);
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
/*
**			<====================== start mandelbrot.c ======================>
*/
void        *mandelbrot(void *tab);
void        mandelbrot_pthread(t_fractol *fractol);
void        mandelbrot_init(t_fractol *fractol);
void        mandelbrot_draw(t_fractol *fractol);
/*
**			<====================== end mandelbrot.c ======================>
*/
/*
**			<====================== start julia.c ======================>
*/
void        julia_draw(t_fractol *fractol);
void        julia_init(t_fractol *fractol);
void        julia_pthread(t_fractol *fractol);
int         julia_motion(int x, int y, t_fractol *fractol);
/*
**			<====================== end julia.c ======================>
*/
/*
**			<====================== start burningship.c ======================>
*/
void        burningship_init(t_fractol *fractol);
void        burningship_draw(t_fractol *fractol);
void        burningship_pthread(t_fractol *fractol);
/*
**			<====================== end burningship.c ======================>
*/
/*
**			<====================== start mandelbar.c ======================>
*/
void        mandelbar_init(t_fractol *fractol);
void        mandelbar_draw(t_fractol *fractol);
void        mandelbar_pthread(t_fractol * fractol);
/*
**			<====================== end mandelbar.c ======================>
*/
/*
**			<====================== start celtic_mandelbrot.c ======================>
*/
void        celtic_mandelbrot_init(t_fractol *fractol);
void        celtic_mandelbrot_draw(t_fractol *fractol);
void        celtic_mandelbrot_pthread(t_fractol *fractol);
/*
**			<====================== end celtic_mandelbrot.c ======================>
*/
/*
**			<====================== start celtic_mandelbar.c ======================>
*/
void        celtic_mandelbar_init(t_fractol *fractol);
void        celtic_mandelbar_draw(t_fractol *fractol);
void        celtic_mandelbar_pthread(t_fractol *fractol);
/*
**			<====================== end celtic_mandelbar.c ======================>
*/
/*
**			<====================== start celtic_perpendicular.c ======================>
*/
void        celtic_perpendicular_init(t_fractol *fractol);
void        celtic_perpendicular_draw(t_fractol *fractol);
void        celtic_perpendicular_pthread(t_fractol *fractol);
/*
**			<====================== end celtic_perpendicular.c ======================>
*/
/*
**			<====================== start perpendicular.c ======================>
*/
void        perpendicular_init(t_fractol *fractol);
void        perpendicular_draw(t_fractol *fractol);
void        perpendicular_pthread(t_fractol *fractol);
/*
**			<====================== end perpendicular.c ======================>
*/
/*
**			<====================== start perpendicular_buffalo.c ======================>
*/
void        perpendicular_buffalo_init(t_fractol *fractol);
void        perpendicular_buffalo_draw(t_fractol *fractol);
void        perpendicular_buffalo_pthread(t_fractol *fractol);
/*
**			<====================== end perpendicular_buffalo.c ======================>
*/
/*
**			<====================== start menu.c ======================>
*/
void        draw_button(t_fractol *fractol);
int         in_button(int x, int y);
void        draw_help(t_fractol *fractol);
/*
**			<====================== end menu.c ======================>
*/
#endif