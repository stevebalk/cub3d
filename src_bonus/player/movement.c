/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:18:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 20:42:57 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Function to normalize a vector
void	normalize_vector(t_vec2 *vec)
{
	float	magnitude;

	magnitude = sqrt(vec->x * vec->x + vec->y * vec->y);
	if (magnitude != 0)
	{
		vec->x /= magnitude;
		vec->y /= magnitude;
	}
}

// Function to slide the player along the wall
void	slide_player(t_cub *cub, t_vec2 total_movement)
{
	t_vec2	slide_x;
	t_vec2	slide_y;

	slide_x = (t_vec2){total_movement.x * MOVE_SPEED, 0};
	slide_y = (t_vec2){0, total_movement.y * MOVE_SPEED};
	if (is_inside_map(cub, v2_to_v2i(add_vec2(cub->player.pos, slide_x)))
		&& !is_colliding(cub, add_vec2(cub->player.pos, slide_x)))
	{
		cub->player.pos.x += slide_x.x;
		cub->player.pos.y += slide_x.y;
		return ;
	}
	if (is_inside_map(cub, v2_to_v2i(add_vec2(cub->player.pos, slide_y)))
		&& !is_colliding(cub, add_vec2(cub->player.pos, slide_y)))
	{
		cub->player.pos.x += slide_y.x;
		cub->player.pos.y += slide_y.y;
		return ;
	}
}

t_vec2	calculate_movement_dir(t_cub *cub)
{
	t_vec2	movement_dir;

	movement_dir.x = cub->player.dir.x * cub->player.move_dir.y
		- cub->player.dir.y * cub->player.move_dir.x;
	movement_dir.y = cub->player.dir.y * cub->player.move_dir.y
		+ cub->player.dir.x * cub->player.move_dir.x;
	normalize_vector(&movement_dir);
	return (movement_dir);
}

void	move(t_cub *cub)
{
	t_vec2	movement_dir;
	t_vec2	new_pos;

	if (cub->player.move_dir.x == 0 && cub->player.move_dir.y == 0)
		return ;
	movement_dir = calculate_movement_dir(cub);
	new_pos.x = cub->player.pos.x + movement_dir.x * MOVE_SPEED;
	new_pos.y = cub->player.pos.y + movement_dir.y * MOVE_SPEED;
	if (is_inside_map(cub, v2_to_v2i(new_pos)) && !is_colliding(cub, new_pos))
	{
		cub->player.pos.x = new_pos.x;
		cub->player.pos.y = new_pos.y;
	}
	else
		slide_player(cub, movement_dir);
	cub->player.move_dir.x = 0;
	cub->player.move_dir.y = 0;
}
