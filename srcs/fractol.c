/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:08:50 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/10 14:11:11 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

int     main()
{
    t_fractol   *fractol;
    t_mouse     mouse;

    mouse.left_key = 0;
    mouse.right_key = 0;
    mouse.third_key = 0;

    fractol = (t_fractol*)malloc(sizeof(t_fractol));
    // ft_fractol_init(&fractol);
    fractol->mlx = mlx_init();
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
    fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    ft_draw(fractol);
    mlx_loop(fractol->mlx);
}