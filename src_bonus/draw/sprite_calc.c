/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:22:52 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/05 16:24:22 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
