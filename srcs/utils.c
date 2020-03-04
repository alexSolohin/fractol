/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:02:42 by user              #+#    #+#             */
/*   Updated: 2020/03/04 19:41:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

void    put_pxl_to_img(t_fractol *fractol, int x, int y, int color)
{
    if (fractol->x < WIDTH && fractol->y < WIDTH)
    {
        color = mlx_get_color_value(fractol->mlx, color);
        ft_memcpy(fractol->pixels_arr + 4 * WIDTH * y + x * 4, &color, sizeof(int));
    }
}

