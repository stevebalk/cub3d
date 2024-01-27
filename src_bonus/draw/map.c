/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/27 19:30:12 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// void draw_minimap(t_cub *cub, t_vec2i pos)
// {
// 	t_vec2i	i;
// 	t_vec2i	j;
// 	t_vec2i	local_pos;
// 	int		color;

// 	i.x = 0;
// 	i.y = 0;
// 	j.x = cub->map_size.x;
// 	j.y = cub->map_size.y;
// 	while (i.y < j.y)
// 	{
// 		i.x = 0;
// 		while (i.x < j.x)
// 		{
// 			local_pos.x = i.x * TILE_SIZE ;
// 			local_pos.y = i.y * TILE_SIZE ;
// 			if (cub->map[i.y][i.x] == 1)
// 				color = 0x00FFFFFF;
// 			else if (cub->map[i.y][i.x] >= 2)
// 				color = 0x00FF0000;
// 			else
// 				color = 0x00000000;
// 			draw_square(cub->img, add_vec2i(local_pos, pos), TILE_SIZE, color);
// 			i.x++;
// 		}
// 		i.y++;
// 	}
// }

// void	draw_minimap_cells(t_cub *cub, t_vec2i start_cell, t_vec2i end_cell)
// {
// 	// t_vec2i	i;
// 	// t_vec2i	j;
// 	// t_vec2i	local_pos;
// 	// int		color;

// 	// i.x = start_cell.x;
// 	// i.y = start_cell.y;
// 	// j.x = end_cell.x;
// 	// j.y = end_cell.y;

// 	int	x;
// 	int	y;
// 	(void) end_cell;
// 	int	tile_size;

// 	// printf("Start cell: %d, %d\n", start_cell.x, start_cell.y);

// 	tile_size = cub->minimap.size.x / (cub->minimap.range * 2);
// 	y = 0;
// 	while (y < cub->minimap.range * 2)
// 	{
// 		x = 0;
// 		while (x < cub->minimap.range * 2)
// 		{
// 			// if (y + 1 == cub->minimap.range && x + 1 == cub->minimap.range)
// 				// draw_square(cub->img, add_vec2i(start_cell, scale_vec2i((t_vec2i){x, y}, tile_size)), tile_size, 0x00FFFF00);
// 			if (start_cell.y + y >= cub->map_size.y || start_cell.x + x >= cub->map_size.x || start_cell.y + y < 0 || start_cell.x + x < 0)
// 				draw_square(cub->img, add_vec2i(start_cell, scale_vec2i((t_vec2i){x, y}, tile_size)), tile_size, 0x00000000);
// 			else if (cub->map[start_cell.y + y][start_cell.x + x] == 0)
// 				draw_square(cub->img, add_vec2i(start_cell, scale_vec2i((t_vec2i){x, y}, tile_size)), tile_size, 0x00000000);
// 			else
// 				draw_square(cub->img, add_vec2i(start_cell, scale_vec2i((t_vec2i){x, y}, tile_size)), tile_size, 0x00FF0000);
// 			x++;
// 			// printf("Pos x: %d :y %d\n", add_vec2i(start_cell, scale_vec2i((t_vec2i){x, y}, tile_size)).x, add_vec2i(start_cell, scale_vec2i((t_vec2i){y, x}, tile_size)).y);
// 		}
// 		y++;
// 		draw_circle(cub->img, scale_vec2i((t_vec2i){cub->minimap.range, cub->minimap.range}, tile_size), tile_size / 2, 0x00FFFF00);
// 	}
	// draw_circle(cub->img, add_vec2i(start_cell, scale_vec2i((t_vec2i){x, y}, tile_size / 2, 0x00FFFF00);

	// while (i.y < j.y)
	// {
	// 	i.x = start_cell.x;
	// 	while (i.x < j.x)
	// 	{
	// 		local_pos.x = i.x * TILE_SIZE ;
	// 		local_pos.y = i.y * TILE_SIZE ;
	// 		if (cub->map[i.y][i.x] == 1)
	// 			color = 0x00FFFFFF;
	// 		else if (cub->map[i.y][i.x] >= 2)
	// 			color = 0x00FF0000;
	// 		else
	// 			color = 0x00000000;
	// 		draw_square(cub->img, add_vec2i(local_pos, cub->minimap.pos), TILE_SIZE, color);
	// 		i.x++;
	// 	}
	// 	i.y++;
	// }
