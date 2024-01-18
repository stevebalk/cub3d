/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:09:17 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 15:12:44 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Convert vec2i into a vec2 */
t_vec2	v2i_to_v2(t_vec2i vec)
{
	t_vec2	new;

	new.x = (double)vec.x;
	new.y = (double)vec.y;
	return (new);
}

/* Convert vec2 into a vec2i */
t_vec2i	v2_to_v2i(t_vec2 vec)
{
	t_vec2i	new;

	new.x = (int)round(vec.x);
	new.y = (int)round(vec.y);
	return (new);
}
