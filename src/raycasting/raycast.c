/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:47:58 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 13:09:13 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	cub->ray.pos.x = cub->player.pos.x;
	cub->ray.pos.y = cub->player.pos.y;
	while (i < cub->win_size.x)
	{
		calculate_ray_dir(&cub->ray, cub, i);
		calculate_step_size(&cub->ray);
		calculate_ray_length(&cub->ray);
		if (is_ray_hitting(cub, &cub->ray))
		{
			cub->ray.hit_direction = get_compass_hit_direction(&cub->ray);
			calculate_perpendicular_wall_dist(&cub->ray);
			calculate_line_height(&cub->ray, cub);
			calculate_wall_x(&cub->ray);
			calculate_texture_x(&cub->ray, cub);
			draw_line_from_texture(&cub->ray, cub, i);
		}
		i++;
	}
}