// }


// void draw_minimap(t_cub *cub)
// {
// 	t_vec2i	start_cell;
// 	t_vec2i	end_cell;

// 	start_cell.x = (int)cub->player.pos.x - cub->minimap.range * cub->minimap.zoom;
// 	start_cell.y = (int)cub->player.pos.y - cub->minimap.range * cub->minimap.zoom;
// 	end_cell.x = (int)cub->player.pos.x + cub->minimap.range * cub->minimap.zoom;
// 	end_cell.y = (int)cub->player.pos.y + cub->minimap.range * cub->minimap.zoom;
// 	draw_minimap_cells(cub, start_cell, end_cell);
// }

// 	for (int i = cub->player.pos.y - visible_tiles; i <= cub->player.pos.y + visible_tiles; i++) {
// 		for (int j = cub->player.pos.x - visible_tiles; j <= cub->player.pos.x + visible_tiles; j++) {
// void	draw_minimap(t_cub *cub)
// {
// 	int visible_tiles;
// 	int i;
// 	int j;

// 	visible_tiles = 5;
// 	i = round(cub->player.pos.y - visible_tiles);
// 	j = round(cub->player.pos.x - visible_tiles);
// 	while (i <= cub->player.pos.y + visible_tiles)
// 	{
// 		j = round(cub->player.pos.x - visible_tiles);
// 		while (j <= cub->player.pos.x + visible_tiles)
// 		{
// 			int draw_x = cub->minimap.pos.x + (j - (cub->player.pos.x - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));
// 			int draw_y = cub->minimap.pos.y + (i - (cub->player.pos.y - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));

// 			if (i >= 0 && i < cub->map_size.x && j >= 0 && j < cub->map_size.y)
// 			{
// 				if (cub->map[i][j] == 0)
// 				{
// 					if (i == (int)(cub->player.pos.y + visible_tiles) && j == (int)(cub->player.pos.x + visible_tiles))
// 					{
// 						draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){(cub->minimap.pos.x + cub->minimap.size - draw_x)  - cub->minimap.size / (visible_tiles * 2 + 1) , (cub->minimap.pos.y + cub->minimap.size - draw_y) - cub->minimap.size / (visible_tiles * 2 + 1)}, 0x00333333);
// 						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);
// 					}
// 					else if (i == (int)(cub->player.pos.y + visible_tiles))
// 					{
// 						draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){cub->minimap.size / (visible_tiles * 2 + 1) , (cub->minimap.pos.y + cub->minimap.size - draw_y) - cub->minimap.size / (visible_tiles * 2 + 1)}, 0x00333333);
// 						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);

// 					}
// 					else if (j == (int)(cub->player.pos.x + visible_tiles))
// 					{
// 						draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){(cub->minimap.pos.x + cub->minimap.size - draw_x)  - cub->minimap.size / (visible_tiles * 2 + 1) ,cub->minimap.size / (visible_tiles * 2  + 1) }, 0x00333333);
// 						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);

// 					}
// 					else
// 					{
// 						draw_square(cub->img, (t_vec2i){draw_x, draw_y}, cub->minimap.size / (visible_tiles * 2 + 1), 0x00333333);
// 						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);
// 					}
// 				}
// 				// else if (cub->map[i][j] >= 1)
// 				// {
// 				// 	if (i == (int)(cub->player.pos.y + visible_tiles))
// 				// 	{
// 				// 		draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){cub->minimap.pos.x + cub->minimap.size - draw_x , cub->minimap.pos.y + cub->minimap.size - draw_y}, 0x00000000);
// 				// 		printf("Draw x: %d\n", cub->minimap.pos.x + cub->minimap.size - draw_x);
// 				// 	}
// 				// 	else
// 				// 	{
// 				// 		draw_square(cub->img, (t_vec2i){draw_x, draw_y}, cub->minimap.size / (visible_tiles * 2 + 1), 0x00000000);
// 				// 		put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFFFF);
// 				// 	}
// 				// }
// 			}
// 			else
// 			{
// 				// draw_square(cub->img, (t_vec2i){draw_x, draw_y}, cub->minimap.size / visible_tiles, 0x00000000);
// 				put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}


