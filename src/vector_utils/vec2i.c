/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:29:15 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 13:11:57 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
