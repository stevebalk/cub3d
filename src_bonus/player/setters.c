/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:20:27 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:30:32 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_player_pos(t_player *player, t_vec2 pos)
{
	player->pos = pos;
}

void	set_player_dir(t_player *player, t_vec2 dir)
{
	player->dir = dir;
}

void	set_player_plane(t_player *player, t_vec2 plane)
{
	player->plane = plane;
}

void	set_player_time(t_player *player, double time)
{
	player->time = time;
}

// void	set_player_old_time(t_player *player, double old_time)
// {
// 	player->old_time = old_time;
// }

// void	set_player(t_player *player, t_vec2 pos, t_vec2 dir, t_vec2 plane)
// {
// 	set_player_pos(player, pos);
// 	set_player_dir(player, dir);
// 	set_player_plane(player, plane);
// }

// void	set_player_time_old_time(t_player *player, double time, double old_time)
// {
// 	set_player_time(player, time);
// 	set_player_old_time(player, old_time);
// }
