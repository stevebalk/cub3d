/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:20:29 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:29:52 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vec2	get_player_pos(t_player *player)
{
	return (player->pos);
}

t_vec2	get_player_dir(t_player *player)
{
	return (player->dir);
}

t_vec2	get_player_plane(t_player *player)
{
	return (player->plane);
}

double	get_player_time(t_player *player)
{
	return (player->time);
}

double	get_player_old_time(t_player *player)
{
	return (player->old_time);
}
