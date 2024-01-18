/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:18:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 17:22:27 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub *cub)
{
	cub->player.pos = add_vec2(cub->player.pos, scale_vec2(cub->player.dir, MOVE_SPEED));
}

void	move_backward(t_cub *cub)
{
	cub->player.pos = sub_vec2(cub->player.pos, scale_vec2(cub->player.dir, MOVE_SPEED));
}

void	move_left(t_cub *cub)
{
	t_vec2	new_dir;

	new_dir.x = cub->player.dir.y;
	new_dir.y = -cub->player.dir.x;
	cub->player.pos = add_vec2(cub->player.pos, scale_vec2(new_dir, MOVE_SPEED));
}

void	move_right(t_cub *cub)
{
	t_vec2	new_dir;

	new_dir.x = -cub->player.dir.y;
	new_dir.y = cub->player.dir.x;
	cub->player.pos = add_vec2(cub->player.pos, scale_vec2(new_dir, MOVE_SPEED));
}
