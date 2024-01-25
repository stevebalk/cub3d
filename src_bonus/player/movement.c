/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:18:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 13:13:41 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move(t_cub *cub)
{
	t_vec2	new_pos;

	new_pos.x = cub->player.pos.x + cub->player.velocity.x * MOVE_SPEED;
	new_pos.y = cub->player.pos.y + cub->player.velocity.y * MOVE_SPEED;
	// if (is_inside_map(cub, v2_to_v2i(new_pos)))
	// {
	// 	if (!is_colliding(cub, new_pos))
	// 	{
	// 		cub->player.pos.x = new_pos.x;
	// 		cub->player.pos.y = new_pos.y;
	// 	}
	// }
	cub->player.pos.x = new_pos.x;
	cub->player.pos.y = new_pos.y;
	cub->player.velocity.x = 0;
	cub->player.velocity.y = 0;
}

void	move_forward(t_cub *cub)
{
	cub->player.velocity.x += cub->player.dir.x;
	cub->player.velocity.y += cub->player.dir.y;
}

void	move_backward(t_cub *cub)
{
	cub->player.velocity.x -= cub->player.dir.x;
	cub->player.velocity.y -= cub->player.dir.y;
}

void	move_left(t_cub *cub)
{
	t_vec2	new_dir;

	new_dir.x = cub->player.dir.y;
	new_dir.y = -cub->player.dir.x;
	cub->player.velocity.x += new_dir.x;
	cub->player.velocity.y += new_dir.y;
}

void	move_right(t_cub *cub)
{
	t_vec2	new_dir;

	new_dir.x = -cub->player.dir.y;
	new_dir.y = cub->player.dir.x;
	cub->player.velocity.x += new_dir.x;
	cub->player.velocity.y += new_dir.y;
}
