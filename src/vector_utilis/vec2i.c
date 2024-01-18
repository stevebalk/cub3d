/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:29:15 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 12:30:19 by sbalk            ###   ########.fr       */
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

t_vec2i	mult_vec2i(t_vec2i a, t_vec2i b)
{
	t_vec2i	c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return (c);
}

t_vec2i	div_vec2i(t_vec2i a, t_vec2i b)
{
	t_vec2i	c;

	c.x = a.x / b.x;
	c.y = a.y / b.y;
	return (c);
}

t_vec2i	mod_vec2i(t_vec2i a, t_vec2i b)
{
	t_vec2i	c;

	c.x = a.x % b.x;
	c.y = a.y % b.y;
	return (c);
}
