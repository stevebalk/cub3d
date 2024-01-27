/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/27 20:41:17 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_minimap_square(t_cub *cub, t_vec2i pos, int color)
{
	t_vec2i		start;
	t_vec2i		end;
	t_minimap	*minimap;

	minimap = &cub->minimap;
	start.x = pos.x;
	start.y = pos.y;
	end.x = pos.x + minimap->tile_size;
	end.y = pos.y + minimap->tile_size;
	while (start.x < end.x)
	{
		start.y = pos.y;
		while (start.y < end.y)
		{
			if (start.x >= minimap->pos.x
				&& start.x < minimap->global_size_end.x
				&& start.y >= minimap->pos.y
				&& start.y < minimap->global_size_end.y)
			{
				put_pixel(cub->img, start, color);
			}
			start.y++;
		}
		start.x++;
	}
}

static void	draw_player(t_cub *cub)
{
	t_minimap	*mm;
	t_player	*player;
	t_vec2i		player_pos;

	mm = &cub->minimap;
	player = &cub->player;
	player_pos.x = mm->pos.x + (player->pos.x
			- (player->pos.x - mm->visible_tiles))
		* (cub->minimap.size / (2 * mm->visible_tiles + 1));
	player_pos.y = mm->pos.y + (player->pos.y
			- (player->pos.y - mm->visible_tiles))
		* (cub->minimap.size / (2 * mm->visible_tiles + 1));
	draw_circle(cub->img, player_pos, cub->minimap.size / mm->visible_tiles
		/ 8, mm->color_player);
}

static void	draw_tile(t_cub *cub, t_vec2i tile_offset, t_vec2i tile_pos)
{
	if (is_inside_map(cub, tile_offset))
	{
		if (cub->map[tile_offset.y][tile_offset.x] >= 1)
			draw_minimap_square(cub, tile_pos, cub->minimap.color_blocked);
		else
			draw_minimap_square(cub, tile_pos, cub->minimap.color_free);
	}
	else
		draw_minimap_square(cub, tile_pos, cub->minimap.color_blocked);
}

static void	draw_map(t_cub *cub)
{
	t_minimap	*mm;
	t_player	*player;
	t_vec2i		tile_pos;
	t_vec2i		tile_offset;

	mm = &cub->minimap;
	player = &cub->player;
	tile_offset.x = player->pos.x - mm->visible_tiles * 1.5;
	while (tile_offset.x < player->pos.x + mm->visible_tiles * 1.5)
	{
		tile_offset.y = player->pos.y - mm->visible_tiles * 1.5;
		while (tile_offset.y < player->pos.y + mm->visible_tiles * 1.5)
		{
			tile_pos.x = mm->pos.x + (tile_offset.x - (player->pos.x
						- mm->visible_tiles)) * mm->tile_size;
			tile_pos.y = mm->pos.y + (tile_offset.y - (player->pos.y
						- mm->visible_tiles)) * mm->tile_size;
			draw_tile(cub, tile_offset, tile_pos);
			tile_offset.y++;
		}
		tile_offset.x++;
	}
}

void	draw_minimap(t_cub *cub)
{
	draw_map(cub);
	draw_player(cub);
}
