/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:59 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/17 15:57:11 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
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
