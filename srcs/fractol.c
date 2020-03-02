/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:55:55 by user              #+#    #+#             */
/*   Updated: 2020/03/02 18:53:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"
#include <stdio.h>

void    fract_calc(t_fractol *fractol)
{
    if (fractol->max_iteration < 0)
        fractol->max_iteration = 0;
    if (fractol->type == 1)
        mandelbrot_pthread(fractol);
    else if (fractol->type == 2)
        printf("julia");
}

int     ft_name_fractol(char *av, t_fractol *fractol)
{
    fractol->type = 0;
    if (ft_strequ(av, "mandelbrot"))
        fractol->type = 1;
    else if (ft_strequ(av, "julia"))
        fractol->type = 2;
    else
    {
        ft_putstr(av);
        ft_putendl(" is'n a valid");
    }
    return (fractol->type);
}
void    fractol_init(t_fractol *fractol)
{
    if (fractol->type == 1)
        mandelbrot_calc(fractol);
    else if (fractol->type == 2)
        printf("julia");
    // fract_calc(fractol);
}

void    ft_mlx_win_init(t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
    fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    fractol->pixels_arr = mlx_get_data_addr(fractol->img, 
        &fractol->bits_per_pixel, &fractol->line_size, &fractol->endian);
}

int     main(int ac, char **av)
{
    t_fractol   *fractol;

    if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
        return (0);
    if (!(ft_name_fractol(av[1], fractol)))
        return (0);
    if (ac == 2)
    {
        ft_mlx_win_init(fractol);
        fractol_init(fractol);
        mlx_hook(fractol->win, 2, 0, key_press, fractol);
        mlx_hook(fractol->win, 17, 0, ft_close, fractol);
        mlx_loop(fractol->mlx);
    }
    else
    {
        printf("stop");
    }
    
}
