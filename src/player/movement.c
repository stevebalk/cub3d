/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:18:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 11:48:37 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	is_vec2_inside_map(t_cub *cub, t_vec2 position)
// {
// 	if (position.x >= 0 && position.x < cub->map_size.x &&
// 		position.y >= 0 && position.y < cub->map_size.y)
// 		return (1);
// 	return (0);
// }

// int	is_vec2i_inside_map(t_cub *cub, t_vec2i position)
// {
// 	if (position.x >= 0 && position.x < cub->map_size.x &&
// 		position.y >= 0 && position.y < cub->map_size.y)
// 		return (1);
// 	return (0);
// }

int	is_colliding(t_cub *cub, t_vec2 position)
{
	t_vec2i	map_pos;

	map_pos.x = (int)(position.x);
	map_pos.y = (int)(position.y);
	if (is_inside_map(cub, map_pos))
		if (cub->map[map_pos.y][map_pos.x] >= 1)
			return (1);
	return (0);
}

void	move(t_cub *cub)
{
	t_vec2	new_pos;

	new_pos.x = cub->player.pos.x + cub->player.velocity.x * MOVE_SPEED;
	new_pos.y = cub->player.pos.y + cub->player.velocity.y * MOVE_SPEED;
	// if (new_pos.x >= 0 && new_pos.x < cub->map_size.x &&
	// 	new_pos.y >= 0 && new_pos.y < cub->map_size.y)
	// {
	// 	if (!is_colliding(cub, new_pos))
	// 	{
	// 		cub->player.pos.x = new_pos.x;
	// 		cub->player.pos.y = new_pos.y;
	// 	}
	// }
	if (!is_colliding(cub, new_pos))
	{
		cub->player.pos.x = new_pos.x;
		cub->player.pos.y = new_pos.y;
	}
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
