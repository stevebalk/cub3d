/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:47:58 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/19 16:33:24 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_cub *cub, t_vec2 start_pos, t_vec2 dir)
{
	(void)dir;
	t_vec2	step_size;
	t_vec2i	step;
	t_vec2i	map_check;
	t_vec2	ray_length;
	double	perp_wall_dist;
	int i;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	
	i = 0;
	while (i < cub->win_size.x)
	{
		camera_x = 2 * i / (double)cub->win_size.x - 1;
		ray_dir_x = cub->player.dir.x + cub->player.plane.x * camera_x;
		ray_dir_y = cub->player.dir.y + cub->player.plane.y * camera_x;

		int		side;

		step.x = 0;
		step.y = 0;
		map_check.x = (int)start_pos.x;
		map_check.y = (int)start_pos.y;
		// step_size.x = sqrt(1 + (dir.y / dir.x) * (dir.y / dir.x));
		// step_size.y = sqrt(1 + (dir.x / dir.y) * (dir.x / dir.y));
		// step_size.x = fabs(1 / dir.x);
		// step_size.y = fabs(1 / dir.y);

		if (ray_dir_x == 0)
			step_size.x = 1e30;
		else
			step_size.x = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			step_size.y = 1e30;
		else
			step_size.y = fabs(1 / ray_dir_y);
		if (ray_dir_x < 0)
		{
			step.x = -1;
			ray_length.x = (start_pos.x - map_check.x) * step_size.x;
		}
		else
		{
			step.x = 1;
			ray_length.x = (map_check.x + 1.0f - start_pos.x) * step_size.x;
		}
		if (ray_dir_y < 0)
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
				dist = ray_length.x;
				ray_length.x += step_size.x;
				side = 0;
			}
			else
			{
				map_check.y += step.y;
				dist = ray_length.y;
				ray_length.y += step_size.y;
				side = 1;
			}
			if ( map_check.x >= 0 && map_check.x < cub->map_size.x && map_check.y >= 0 && map_check.y < cub->map_size.y)
			{
				if (cub->map[map_check.y][map_check.x] >= 1)
				{
					t_vec2i	coord;
					int		color;

					if (side == 0)
						color = 0x000000FF;
					else
						color = 0x0000FF00;
					coord = scale_vec2i(map_check, TILE_SIZE / 2);
					coord.x += 400;
					draw_square(cub->img, coord, TILE_SIZE / 2, color);
					hit = 1;
				}
			}
		}

		if (hit)
		{
			// t_vec2	intersection;

			// intersection.x = start_pos.x + dir.x * dist;
			// intersection.y = start_pos.y + dir.y * dist;
			// draw_circle(cub->img, v2_to_v2i(scale_vec2(intersection, TILE_SIZE)), TILE_SIZE / 4, 0x00FFFF00);

			if (side == 0)
				perp_wall_dist = (ray_length.x - step_size.x);
			else
				perp_wall_dist = (ray_length.y - step_size.y);
			int line_height = (int)(cub->win_size.y / perp_wall_dist);

			int draw_start = -line_height / 2 + cub->win_size.y / 2;
			if(draw_start < 0)
				draw_start = 0;
			int draw_end = line_height / 2 + cub->win_size.y / 2;
			if(draw_end >= cub->win_size.y)
				draw_end = cub->win_size.y - 1;
			draw_line(cub->img, (t_vec2i){cub->win_size.x - i, draw_start}, (t_vec2i){cub->win_size.x - i, draw_end}, 0x00FFFF00);
		}
		i++;
	}
}
