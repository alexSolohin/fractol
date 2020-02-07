/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:08:50 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/07 17:33:33 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int     main()
{
    t_fractol   fractol;
    t_mouse     mouse;

    mouse.left_key = 0;
    mouse.right_key = 0;
    mouse.third_key = 0;

    ft_fractol_init(&fractol);
    ft_draw(&fractol);
    mlx_loop(fractol.mlx);
}