/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:55:24 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/19 23:19:10 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_data *img, t_vec2i pos, int color)
{
	char	*dst;

	if (pos.x < 0 || pos.y < 0 || pos.x >= img->win_size.x
		|| pos.y >= img->win_size.y)
		return ;
	dst = img->addr + (pos.y * img->line_length + pos.x
			* (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_data *img, t_vec2i size, int color)
{
	t_vec2i	start;

	start.x = 0;
	start.y = 0;
	draw_rectangle(img, start, size, color);
}

void	draw_ceilling(t_cub *cub)
{
	t_vec2i	start;
	t_vec2i	size;

	start.x = 0;
	start.y = 0;
	size.x = cub->img->win_size.x;
	size.y = cub->img->win_size.y / 2;
	draw_rectangle(cub->img, start, size, cub->ceilling_color);
}

void	draw_floor(t_cub *cub)
{
	t_vec2i	start;
	t_vec2i	size;

	start.x = 0;
	start.y = cub->img->win_size.y / 2;
	size.x = cub->img->win_size.x;
	size.y = cub->img->win_size.y / 2;
	draw_rectangle(cub->img, start, size, cub->floor_color);
}
