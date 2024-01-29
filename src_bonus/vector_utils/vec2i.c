/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:29:15 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/29 15:44:05 by sbalk            ###   ########.fr       */
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

// Rounds a vector to the nearest integer
t_vec2i	round_vec2i(t_vec2i a)
{
	t_vec2i	c;

	c.x = round(a.x);
	c.y = round(a.y);
	return (c);
}

// Rounds a vector down to the nearest integer
t_vec2i	floor_vec2i(t_vec2i a)
{
	t_vec2i	c;

	c.x = floor(a.x);
	c.y = floor(a.y);
	return (c);
}

// Rounds a vector up to the nearest integer
t_vec2i	ceil_vec2i(t_vec2i a)
{
	t_vec2i	c;

	c.x = ceil(a.x);
	c.y = ceil(a.y);
	return (c);
}

// // Returns the absolute value of a vector
// t_vec2i	abs_vec2i(t_vec2i a)
// {
// 	t_vec2i	c;

// 	c.x = abs(a.x);
// 	c.y = abs(a.y);
// 	return (c);
// }

// // Returns the minimum value of a vector
// t_vec2i	min_vec2i(t_vec2i a, t_vec2i b)
// {
// 	t_vec2i	c;

// 	c.x = min(a.x, b.x);
// 	c.y = min(a.y, b.y);
// 	return (c);
// }

// // Returns the maximum value of a vector
// t_vec2i	max_vec2i(t_vec2i a, t_vec2i b)
// {
// 	t_vec2i	c;

// 	c.x = max(a.x, b.x);
// 	c.y = max(a.y, b.y);
// 	return (c);
// }

// // Returns the sign of a vector
// t_vec2i	sign_vec2i(t_vec2i a)
// {
// 	t_vec2i	c;

// 	c.x = ft_sign(a.x);
// 	c.y = ft_sign(a.y);
// 	return (c);
// }

// // Returns the dot product of two vectors
// int	dot_vec2i(t_vec2i a, t_vec2i b)
// {
// 	return (a.x * b.x + a.y * b.y);
// }

// // Returns the cross product of two vectors
// int	cross_vec2i(t_vec2i a, t_vec2i b)
// {
// 	return (a.x * b.y - a.y * b.x);
// }

// // Returns the squared length of a vector
// int	length2_vec2i(t_vec2i a)
// {
// 	return (a.x * a.x + a.y * a.y);
// }

// // Returns the length of a vector
// double	length_vec2i(t_vec2i a)
// {
// 	return (sqrt(length2_vec2i(a)));
// }

// // Returns the distance between two vectors
// double	distance_vec2i(t_vec2i a, t_vec2i b)
// {
// 	return (length_vec2i(sub_vec2i(a, b)));
// }

// // Returns the angle between two vectors
// double	angle_vec2i(t_vec2i a, t_vec2i b)
// {
// 	return (acos(dot_vec2i(a, b) / (length_vec2i(a) * length_vec2i(b))));
// }

// // Returns the unit vector of a vector
// t_vec2	unit_vec2i(t_vec2i a)
// {
// 	t_vec2	c;
// 	double	length;

// 	length = length_vec2i(a);
// 	c.x = a.x / length;
// 	c.y = a.y / length;
// 	return (c);
// }

// // Returns the perpendicular vector of a vector
// t_vec2	perp_vec2i(t_vec2i a)
// {
// 	t_vec2	c;

// 	c.x = -a.y;
// 	c.y = a.x;
// 	return (c);
// }

// // Returns the normal vector of a vector
// t_vec2	normal_vec2i(t_vec2i a)
// {
// 	t_vec2	c;

// 	c.x = a.y;
// 	c.y = -a.x;
// 	return (c);
// }

// // Returns the midpoint of two vectors
// t_vec2	midpoint_vec2i(t_vec2i a, t_vec2i b)
// {
// 	t_vec2	c;

// 	c.x = (a.x + b.x) / 2;
// 	c.y = (a.y + b.y) / 2;
// 	return (c);
// }

// // Returns the linear interpolation between two vectors
// t_vec2	lerp_vec2i(t_vec2i a, t_vec2i b, double t)
// {
// 	t_vec2	c;

// 	c.x = lerp(a.x, b.x, t);
// 	c.y = lerp(a.y, b.y, t);
// 	return (c);
// }

// // Returns the smooth interpolation between two vectors
// t_vec2	smoothstep_vec2i(t_vec2i a, t_vec2i b, double t)
// {
// 	t_vec2	c;

// 	c.x = smoothstep(a.x, b.x, t);
// 	c.y = smoothstep(a.y, b.y, t);
// 	return (c);
// }

// // Returns the cosine interpolation between two vectors
// t_vec2	cosine_vec2i(t_vec2i a, t_vec2i b, double t)
// {
// 	t_vec2	c;

// 	c.x = cosine(a.x, b.x, t);
// 	c.y = cosine(a.y, b.y, t);
// 	return (c);
// }

// // Returns the cubic interpolation between two vectors
// t_vec2	cubic_vec2i(t_vec2i a, t_vec2i b, double t)
// {
// 	t_vec2	c;

// 	c.x = cubic(a.x, b.x, t);
// 	c.y = cubic(a.y, b.y, t);
// 	return (c);
// }

// // Returns the square root of a vector
// t_vec2	sqrt_vec2i(t_vec2i a)
// {
// 	t_vec2	c;

// 	c.x = sqrt(a.x);
// 	c.y = sqrt(a.y);
// 	return (c);
// }

// // Returns the exponential of a vector
// t_vec2	exp_vec2i(t_vec2i a)
// {
// 	t_vec2	c;

// 	c.x = exp(a.x);
// 	c.y = exp(a.y);
// 	return (c);
// }

// // Returns the power of a vector
// t_vec2	pow_vec2i(t_vec2i a, double power)
// {
// 	t_vec2	c;

// 	c.x = pow(a.x, power);
// 	c.y = pow(a.y, power);
// 	return (c);
// }	
