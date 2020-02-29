/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:10:40 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/29 21:06:25 by user             ###   ########.fr       */
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
# define BLUE 0x000066
# define WHITE 0xFFFFFF
#include <math.h>
#include <stdint.h>


typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

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
    int         start_line;
    int         finish_line;
    int         max_iteration;
    t_complex   min;
    t_complex   max;
    t_complex   k;
    t_complex   c;
    t_complex   factor;
    t_image     *image;
    int         color_shift;
    int         x;
    int         y;
    int         image_width;
    int         image_height;
    // int         min_re;
    // int         max_re;
    // int         min_im;
    // int         max_im;
    // int         re_factor;
    // int         im_factor;
    // int         c_im;
    // int         c_re;
    // int         z_re;
    // int         z_im;
    // int         z_re2;
    // int         z_im2;
    int				(*formula)(struct s_fractol *fractol);
    void        *mlx;
    void        *win;
    void        *img;
    int         bits_per_pixel;
    int         line_size;
    char        *pixels_arr;
    int         error;
    int         error2;
}               t_fractol;

void        ft_fractol_init(t_fractol *fractol);
void        ft_draw(t_fractol *fractol);
void        ft_draw2(t_fractol *fractol);
int         ft_fractol_init_img(t_fractol *fractol);
int         ft_init_hook(t_fractol *fractol);
int         ft_keyboard_hook(int key, void *param);
int         ft_close(void *param);
int		    iterate_mandelbrot(t_fractol *fractol);
void         ft_draw3(t_fractol *fractol);
t_complex   init_complex(double re, double im);

#endif