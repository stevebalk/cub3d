/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculate_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:06:21 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 21:01:04 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_step_size(t_ray *ray)
{
	ray->step.x = 0;
	ray->step.y = 0;
	ray->map_check.x = (int)floor(ray->pos.x);
	ray->map_check.y = (int)floor(ray->pos.y);
	if (ray->dir.x == 0)
		ray->step_size.x = 1e30;
	else
		ray->step_size.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->step_size.y = 1e30;
	else
		ray->step_size.y = fabs(1 / ray->dir.y);
}

void	calculate_ray_length(t_ray *ray)
{
	if (ray->dir.x < 0.0)
	{
		ray->step.x = -1;
		ray->length.x = (ray->pos.x - ray->map_check.x) * ray->step_size.x;
	}
	else
	{
		ray->step.x = 1;
		ray->length.x = (ray->map_check.x + 1.0f
				- ray->pos.x) * ray->step_size.x;
	}
	if (ray->dir.y < 0.0)
	{
		ray->step.y = -1;
		ray->length.y = (ray->pos.y - ray->map_check.y) * ray->step_size.y;
	}
	else
	{
		ray->step.y = 1;
		ray->length.y = (ray->map_check.y + 1.0f
				- ray->pos.y) * ray->step_size.y;
	}
}

void	calculate_ray_dir(t_ray *ray, t_cub *cub, int i)
{
	double	camera_x;

	camera_x = 2 * i / (double)cub->win_size.x - 1;
	ray->dir.x = cub->player.dir.x + cub->player.plane.x * camera_x;
	ray->dir.y = cub->player.dir.y + cub->player.plane.y * camera_x;
}
