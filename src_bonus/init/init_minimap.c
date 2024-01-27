/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:54:57 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/27 20:52:20 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_minimap(t_cub *cub)
{
	t_minimap	*mm;

	mm = &cub->minimap;
	mm->size = cub->win_size.y * 0.01 * MINIMAP_SIZE_PERCENT;
	mm->pos.x = (cub->win_size.x - mm->size) - (cub->win_size.x * 0.01
			* MINIMAP_MARGIN_X_PERCENT);
	mm->pos.y = 0 + (cub->win_size.y * 0.01 * MINIMAP_MARGIN_Y_PERCENT);
	mm->global_size_end.x = mm->pos.x + mm->size;
	mm->global_size_end.y = mm->pos.y + mm->size;
	mm->visible_tiles = MINIMAP_VISIBLE_TILES;
	mm->tile_size = mm->size / (2 * MINIMAP_VISIBLE_TILES + 1);
	mm->color_blocked = MINIMAP_COLOR_BLOCKED;
	mm->color_free = MINIMAP_COLOR_FREE;
	mm->color_player = MINIMAP_COLOR_PLAYER;
}
