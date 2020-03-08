/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:00:30 by rmaxima           #+#    #+#             */
/*   Updated: 2020/03/08 17:57:43 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int    in_button(int x, int y)
{
    if (y >= 0 && y < B_H)
        if (x >= 0 && x < MENU_W)
            return (1);
    return (0);
}

void    draw_help(t_fractol *fractol)
{
    int x;
    int y;

    y = 0;
    while (y < 500)
    {
        x = WIDTH - 100;
        while (x < WIDTH)
        {
            /* code */
        }
        
    }
}

void    draw_button(t_fractol *fractol)
{
    int x;
    int y;
    int i;

    i = 0;
    y = 0;
    while (y < B_H)
    {
        x = MENU_W;
        mlx_pixel_put(fractol->mlx, fractol->win, x, y, GREEN);
        x++;
        while (x <  WIDTH)
        {
            // i = (y * fractol->line_size) + (x * 4);
            // *((int *)&fractol->pixels_arr[i]) = 0x5500;
            i = 0;
            mlx_pixel_put(fractol->mlx, fractol->win, x, y, IVKLEIN);
            x++;
        }
        y++;
    }
    x = WIDTH - 200;
    while (x++ < WIDTH)
    {
        mlx_pixel_put(fractol->mlx, fractol->win, x, y, GREEN);
    }
    y = 0;
    x = WIDTH - 200;
    while (x++ < WIDTH)
    {
        mlx_pixel_put(fractol->mlx, fractol->win, x, y, GREEN);
    }
    x -= 2;
    while (y++ < 35)
         mlx_pixel_put(fractol->mlx, fractol->win, x, y, GREEN);
    mlx_string_put(fractol->mlx, fractol->win, WIDTH - 105, 5, GREEN, "MENU");
}