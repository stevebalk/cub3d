/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:57:42 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 11:10:09 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

