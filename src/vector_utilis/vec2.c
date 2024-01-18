/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:30:35 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 12:37:13 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	add_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_vec2	sub_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return (c);
}

t_vec2	mult_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return (c);
}

t_vec2	div_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x / b.x;
	c.y = a.y / b.y;
	return (c);
}

t_vec2	mod_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = fmod(a.x, b.x);
	c.y = fmod(a.y, b.y);
	return (c);
}
