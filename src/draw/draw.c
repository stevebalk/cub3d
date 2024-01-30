/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:55:24 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 13:44:18 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color_int(t_texture *texture, int x, int y)
{
	int	color;
	int	offset;

	color = 0;
	offset = (y * texture->line_length) + (x * (texture->bpp / 8));
	if (x >= 0 && x < texture->width && y >= 0 && y < texture->height)
	{
		color |= ((unsigned char)texture->addr[offset + 2]) << 16;
		color |= ((unsigned char)texture->addr[offset + 1]) << 8;
		color |= ((unsigned char)texture->addr[offset]);
	}
	return (color);
}

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
