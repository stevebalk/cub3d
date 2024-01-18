/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 12:28:31 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_map(t_cub *cub, t_vec2i pos)
{
	t_vec2i	i;
	t_vec2i	j;
	t_vec2i	local_pos;
	int		color;

	i.x = 0;
	i.y = 0;
	j.x = cub->map_size.x;
	j.y = cub->map_size.y;
	while (i.x < j.x)
	{
		i.y = 0;
		while (i.y < j.y)
		{
			local_pos.x = i.x * TILE_SIZE_HALF;
			local_pos.y = i.y * TILE_SIZE_HALF;
			if (cub->map[i.x][i.y] == 1)
				color = 0x00FFFFFF;
			else if (cub->map[i.x][i.y] >= 2)
				color = 0x00FF0000;
			else
				color = 0x00000000;
			draw_square(cub->img, local_pos + pos, TILE_SIZE_HALF, color);
			i.y++;
		}
		i.x++;
	}
}
