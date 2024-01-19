/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:47:58 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/19 13:06:48 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_cub *cub, t_vec2 start_pos, t_vec2 dir)
{
	t_vec2	step_size;
	t_vec2i	step;
	t_vec2i	map_check;
	t_vec2	ray_length;

	step.x = 0;
	step.y = 0;
	map_check.x = start_pos.x;
	map_check.y = start_pos.y;
	step_size.x = sqrt(1 + (dir.y / dir.x) * (dir.y / dir.x));
	step_size.y = sqrt(1 + (dir.x / dir.y) * (dir.x / dir.y));
	if (dir.x < 0)
	{
		step.x = -1;
		ray_length.x = (start_pos.x - map_check.x) * step_size.x;
	}
	else
	{
		step.x = 1;
		ray_length.x = (map_check.x + 1.0f - start_pos.x) * step_size.x;
	}
	if (dir.y < 0)
	{
		step.y = -1;
		ray_length.y = (start_pos.y - map_check.y) * step_size.y;
	}
	else
	{
		step.y = 1;
		ray_length.y = (map_check.y + 1.0f - start_pos.y) * step_size.y;
	}

	int		hit;
	double	max_dist;
	double	dist;

	hit = 0;
	max_dist = 100.0f;
	dist = 0;
	while (!hit && dist < max_dist)
	{
		if (ray_length.x < ray_length.y)
		{
			map_check.x += step.x;
			dist += ray_length.x;
			ray_length.x += step_size.x;
		}
		else
		{
			map_check.y += step.y;
			dist += ray_length.y;
			ray_length.y += step_size.y;
		}
		if ( map_check.x >= 0 && map_check.x < cub->map_size.x && map_check.y >= 0 && map_check.y < cub->map_size.y)
		{
			if (cub->map[map_check.y][map_check.x] >= 1)
			{
				t_vec2i	coord;
				coord.x = map_check.x * TILE_SIZE;
				coord.y = map_check.y * TILE_SIZE;
				printf("map_check.x: %d map_chech.y: %d\n", map_check.x, map_check.y);
				draw_square(cub->img, coord, TILE_SIZE, 0x00FF00FF);
				hit = 1;
			}
		}
	}

}
