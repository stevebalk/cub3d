/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:37 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 21:49:51 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_press(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_UP)
	{
		if (is_flag_set(cub->flags, FLAG_RESOLUTION_MODE)
			&& cub->resolution < 128)
			cub->resolution *= 2;
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		if (is_flag_set(cub->flags, FLAG_RESOLUTION_MODE)
			&& cub->resolution >= 2)
				cub->resolution /= 2;;
	}
	return (0);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	t_vec2i	rel_pos;

	if (is_flag_set(cub->flags, FLAG_MOUSE_CONTROL))
	{
		rel_pos.x = x - cub->win_center.x;
		rel_pos.y = y - cub->win_center.y;
		if (rel_pos.x != 0)
		{
			rotate_player(cub, rel_pos.x * ROT_SPEED * MOUSE_SENSITIVITY);
			mlx_mouse_move(cub->mlx, cub->win,
				cub->win_center.x, cub->win_center.y);
		}
	}
	return (0);
}

void	move_mouse_to_center(t_cub *cub)
{
	t_vec2i	pos;

	pos.x = cub->win_size.x / 2;
	pos.y = cub->win_size.y / 2;
	mlx_mouse_move(cub->mlx, cub->win, pos.x, pos.y);
}

void	init_mouse(t_cub *cub)
{
	mlx_mouse_hide(cub->mlx, cub->win);
	move_mouse_to_center(cub);
}

t_vec2i	get_relative_mouse_pos(t_cub *cub)
{
	t_vec2i	pos;

	pos.x = cub->mouse.x - cub->win_center.x;
	pos.y = cub->mouse.y - cub->win_center.y;
	return (pos);
}
