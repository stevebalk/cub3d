/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:55:24 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:33:59 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	size_t	total_size;
	size_t	i;

	total_size = WIN_WIDTH * WIN_HEIGHT / 2;
	i = 0;
	while (i < total_size)
	{
		*((int *)cub->img->addr + i) = cub->ceilling_color;
		i ++;
	}
}

void	draw_floor(t_cub *cub)
{
	size_t	total_size;
	size_t	i;

	total_size = WIN_WIDTH * WIN_HEIGHT;
	i = WIN_WIDTH * WIN_HEIGHT / 2;
	while (i < total_size)
	{
		*((int *)cub->img->addr + i) = cub->floor_color;
		i ++;
	}
}
