/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:31:37 by user              #+#    #+#             */
/*   Updated: 2020/03/09 19:43:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractol_init(t_fractol *fractol)
{
	if (fractol->type == 1)
		mandelbrot_init(fractol);
	else if (fractol->type == 2)
		julia_init(fractol);
	else if (fractol->type == 3)
		burningship_init(fractol);
	else if (fractol->type == 4)
		mandelbar_init(fractol);
	else if (fractol->type == 5)
		celtic_mandelbrot_init(fractol);
	else if (fractol->type == 6)
		celtic_mandelbar_init(fractol);
	else if (fractol->type == 7)
		celtic_perpendicular_init(fractol);
	else if (fractol->type == 8)
		perpendicular_init(fractol);
	else if (fractol->type == 9)
		perpendicular_buffalo_init(fractol);
	fract_type(fractol);
}

t_fractol	*fractol_init_start(char *av, void *mlx)
{
	t_fractol *fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		exit(0);
	fractol->mlx = mlx;
	if (!(ft_name_fractol(av, fractol)))
		exit(0);
	ft_mlx_win_init(av, fractol);
	fractol->button = 0;
	fractol_init(fractol);
	ft_init_hook(fractol);
	draw_button(fractol);
	return (fractol);
}
