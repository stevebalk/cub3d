/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:55:38 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 20:37:49 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_player(t_cub *cub)
{
	cub->player.pos.x = 1;
	cub->player.pos.y = 1;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.plane.x = 0;
	cub->player.plane.y = (double)FOV / 100;
	cub->player.time = 0;
	cub->player.old_time = 0;
	rotate_player(cub, cub->player.start_direction * deg_to_rad(90));
}
