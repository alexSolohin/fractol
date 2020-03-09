/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:55:55 by user              #+#    #+#             */
/*   Updated: 2020/03/09 15:27:22 by user             ###   ########.fr       */
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
        julia_pthread(fractol);
    else if (fractol->type == 3)
        burningship_pthread(fractol);
    else if (fractol->type == 4)
        mandelbar_pthread(fractol);
    else if (fractol->type == 5)
        celtic_mandelbrot_pthread(fractol);
    else if (fractol->type == 6)
        celtic_mandelbar_pthread(fractol);
    else if (fractol->type == 7)
        celtic_perpendicular_pthread(fractol);
    else if (fractol->type == 8)
        perpendicular_pthread(fractol);
    else if (fractol->type == 9)
        perpendicular_buffalo_pthread(fractol);
    draw_button(fractol);
    if (fractol->button)
        draw_help(fractol);
}

int     ft_name_fractol(char *av, t_fractol *fractol)
{
    fractol->type = 0;
    if (ft_strequ(av, "mandelbrot"))
        fractol->type = 1;
    else if (ft_strequ(av, "julia"))
        fractol->type = 2;
    else if (ft_strequ(av, "burningship"))
        fractol->type = 3;
    else if (ft_strequ(av, "mandelbar"))
        fractol->type = 4;
    else if (ft_strequ(av, "celtic_mandelbrot"))
        fractol->type = 5;
    else if (ft_strequ(av, "celtic_mandelbar"))
        fractol->type = 6;
    else if (ft_strequ(av, "celtic_perpendicular"))
        fractol->type = 7;
    else if (ft_strequ(av, "perpendicular"))
        fractol->type = 8;
    else if (ft_strequ(av, "perpendicular_buffalo"))
        fractol->type = 9;
    else
    {
        ft_putstr(av);
        ft_putendl(" is not a valid parameter");
    }
    return (fractol->type);
}
void    fractol_init(t_fractol *fractol)
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

void    ft_mlx_win_init(char *name, t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    if (!(fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, name)))
        exit(0);
    fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    fractol->pixels_arr = mlx_get_data_addr(fractol->img, 
        &fractol->bits_per_pixel, &fractol->line_size, &fractol->endian);
}

int     ft_init_hook(t_fractol *fractol)
{
    mlx_do_key_autorepeatoff(fractol->mlx);
    mlx_key_hook(fractol->win, key_press, fractol);
    mlx_hook(fractol->win, 17, 0, ft_close, fractol);
    if (fractol->type == 2)
        mlx_hook(fractol->win, 6, 0, julia_motion, fractol);
    mlx_hook(fractol->win, 4, 0, mouse_hook, fractol);
   return (0); 
}

int     main(int ac, char **av)
{
    t_fractol   *fractol;
    int i;
    
    if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
        exit(0);
    if (ac < 2)
        print();
    // else if (!(ft_name_fractol(av[1], fractol)))
    //     exit(0);
    if (ac >= 2)
    {
        i = 1;
            if (!(ft_name_fractol(av[1], fractol)))
                exit(0);
            ft_mlx_win_init(av[1], fractol);
            fractol->button = 0;
            fractol_init(fractol);
            ft_init_hook(fractol);
            draw_button(fractol);
            mlx_loop(fractol->mlx);

        // if (!(ft_name_fractol(av[2], fractol)))
        //     exit(0);
        // ft_mlx_win_init(av[2], fractol);
        // fractol_init(fractol);
        // ft_init_hook(fractol);
        // mlx_loop(fractol->mlx);
        
        
    }
    return (0);
}
