/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:02:42 by user              #+#    #+#             */
/*   Updated: 2020/03/06 17:09:31 by user             ###   ########.fr       */
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

void    print()
{
    ft_putendl("Usage ./fractol <name>");
	ft_putchar('\n');
    ft_putendl("List of fractols:");
	ft_putchar('\n');
    ft_putendl("-mandelbrot");
    ft_putendl("-julia");
    ft_putendl("-burningship");
    ft_putendl("-mandelbar");
    ft_putendl("-celtic_mandelbrot");
    ft_putendl("-celtic_mandelbar");
    ft_putendl("-celtic_perpendicular");
    ft_putendl("-perpendicular");
    ft_putendl("-perpendicular_buffalo");
	ft_putchar('\n');
}
