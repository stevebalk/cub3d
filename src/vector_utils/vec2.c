/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:30:35 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 15:36:42 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Add a vec2 to a vec2
t_vec2	add_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

// Subtract a vec2 from a vec2
t_vec2	sub_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return (c);
}

// Multiply a vec2 by a vec2
t_vec2	mult_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return (c);
}

// Divide a vec2 by a vec2
t_vec2	div_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = a.x / b.x;
	c.y = a.y / b.y;
	return (c);
}

// Modulo a vec2 by a vec2
t_vec2	mod_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2	c;

	c.x = fmod(a.x, b.x);
	c.y = fmod(a.y, b.y);
	return (c);
}

// Scale a vec2 by a double
t_vec2	scale_vec2(t_vec2 a, double scale)
{
	t_vec2	c;

	c.x = a.x * scale;
	c.y = a.y * scale;
	return (c);
}
