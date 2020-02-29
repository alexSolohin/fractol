/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaxima <rmaxima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:18:12 by rmaxima           #+#    #+#             */
/*   Updated: 2020/02/26 17:22:42 by rmaxima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"
#include "mlx.h"

int     ft_keyboard_hook(int key, void *param)
{
    if (key == MAIN_PAD_ESC)
        ft_close(param);
    else
        return (0);
    ft_draw(param);
    return (0);
}