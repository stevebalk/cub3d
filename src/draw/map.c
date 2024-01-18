/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 12:14:44 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_cub *cub)
{
	t_vec2i	i;
	t_vec2i	j;
	t_vec2i	pos;
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
			pos.x = i.x * 10;
			pos.y = i.y * 10;
			color = cub->map[i.x][i.y] == 1 ? 0x00FFFFFF : 0x00000000;
			draw_square(cub->img, pos, 10, color);
			i.y++;
		}
		i.x++;
	}
}
