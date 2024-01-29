/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:48:44 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/29 13:19:12 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_sprite_distances(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->sprite_count)
	{
		cub->sprites[i].distance = ((cub->player.pos.x - cub->sprites[i].x)
				* (cub->player.pos.x - cub->sprites[i].x)
				+ (cub->player.pos.y - cub->sprites[i].y)
				* (cub->player.pos.y - cub->sprites[i].y));
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

	cub->sc.dir.x = cub->sprites[i].x - cub->player.pos.x;
	cub->sc.dir.y = cub->sprites[i].y - cub->player.pos.y;
	inv_det = 1.0 / (cub->player.plane.x * cub->player.dir.y
			- cub->player.dir.x * cub->player.plane.y);
	cub->sc.transform.x = inv_det * (cub->player.dir.y * cub->sc.dir.x
				- cub->player.dir.x * cub->sc.dir.y);
	cub->sc.transform.y = inv_det * (-cub->player.plane.y * cub->sc.dir.x
			+ cub->player.plane.x * cub->sc.dir.y);
	cub->sc.sprite_screen_x = (int)((cub->win_size.x / 2)
		* (1 + cub->sc.transform.x / cub->sc.transform.y));
}

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

void	sprite_rendering(t_cub *cub, int i)
{
	t_sprite_calc	*sc;
	int				y;
	int				d;
	int				color;

	sc = &cub->sc;
	sc->stripe = cub->sc.draw_start.x;
	while (sc->stripe < cub->sc.draw_end.x)
	{
		cub->sc.tex.x = (int)(256 * (sc->stripe - (-cub->sc.size.x / 2 + cub->sc.sprite_screen_x)) * cub->sprites[i].frame_width / cub->sc.size.x) / 256;
		if (cub->sc.transform.y > 0 && sc->stripe > 0 && sc->stripe < cub->win_size.x && cub->sc.transform.y < cub->z_buffer[sc->stripe])
		{
			y = cub->sc.draw_start.y;
			while (y < cub->sc.draw_end.y)
			{
				d = (y) * 256 - cub->win_size.y * 128 + cub->sc.size.y * 128;
				cub->sc.tex.y = ((d * cub->sprite_textures[cub->sprites[i].id].height) / cub->sc.size.y) / 256;
				color = get_pixel_color_int(&cub->sprite_textures[cub->sprites[i].id], cub->sc.tex.x + cub->sprites[i].frame_offset_x, cub->sc.tex.y);
				if (color != SPRITE_TRANSPARENCY)
					put_pixel(cub->img, (t_vec2i){sc->stripe, y}, color);
				y++;
			}
		}
		sc->stripe++;
	}
}

void	change_sprite_frame(t_cub *cub, int i)
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
		cub->sprites[i].frame_offset_x = cub->sprites[i].frame_index * cub->sprites[i].frame_width;
	}
}

void	calculate_sprites(t_cub *cub)
{
	int				i;

	calculate_sprite_distances(cub);
	sort_sprites(cub);
	i = 0;
	while (i < cub->sprite_count)
	{
		change_sprite_frame(cub, i);
		sprite_projection(cub, i);
		sprite_clip_height_calc(cub);
		sprite_clip_width_calc(cub);
		sprite_rendering(cub, i);
		i++;
	}
}

void	draw_sprites(t_cub *cub)
{
	calculate_sprites(cub);
}


// calculate_sprites(t_cub *cub)
// {
// 	int				i;

// 	calculate_sprite_distances(cub);
// 	sort_sprites(cub);
// 	i = 0;
// 	while (i < cub->sprite_count)
// 	{
// 		// double	sprite_x;
// 		// double	sprite_y;
// 		// double	inv_det;
// 		// double	transform_x;
// 		// double	transform_y;
// 		// int		sprite_screen_x;
// 		// int		sprite_height;
// 		// int		sprite_width;
// 		// t_vec2i	draw_start;
// 		// t_vec2i	draw_end;
// 		// t_vec2i	tex;
// 		// int		d;
// 		// int		color;
// 		// int		y;

// 		// // sprite_calc_dir(cub, i);
// 		// sprite_x = cub->sprites[i].x - cub->player.pos.x;
// 		// sprite_y = cub->sprites[i].y - cub->player.pos.y;

// 		// inv_det = 1.0 / (cub->player.plane.x * cub->player.dir.y
// 		// 		- cub->player.dir.x * cub->player.plane.y);

// 		// transform_x = inv_det * (cub->player.dir.y * sprite_x - cub->player.dir.x * sprite_y);
// 		// transform_y = inv_det * (-cub->player.plane.y * sprite_x + cub->player.plane.x * sprite_y);

// 		// sprite_screen_x = (int)((cub->win_size.x / 2) * (1 + transform_x / transform_y));

// 		// sprite_height = abs((int)(cub->win_size.y / (transform_y)));

// 		// draw_start.y = -sprite_height / 2 + cub->win_size.y / 2;
// 		// if (draw_start.y < 0)
// 		// 	draw_start.y = 0;
// 		// draw_end.y = sprite_height / 2 + cub->win_size.y / 2;
// 		// if (draw_end.y >= cub->win_size.y)
// 		// 	draw_end.y = cub->win_size.y - 1;

// 		// sprite_width = abs((int)(cub->win_size.y / (transform_y)));
// 		// draw_start.x = -sprite_width / 2 + sprite_screen_x;
// 		// if (draw_start.x < 0)
// 		// 	draw_start.x = 0;
// 		// draw_end.x = sprite_width / 2 + sprite_screen_x;
// 		// if (draw_end.x >= cub->win_size.x)
// 		// 	draw_end.x = cub->win_size.x - 1;
// 		// int stripe = draw_start.x;
// 		// while (stripe < draw_end.x)
// 		// {
// 		// 	tex.x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * cub->sprite_textures[0].width / sprite_width) / 256;
// 		// 	if (transform_y > 0 && stripe > 0 && stripe < cub->win_size.x && transform_y < cub->z_buffer[stripe])
// 		// 	{
// 		// 		y = draw_start.y;
// 		// 		while (y < draw_end.y)
// 		// 		{
// 		// 			d = (y) * 256 - cub->win_size.y * 128 + sprite_height * 128;
// 		// 			tex.y = ((d * cub->sprite_textures[cub->sprites[i].id].height) / sprite_height) / 256;
// 		// 			color = get_pixel_color_int(&cub->sprite_textures[cub->sprites[i].id], tex.x, tex.y);
// 		// 			if (color != SPRITE_TRANSPARENCY)
// 		// 				put_pixel(cub->img, (t_vec2i){stripe, y}, color);
// 		// 			y++;
// 		// 		}
// 		// 	}
// 		// 	stripe++;
// 		// }
// 		// i++;
// 	}
// }