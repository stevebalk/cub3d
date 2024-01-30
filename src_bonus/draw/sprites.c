/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:48:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 13:53:39 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_sprite_distances(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->sprite_count)
	{
		cub->sprites[i].distance = ((cub->player.pos.x - cub->sprites[i].pos.x)
				* (cub->player.pos.x - cub->sprites[i].pos.x)
				+ (cub->player.pos.y - cub->sprites[i].pos.y)
				* (cub->player.pos.y - cub->sprites[i].pos.y));
		i++;
	}
}

// Sort sprites from farthest to closest
void	sort_sprites(t_cub *cub)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < cub->sprite_count)
	{
		j = 0;
		while (j < cub->sprite_count - 1)
		{
			if (cub->sprites[j].distance < cub->sprites[j + 1].distance)
			{
				tmp = cub->sprites[j];
				cub->sprites[j] = cub->sprites[j + 1];
				cub->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

// Calculate the relative position of the sprite to the camera plane
void	sprite_projection(t_cub *cub, int i)
{
	double	inv_det;

	cub->sc.dir = get_target_vec2(cub->player.pos, cub->sprites[i].pos);
	inv_det = 1.0 / (cub->player.plane.x * cub->player.dir.y
			- cub->player.dir.x * cub->player.plane.y);
	cub->sc.transform.x = inv_det * (cub->player.dir.y * cub->sc.dir.x
			- cub->player.dir.x * cub->sc.dir.y);
	cub->sc.transform.y = inv_det * (-cub->player.plane.y * cub->sc.dir.x
			+ cub->player.plane.x * cub->sc.dir.y);
	cub->sc.sprite_screen_x = (int)((cub->win_size.x / 2)
			* (1 + cub->sc.transform.x / cub->sc.transform.y));
}

// Calculate the height of the sprite on screen
void	sprite_clip_height_calc(t_cub *cub)
{
	cub->sc.size.y = abs((int)(cub->win_size.y / (cub->sc.transform.y)));
	cub->sc.draw_start.y = -cub->sc.size.y / 2 + cub->win_size.y / 2;
	if (cub->sc.draw_start.y < 0)
		cub->sc.draw_start.y = 0;
	cub->sc.draw_end.y = cub->sc.size.y / 2 + cub->win_size.y / 2;
	if (cub->sc.draw_end.y >= cub->win_size.y)
		cub->sc.draw_end.y = cub->win_size.y - 1;
}

// Calculate the width of the sprite on screen
void	sprite_clip_width_calc(t_cub *cub)
{
	cub->sc.size.x = abs((int)(cub->win_size.y / (cub->sc.transform.y)));
	cub->sc.draw_start.x = -cub->sc.size.x / 2 + cub->sc.sprite_screen_x;
	if (cub->sc.draw_start.x < 0)
		cub->sc.draw_start.x = 0;
	cub->sc.draw_end.x = cub->sc.size.x / 2 + cub->sc.sprite_screen_x;
	if (cub->sc.draw_end.x >= cub->win_size.x)
		cub->sc.draw_end.x = cub->win_size.x - 1;
}

// Calculate the texture x-coordinate for the sprite
void	sprite_calc_tex_x(t_cub *cub, t_sprite_calc *sc, int i)
{
	cub->sc.tex.x = (int)((sc->stripe
				- (-cub->sc.size.x / 2 + cub->sc.sprite_screen_x))
			* cub->sprites[i].frame_width / cub->sc.size.x);
}

// Calculate the texture y-coordinate for the sprite
void	sprite_calc_tex_y(t_cub *cub, int i, int y)
{
	int	d;

	d = y * 256 - cub->win_size.y * 128 + cub->sc.size.y * 128;
	cub->sc.tex.y = ((d * cub->sprite_textures[cub->sprites[i].id].height)
			/ cub->sc.size.y) / 256;
}

int	is_sprite_visible(t_cub *cub, t_sprite_calc *sc)
{
	if (cub->sc.transform.y > 0 && sc->stripe > 0
		&& sc->stripe < cub->win_size.x
		&& cub->sc.transform.y < cub->z_buffer[sc->stripe])
		return (1);
	return (0);
}

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
