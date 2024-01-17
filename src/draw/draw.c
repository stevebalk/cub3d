/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:55:24 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/17 16:08:01 by sbalk            ###   ########.fr       */
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

/* Sets next point, returns 1 if successful, 0 if not*/ //DEBUG
static int	get_next_point(t_line *line, t_vec2i *start, t_vec2i end)
{
	if (start->x == end.x && start->y == end.y)
		return (0);
	line->err2 = 2 * line->err;
	if (line->err2 >= line->dy)
	{
		line->err += line->dy;
		start->x += line->sx;
	}
	if (line->err2 <= line->dx)
	{
		line->err += line->dx;
		start->y += line->sy;
	}
	return (1);
}

/* Bresenham's algorithm */ //DEBUG
void	draw_line(t_data *img, t_vec2i start, t_vec2i end, int color)
{
	t_line	line;

	line.dx = abs(end.x - start.x);
	line.sx = ft_sign(start.x - end.x) * -1;
	line.dy = -abs(end.y - start.y);
	line.sy = ft_sign(start.y - end.y) * -1;
	line.err = line.dx + line.dy;
	put_pixel(img, start, color);
	while (get_next_point(&line, &start, end))
		put_pixel(img, start, color);
}
