/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:08:50 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/26 17:24:48 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//                              fractol
// 1. входные данные Mondelbrot, julia, третий любой фрактал
// 2. фракталы должны увеличиваться по увеличению мышки
// 3. фракталу нужно установить цвета в зависимости от итераций
// 4. выход из программы на ESC
// 5. использовать image
// 6. если входной параметр не валидный или отсутствует - вывести какие параметры нужно вводить
// 7. zoom должен увелисивать по позиции мыши  
// 8. изменение цвета
// 9. 3d презентация 
// 10. два валидных параметра - два открытых окна
#include "fractol.h"
#include "mlx.h"
#include "fractol_key.h"
#include <stdlib.h>

int     ft_close(void *param)
{
    (void)param;
    exit(0);
}

t_complex   init_complex(double re, double im)
{
    t_complex complex;

    complex.re = re;
    complex.im = im;
    return (complex);
}


void    ft_default(t_fractol *fractol)
{
    fractol->max_iteration = 50;
    fractol->min = init_complex(-2.0, -2.0);
    fractol->max.re = 2.0;
    fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
    fractol->k = init_complex(-0.4, 0.6);
    fractol->color_shift = 0;
}

int     main()
{
    t_fractol   fractol;
    t_mouse     mouse;

    mouse.left_key = 0;
    mouse.right_key = 0;
    mouse.third_key = 0;

    // fractol = (t_fractol*)malloc(sizeof(t_fractol));
    // ft_fractol_init(&fractol);
    fractol.mlx = mlx_init();
    fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "fractol");
    ft_fractol_init_img(&fractol);
    // ft_default(&fractol);
    // ft_init_hook(&fractol);
    ft_draw(&fractol);
    mlx_loop(fractol.mlx);
}