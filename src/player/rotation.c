/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:57:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:31:51 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub *cub, double angle)
{
	t_vec2	new_dir;
	t_vec2	new_plane;

	if (angle == 0)
		return ;
	new_dir.x = cub->player.dir.x * cos(angle) - cub->player.dir.y * sin(angle);
	new_dir.y = cub->player.dir.x * sin(angle) + cub->player.dir.y * cos(angle);
	new_plane.x = cub->player.plane.x * cos(angle)
		- cub->player.plane.y * sin(angle);
	new_plane.y = cub->player.plane.x * sin(angle)
		+ cub->player.plane.y * cos(angle);
	cub->player.dir = new_dir;
	cub->player.plane = new_plane;
}
