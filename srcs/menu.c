/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:00:30 by rmaxima           #+#    #+#             */
/*   Updated: 2020/03/09 20:29:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				in_button(int x, int y)
{
	if (y >= 0 && y < B_H)
		if (x >= WIDTH - 200 && x < WIDTH)
			return (1);
	return (0);
}

static void		string_help(t_fractol *fractol)
{
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 50, 0x0f4c81, "Change color: ");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 50, GREEN, "              0-9");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 80, 0x0f4c81, "Zoom: ");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 80, GREEN, "      left button/");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 100, GREEN, "right button, mouse");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 130, 0x0f4c81, "Position: ");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 130, GREEN, "          arrows");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 160, 0x0f4c81, "Iterations: ");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 160, GREEN, "            < >");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 190, 0x0f4c81, "Colors: ");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 190, GREEN, "            P");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 220, 0x0f4c81, "Exit: ");
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 200, 220, GREEN, "            ESC");
}

void			draw_help(t_fractol *fractol)
{
	int x;
	int y;

	y = B_H + 1;
	while (y < 250)
	{
		x = WIDTH - 200;
		while (x < WIDTH)
		{
			mlx_pixel_put(fractol->mlx, fractol->win, x, y, 0x8c0000ff);
			x++;
		}
		y++;
	}
	string_help(fractol);
}

void			draw_button(t_fractol *fractol)
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
			mlx_pixel_put(fractol->mlx, fractol->win, x, y, 0x8c0000ff);
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
	mlx_string_put(fractol->mlx, fractol->win, WIDTH - 110, 5, 0x000000, "MENU");
}
