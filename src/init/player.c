/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:55:38 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/19 23:51:03 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->pos.x = 22;
	player->pos.y = 12;
	player->velocity.x = 0;
	player->velocity.y = 0;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = (double)FOV / 100;
	player->time = 0;
	player->old_time = 0;
}
