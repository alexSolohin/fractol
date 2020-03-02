/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:01:16 by user              #+#    #+#             */
/*   Updated: 2020/03/02 18:02:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_key.h"


int     key_press(int key, t_fractol *fractol)
{
    fractol = 0;
    if (key == MAIN_PAD_ESC)
        exit(0);
    return (0);
}