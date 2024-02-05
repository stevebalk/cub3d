/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:56:44 by jonas             #+#    #+#             */
/*   Updated: 2024/02/03 16:09:06 by jonas            ###   ########.fr       */
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

void	ini_map(t_map *s_map)
{
	int	i;

	i = 0;
	s_map->textures = (char **)malloc(sizeof(char *) * 5);
	while (i < 5)
	{
		s_map->textures[i] = NULL;
		i++;
	}
	s_map->map = NULL;
}
