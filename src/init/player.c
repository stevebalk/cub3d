/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:55:38 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/22 19:25:04 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cub *cub)
{
	cub->player.pos.x = 6.65;
	cub->player.pos.y = 2.15;
	cub->player.velocity.x = 0;
	cub->player.velocity.y = 0;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.plane.x = 0;
	cub->player.plane.y = (double)FOV / 100;
	cub->player.time = 0;
	cub->player.old_time = 0;
	rotate_player(cub, cub->player.start_direction * deg_to_rad(90));
}
