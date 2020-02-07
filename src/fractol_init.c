/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:39:10 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/07 16:42:38 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void        ft_fractol_init(t_fractol *fractol)
{
    if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
        exit(-1);
    fractol->image_width = 1000;
    fractol->image_height = 500;
    fractol->mlx = mlx_init();
    fdf->win = mlx_new_image(fractol->mlx, )
}