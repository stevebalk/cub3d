/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:29:15 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 12:39:40 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vec2i	add_vec2i(t_vec2i a, t_vec2i b)
{
	t_vec2i	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_vec2i	sub_vec2i(t_vec2i a, t_vec2i b)
{
	t_vec2i	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return (c);
}

t_vec2i	scale_vec2i(t_vec2i a, int scale)
{
	t_vec2i	c;

	c.x = a.x * scale;
	c.y = a.y * scale;
	return (c);
}

t_vec2i	get_target_vec2i(t_vec2i from, t_vec2i to)
{
	t_vec2i	dir;

	dir.x = to.x - from.x;
	dir.y = to.y - from.y;
	return (dir);
}
