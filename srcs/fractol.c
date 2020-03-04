/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:55:55 by user              #+#    #+#             */
/*   Updated: 2020/03/04 19:56:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"
#include <stdio.h>

void    fract_type(t_fractol *fractol)
{
    if (fractol->max_iteration < 0)
        fractol->max_iteration = 0;
    if (fractol->type == 1)
        mandelbrot_pthread(fractol);
    else if (fractol->type == 2)
        printf("s");
        // julia_pthread(fractol);
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
        ft_putendl(" is not a valid");
    }
    return (fractol->type);
}
void    fractol_init(t_fractol *fractol)
{
    if (fractol->type == 1)
    {
        mandelbrot_init(fractol);
        mandelbrot_draw(fractol);
    }   
    else if (fractol->type == 2)
    {
        julia_init(fractol);
        julia_draw(fractol);
    }
    // fract_type(fractol);
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
        mlx_key_hook(fractol->win, key_press, fractol);
        mlx_hook(fractol->win, 17, 0, ft_close, fractol);
        if (fractol->type == 2)
            mlx_hook(fractol->win, 6, 0, julia_motion, fractol);
        mlx_hook(fractol->win, 4, 0, mouse_hook, fractol);
        mlx_loop(fractol->mlx);
    }
    else
    {
        printf("stop");
    }
    return (0);
}
