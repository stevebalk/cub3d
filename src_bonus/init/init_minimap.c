/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:54:57 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/27 18:17:03 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_minimap(t_cub *cub)
{
	cub->minimap.size = cub->win_size.y / 4;
	cub->minimap.range = 10;
	cub->minimap.pos.x = 0;
	cub->minimap.pos.y = 0;
	// cub->minimap.color = 0x00000000;
}