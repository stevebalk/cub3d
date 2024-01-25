/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:00:06 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 23:48:41 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_pixel_from_texture(t_ray *ray, int i, int j)
{
	int			color;
	t_texture	*texture;

	texture = &(ray->textures[ray->hit_direction]);
	color = get_pixel_color_int(texture, ray->tex.x, ray->tex.y);
	put_pixel(ray->img, (t_vec2i){i, j}, color);
}

void	draw_line_from_texture(t_ray *ray, int i)
{
	double	step_tex;
	double	tex_pos;
	int		tex_height;
	int		j;

	j = ray->draw_start;
	tex_height = ray->textures[ray->hit_direction].height;
	step_tex = 1.0 * tex_height / ray->line_height;
	tex_pos = (ray->draw_start - ray->win_size->y / 2 + ray->line_height / 2)
		* step_tex;
	while (j < ray->draw_end)
	{
		ray->tex.y = (int)tex_pos & (tex_height - 1);
		tex_pos += step_tex;
		draw_pixel_from_texture(ray, i, j);
		j++;
	}
}
