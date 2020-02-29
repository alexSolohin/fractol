/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:52:59 by user              #+#    #+#             */
/*   Updated: 2020/02/29 21:07:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"
#include "mlx.h"
#include <stdlib.h>
#include <pthread.h>

int 

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}

t_color	get_color(int iteration, t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)iteration / fractol->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

static void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->size_line);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

void        draw_fractal_part(t_fractol *fractol)
{
    int     y;
    int     x;
    t_color color;

    y = fractol->start_line;
    while (y < fractol->finish_line)
    {
        fractol->c.im = fractol->max.im - y * fractol->factor.im;
        x = 0;
        while (x < WIDTH)
        {
            fractol->c.re = fractol->min.re + x * fractol->factor.re;
            color = get_color(fractol->formula(fractol), fractol);
            put_pixel(fractol, x, y, color);
            x++;
        }
        y++;
    }
}

void        draw_fractal(t_fractol *fractol)
{
    pthread_t threads[10];
    t_fractol fractols[10];
    
    fractol->factor = init_complex(
            (fractol->max.re - fractol->min.re) / (WIDTH - 1),
            (fractol->max.im - fractol->min.im) / (HEIGHT - 1));
    int i = 0;
    while (i < 10)
    {
        fractols[i] = *fractols;
        fractols[i].start_line = i * (HEIGHT / 10);
        fractols[i].finish_line = (i + 1) * (HEIGHT / 10);
        pthread_create(&threads[i], NULL, (void *(*)(void *))draw_fractal_part, (void *)&fractols[i]);
        i++;    
    }
    while (i-- > 0)
        pthread_join(threads[i], NULL);
    mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->win, 900, 965, GREEN,
		"H - Help");
}

double      interpolate(double start, double end, double interpolation)
{
    return (start + ((end -start) * interpolation));
}

int     zoom(int button, int x, int y, t_fractol * fractol)
{
    t_complex mouse;
    double      interpolation;
    double      zoom;

    if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
    {
        mouse = init_complex(
                (double)x / (WIDTH / (fractol->max.re - fractol->min.re)) + fractol->min.re,
                (double)y / (HEIGHT / (fractol->max.im - fractol->min.im)) + -1 + fractol->max.im);
        if (button == MOUSE_SCROLL_UP)
            zoom = 0.80;
        else
            zoom = 1.20;
        interpolation = 1.0 / zoom;
        fractol->min.re = interpolate(mouse.re, fractol->min.re, interpolation);
        fractol->min.im = interpolate(mouse.im, fractol->min.im, interpolation);
        fractol->max.re = interpolate(mouse.re, fractol->max.re, interpolation);
        fractol->max.im = interpolate(mouse.im, fractol->max.im, interpolation);
        draw_fractal(fractol);
    }
    return (0);
}



int		close(void *param)
{
	(void)param;
	exit(0);
}

int     key_press(int key, t_fractol *fractol)
{
    fractol = 0;
    if (key == MAIN_PAD_ESC)
        exit(0);
    return (0);
}

t_complex   init_complex(double re, double im)
{
    t_complex complex;

    complex.re = re;
    complex.im = im;
    return (complex);
}

void    set_default(t_fractol *fractol)
{
    fractol->max_iteration = 50;
    fractol->min = init_complex(-2.0, -2.0);
    fractol->max.re = 2.0;
    fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
    fractol->k = init_complex(-0.4, 0.6);
    fractol->color_shift = 0;
}

t_image     *init_image(void *mlx)
{
    t_image  *image;

    image = (t_image *)malloc(sizeof(t_image));
    image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
    image->data_addr = mlx_get_data_addr(image->image, 
                                        &(image->bits_per_pixel),
                                        &(image->size_line), 
                                        &(image->endian));
    return (image);
}

t_fractol      *init_fractol(t_fractol *fractol, void *mlx)
{
    
    fractol->mlx = mlx;
    fractol->win = mlx_new_window(mlx, WIDTH, HEIGHT, "fractol");
    fractol->img = init_image(mlx);
    set_default(fractol);
    mlx_hook(fractol->win, 2, 0, key_press, fractol);
    mlx_hook(fractol->win, 17, 0, close, fractol);
    mlx_hook(fractol->win, 4, 0, zoom, fractol);
    return (fractol);
}

int     main()
{
    t_fractol *fractol;
    void        *mlx;

    fractol = (t_fractol*)malloc(sizeof(t_fractol));
    mlx = mlx_init();
    fractol = init_fractol(fractol, mlx);
    draw_fractal_part(fractol);
    mlx_loop(mlx);
}