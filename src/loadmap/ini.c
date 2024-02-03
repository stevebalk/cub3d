/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:56:44 by jonas             #+#    #+#             */
/*   Updated: 2024/02/03 15:56:56 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// set all vars to -1
void	ini_player_pos(t_map *s_map)
{
	s_map->player_start_pos.view = -1;
	s_map->player_start_pos.x = -1;
	s_map->player_start_pos.y = -1;
}