// 	int minimap_player_x = cub->minimap.pos.x + (cub->player.pos.x - (cub->player.pos.x - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));
// 	int minimap_player_y = cub->minimap.pos.y + (cub->player.pos.y - (cub->player.pos.y - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));
// 	draw_circle(cub->img, (t_vec2i){minimap_player_x, minimap_player_y}, cub->minimap.size / visible_tiles / 8, 0x00FFFF00);
// }

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
			if (start.x >= minimap->pos.x && start.x < minimap->global_size_end.x
				&& start.y >= minimap->pos.y && start.y < minimap->global_size_end.y)
			{
				put_pixel(cub->img, start, color);
			}
			// else
			// 	printf("LOLOL\n");
			start.y++;
		}
		start.x++;
	}
}

void	draw_minimap(t_cub *cub)
{
	t_vec2i		map_pos;
	int			map_size;
	int			tile_size;
	int			visible_tiles;
	int			i;
	int			j;
	// t_vec2i		draw_pos;
	t_player	*player;
	t_vec2i		tile_pos;
	// int			offset;

	map_size = cub->win_size.y * 0.2;
	map_pos.x = cub->win_size.x - map_size - 0.05 * map_size;
	map_pos.y = 0 + 0.05 * map_size;
	visible_tiles = 5;
	player = &cub->player;
	tile_size = map_size / (2 * visible_tiles + 1);
	cub->minimap.tile_size = tile_size;
	cub->minimap.pos.x = map_pos.x;
	cub->minimap.pos.y = map_pos.y;
	cub->minimap.global_size_end.x = map_pos.x + map_size;
	cub->minimap.global_size_end.y = map_pos.y + map_size;
	i = player->pos.x - visible_tiles * 1.5;
	while (i < player->pos.x + visible_tiles * 1.5)
	{
		j = player->pos.y - visible_tiles * 1.5;
		while (j < player->pos.y + visible_tiles * 1.5)
		{
			tile_pos.x = map_pos.x + (i - (player->pos.x - visible_tiles)) * tile_size;
			tile_pos.y = map_pos.y + (j - (player->pos.y - visible_tiles)) * tile_size;
			if (i >= 0 && i < cub->map_size.x && j >= 0 && j < cub->map_size.y)
			{
				if (cub->map[j][i] >= 1)
					draw_minimap_square(cub, tile_pos, 0x00000000);
					// draw_square(cub->img, tile_pos, tile_size, 0x00000000);
				else
					draw_minimap_square(cub, tile_pos, 0x00FFFFFF);
					// draw_square(cub->img, tile_pos, tile_size, 0x00FFFFFF);
			}
			else
				draw_minimap_square(cub, tile_pos, 0x00333333);
				// draw_square(cub->img, tile_pos, tile_size, 0x00333333);
			j++;
		}
		i++;
	}
	int minimap_player_x = map_pos.x + (player->pos.x - (player->pos.x - visible_tiles)) * (map_size / (2 * visible_tiles + 1));
	int minimap_player_y = map_pos.y + (player->pos.y - (player->pos.y - visible_tiles)) * (map_size / (2 * visible_tiles + 1));
	draw_circle(cub->img, (t_vec2i){minimap_player_x, minimap_player_y}, cub->minimap.size / visible_tiles / 8, 0x00FFFF00);
	// draw_minimap_square(cub, (t_vec2i){0, 0}, 0x00000000);
}
