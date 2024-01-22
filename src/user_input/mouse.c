/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:37 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/22 19:15:21 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_press(int button, int x, int y, t_cub *cub)
{
	(void)cub;
	printf("button: %d\n", button);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	return (0);
}

int	mouse_release(int button, int x, int y, t_cub *cub)
{
	(void)cub;
	printf("button: %d\n", button);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	return (0);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	t_vec2i	rel_pos;

	rel_pos.x = x - cub->win_center.x;
	rel_pos.y = y - cub->win_center.y;

	if (rel_pos.x != 0 || rel_pos.y != 0)
	{
		if (rel_pos.x != 0)
			rotate_player(cub, rel_pos.x * ROT_SPEED * MOUSE_SENSITIVITY);
		mlx_mouse_move(cub->mlx, cub->win, cub->win_center.x, cub->win_center.y);
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
