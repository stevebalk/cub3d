/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:01:27 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:03:34 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Returns the side of the wall that was hit
int	get_compass_hit_direction(t_ray *ray)
{
	if (ray->was_hit_vertical && ray->pos.y > ray->map_check.y)
		return (SOUTH);
	else if (ray->was_hit_vertical && ray->pos.y < ray->map_check.y)
		return (NORTH);
	else if (!ray->was_hit_vertical && ray->pos.x > ray->map_check.x)
		return (EAST);
	else if (!ray->was_hit_vertical && ray->pos.x < ray->map_check.x)
		return (WEST);
	return (-1);
}

static void	horizontal_step(t_ray *ray, double *dist)
{
	ray->map_check.x += ray->step.x;
	*dist = ray->length.x;
	ray->length.x += ray->step_size.x;
	ray->was_hit_vertical = 0;
}

static void	vertical_step(t_ray *ray, double *dist)
{
	ray->map_check.y += ray->step.y;
	*dist = ray->length.y;
	ray->length.y += ray->step_size.y;
	ray->was_hit_vertical = 1;
}

int	is_ray_hitting(t_cub *cub, t_ray *ray)
{
	int		hit;
	double	dist;

	hit = 0;
	dist = 0;
	while (!hit && dist < MAX_RAY_LENGTH)
	{
		if (ray->length.x < ray->length.y)
			horizontal_step(ray, &dist);
		else
			vertical_step(ray, &dist);
		if (is_inside_map(cub, ray->map_check))
		{
			if (is_cell_occopied(cub, 
					(t_vec2i){ray->map_check.y, ray->map_check.x}))
				return (1);
		}
	}
	return (0);
}
