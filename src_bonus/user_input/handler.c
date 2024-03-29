/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:00:25 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/27 22:00:43 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	key_handler(t_cub *cub)
{
	if (cub->key.w)
		cub->player.move_dir.y = 1;
	if (cub->key.s)
		cub->player.move_dir.y = -1;
	if (cub->key.d)
		cub->player.move_dir.x = 1;
	if (cub->key.a)
		cub->player.move_dir.x = -1;
	if (cub->key.right)
		rotate_player(cub, ROT_SPEED * cub->delta_time);
	if (cub->key.left)
		rotate_player(cub, -ROT_SPEED * cub->delta_time);
}

void	input_handler(t_cub *cub)
{
	key_handler(cub);
}
