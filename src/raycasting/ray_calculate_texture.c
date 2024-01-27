/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculate_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:04:38 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:40:45 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_perpendicular_wall_dist(t_ray *ray)
{
	if (ray->was_hit_vertical == 0)
		ray->perp_wall_dist = (ray->length.x - ray->step_size.x);
	else
		ray->perp_wall_dist = (ray->length.y - ray->step_size.y);
}

void	calculate_line_height(t_ray *ray, t_cub *cub)
{
	ray->line_height = (int)(cub->win_size.y / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + cub->win_size.y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cub->win_size.y / 2;
	if (ray->draw_end >= cub->win_size.y)
		ray->draw_end = cub->win_size.y - 1;
}

// Calculate where the ray hit the wall
void	calculate_wall_x(t_ray *ray)
{
	double	wall_x;

	if (ray->was_hit_vertical == 0)
		wall_x = ray->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		wall_x = ray->pos.x + ray->perp_wall_dist * ray->dir.x;
	wall_x -= floor(wall_x);
	ray->wall_x = wall_x;
}

void	calculate_texture_x(t_ray *ray, t_cub *cub)
{
	int	tex_width;

	tex_width = cub->wall_textures[0].width;
	if (ray->was_hit_vertical == 0)
	{
		ray->tex.x = (int)(ray->wall_x * (double)(tex_width));
		if (ray->dir.x < 0)
			ray->tex.x = tex_width - ray->tex.x - 1;
	}
	else
	{
		ray->tex.x = (int)(ray->wall_x * (double)(tex_width));
		if (ray->dir.y > 0)
			ray->tex.x = tex_width - ray->tex.x - 1;
	}
}
