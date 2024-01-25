/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:28:01 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 12:28:25 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_colliding(t_cub *cub, t_vec2 position)
{
	t_vec2i	map_pos;

	map_pos.x = (int)(position.x);
	map_pos.y = (int)(position.y);
	if (is_inside_map(cub, map_pos))
		if (cub->map[map_pos.y][map_pos.x] >= 1)
			return (1);
	return (0);
}
