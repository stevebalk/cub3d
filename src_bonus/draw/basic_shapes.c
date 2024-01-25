/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:04:48 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:34:46 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_square(t_data *img, t_vec2i pos, int size, int color)
{
	t_vec2i	i;
	t_vec2i	j;

	i.x = pos.x;
	i.y = pos.y;
	j.x = pos.x + size;
	j.y = pos.y + size;
	while (i.x < j.x)
	{
		i.y = pos.y;
		while (i.y < j.y)
		{
			put_pixel(img, i, color);
			i.y++;
		}
		i.x++;
	}
}

void	draw_rectangle(t_data *img, t_vec2i pos, t_vec2i size, int color)
{
	t_vec2i	i;
	t_vec2i	j;

	i.x = pos.x;
	i.y = pos.y;
	j.x = pos.x + size.x;
	j.y = pos.y + size.y;
	while (i.x < j.x)
	{
		i.y = pos.y;
		while (i.y < j.y)
		{
			put_pixel(img, i, color);
			i.y++;
		}
		i.x++;
	}
}

void	draw_circle(t_data *img, t_vec2i pos, int radius, int color)
{
	t_vec2i	i;
	t_vec2i	j;

	i.x = pos.x - radius;
	i.y = pos.y - radius;
	j.x = pos.x + radius;
	j.y = pos.y + radius;
	while (i.x < j.x)
	{
		i.y = pos.y - radius;
		while (i.y < j.y)
		{
			if (pow(i.x - pos.x, 2) + pow(i.y - pos.y, 2) <= pow(radius, 2))
				put_pixel(img, i, color);
			i.y++;
		}
		i.x++;
	}
}

void	draw_triangle(t_data *img, t_vec2i pos, int size, int color)
{
	t_vec2i	i;
	t_vec2i	j;

	i.x = pos.x;
	i.y = pos.y;
	j.x = pos.x + size;
	j.y = pos.y + size;
	while (i.x < j.x)
	{
		i.y = pos.y;
		while (i.y < j.y)
		{
			if (i.y - pos.y <= i.x - pos.x)
				put_pixel(img, i, color);
			i.y++;
		}
		i.x++;
	}
}
