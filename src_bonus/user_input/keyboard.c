/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:59 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 21:07:31 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	toggle_mouse_input(t_cub *cub)
{
	toggle_flag(&cub->flags, FLAG_MOUSE_CONTROL);
	if (is_flag_set(cub->flags, FLAG_MOUSE_CONTROL))
	{
		mlx_mouse_hide(cub->mlx, cub->win);
		move_mouse_to_center(cub);
	}
	else
		mlx_mouse_show(cub->mlx, cub->win);
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_F3)
		toggle_flag(&cub->flags, FLAG_RESOLUTION_MODE);
	if (keycode == XK_F2)
		toggle_flag(&cub->flags, FLAG_DEBUG_OVERLAY);
	if (keycode == XK_F1)
		toggle_mouse_input(cub);
	if (keycode == XK_w)
		cub->key.w = 1;
	if (keycode == XK_s)
		cub->key.s = 1;
	if (keycode == XK_a)
		cub->key.a = 1;
	if (keycode == XK_d)
		cub->key.d = 1;
	if (keycode == XK_Right)
		cub->key.right = 1;
	if (keycode == XK_Left)
		cub->key.left = 1;
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
	if (keycode == XK_Right)
		cub->key.right = 0;
	if (keycode == XK_Left)
		cub->key.left = 0;
	return (0);
}
