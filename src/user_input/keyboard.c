/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:59 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 16:32:55 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		move_forward(cub);
	if (keycode == XK_s)
		move_backward(cub);
	if (keycode == XK_a)
		move_left(cub);
	if (keycode == XK_d)
		move_right(cub);
	printf("keycode: %d\n", keycode);
	if (keycode == XK_Escape)
		close_window(cub);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	(void)cub;
	printf("keycode: %d\n", keycode);
	return (0);
}
