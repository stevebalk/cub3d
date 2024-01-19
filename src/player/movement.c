/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:18:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/20 00:05:18 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	can_move(t_cub *cub, t_vec2 dir)
// {
// 	t_vec2i	new_pos;

// 	new_pos.x = round(cub->player.pos.x + dir.x * MOVE_SPEED);
// 	new_pos.y = round(cub->player.pos.y + dir.y * MOVE_SPEED);
// 	printf("New pos: %d, %d\n", new_pos.x, new_pos.y);
// 	if (cub->map[new_pos.y][new_pos.x] >= 1)
// 		return (0);n_move(t_cub *cub, t_vec2 dir)
// {
// 	t_vec2i	new_pos;

// 	new_pos.x = round(cub->player.pos.x + dir.x * MOVE_SPEED);
// 	new_pos.y = round(cub->player.pos.y + dir.y * MOVE_SPEED);
// 	printf("New pos: %d, %d\n", new_pos.x, new_pos.y);
// 	if (cub->map[new_pos.y][new_pos.x] >= 1)
// 		return (0);
// 	return (1);
// }
// 	return (1);
// }

void	move(t_cub *cub)
{
	t_vec2	new_pos;

	new_pos.x = cub->player.pos.x + cub->player.velocity.x;
	new_pos.y = cub->player.pos.y + cub->player.velocity.y;
	cub->player.pos.x = new_pos.x;
	cub->player.pos.y = new_pos.y;
	// if (cub->map[(int)round(new_pos.y)][(int)round(cub->player.pos.x)] == 0)
	// 	cub->player.pos.x = new_pos.x;
	// if (cub->map[(int)round(cub->player.pos.y)][(int)round(new_pos.x)] == 0)
	// 	cub->player.pos.y = new_pos.y;
	cub->player.velocity.x = 0;
	cub->player.velocity.y = 0;
}

void	move_forward(t_cub *cub)
{
	cub->player.velocity.x += cub->player.dir.x * MOVE_SPEED;
	cub->player.velocity.y += cub->player.dir.y * MOVE_SPEED;
}

void	move_backward(t_cub *cub)
{
	cub->player.velocity.x -= cub->player.dir.x * MOVE_SPEED;
	cub->player.velocity.y -= cub->player.dir.y * MOVE_SPEED;
}

void	move_left(t_cub *cub)
{
	t_vec2	new_dir;

	new_dir.x = cub->player.dir.y;
	new_dir.y = -cub->player.dir.x;
	cub->player.velocity.x += new_dir.x * MOVE_SPEED;
	cub->player.velocity.y += new_dir.y * MOVE_SPEED;
}

void	move_right(t_cub *cub)
{
	t_vec2	new_dir;

	new_dir.x = -cub->player.dir.y;
	new_dir.y = cub->player.dir.x;
	cub->player.velocity.x += new_dir.x * MOVE_SPEED;
	cub->player.velocity.y += new_dir.y * MOVE_SPEED;
}
