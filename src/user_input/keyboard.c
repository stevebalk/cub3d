/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:59 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 17:00:01 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->key.w = 1;
	if (keycode == XK_s)
		cub->key.s = 1;
	if (keycode == XK_a)
		cub->key.a = 1;
	if (keycode == XK_d)
		cub->key.d = 1;
	if (keycode == XK_Escape)
		close_window(cub);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->key.w = 0;
	if (keycode == XK_s)
		cub->key.s = 0;
	if (keycode == XK_a)
		cub->key.a = 0;
	if (keycode == XK_d)
		cub->key.d = 0;
	return (0);
}
