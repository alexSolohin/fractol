/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:45:33 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/26 15:52:12 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"
#include "mlx.h"

int     ft_init_hook(t_fractol *fractol)
{
    mlx_hook(fractol->win, KEY_BUTTON_PRESS, 0, ft_keyboard_hook, fractol);
    mlx_hook(fractol->win, ESC_BUTTON_PRESS, 0, ft_close, fractol);
    return (0);
}
