/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:47:51 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 11:48:57 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_inside_map(t_cub *cub, t_vec2i position)
{
	if (position.x >= 0 && position.x < cub->map_size.x &&
		position.y >= 0 && position.y < cub->map_size.y)
		return (1);
	return (0);
}

int	is_cell_occopied(t_cub *cub, t_vec2i pos)
{
	if (cub->map[pos.x][pos.y] >= 1)
		return (1);
	return (0);
}
