/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:48:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/05 16:25:26 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	sprite_rendering(t_cub *cub, int i)
{
	t_sprite_calc	*sc;
	int				y;
	int				color;

	sc = &cub->sc;
	sc->stripe = cub->sc.draw_start.x;
	while (sc->stripe < cub->sc.draw_end.x)
	{
		sprite_calc_tex_x(cub, sc, i);
		if (is_sprite_visible(cub, sc))
		{
			y = cub->sc.draw_start.y;
			while (y < cub->sc.draw_end.y)
			{
				sprite_calc_tex_y(cub, i, y);
				color = get_pixel_color_int(
						&cub->sprite_textures[cub->sprites[i].id], cub->sc.tex.x
						+ cub->sprites[i].frame_offset_x, cub->sc.tex.y);
				if (color != SPRITE_TRANSPARENCY)
					put_pixel(cub->img, (t_vec2i){sc->stripe, y}, color);
				y++;
			}
		}
		sc->stripe++;
	}
}

void	set_sprite_frame(t_cub *cub, int i)
{
	if (cub->sprites[i].animatable == 0)
		return ;
	cub->sprites[i].frame_time += cub->delta_time;
	if (cub->sprites[i].frame_time > cub->sprites[i].frame_duration)
	{
		cub->sprites[i].frame_time = 0.0;
		cub->sprites[i].frame_index++;
		if (cub->sprites[i].frame_index >= cub->sprites[i].frame_count)
			cub->sprites[i].frame_index = 0;
		cub->sprites[i].frame_offset_x = cub->sprites[i].frame_index
			* cub->sprites[i].frame_width;
	}
}

void	draw_sprites(t_cub *cub)
{
	int				i;

	calculate_sprite_distances(cub);
	sort_sprites(cub);
	i = 0;
	while (i < cub->sprite_count)
	{
		set_sprite_frame(cub, i);
		sprite_projection(cub, i);
		sprite_clip_height_calc(cub);
		sprite_clip_width_calc(cub);
		sprite_rendering(cub, i);
		i++;
	}
}
