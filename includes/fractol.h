/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:10:40 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/07 17:25:19 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1200
# define HEIGHT 800
#include <math.h>

typedef enum		e_bool
{
	false,
	true
}                   t_bool;

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
}               t_fractol;

void        ft_fractol_init(t_fractol *fractol);
void        ft_draw(t_fractol *fractol);

#endif