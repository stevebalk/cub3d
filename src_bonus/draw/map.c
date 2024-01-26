/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:15:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/26 21:56:43 by sbalk            ###   ########.fr       */
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

	// for (int i = cub->player.pos.y - visible_tiles; i <= cub->player.pos.y + visible_tiles; i++) {
		// for (int j = cub->player.pos.x - visible_tiles; j <= cub->player.pos.x + visible_tiles; j++) {
void	draw_minimap(t_cub *cub)
{
	int visible_tiles;
	int i;
	int j;

	visible_tiles = 5;
	i = round(cub->player.pos.y - visible_tiles);
	j = round(cub->player.pos.x - visible_tiles);
	while (i <= cub->player.pos.y + visible_tiles)
	{
		j = cub->player.pos.x - visible_tiles;
		while (j <= cub->player.pos.x + visible_tiles)
		{
			int draw_x = cub->minimap.pos.x + (j - (cub->player.pos.x - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));
			int draw_y = cub->minimap.pos.y + (i - (cub->player.pos.y - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));

			if (i >= 0 && i < cub->map_size.x && j >= 0 && j < cub->map_size.y)
			{
				if (cub->map[i][j] == 0)
				{
					if (i == (int)(cub->player.pos.y + visible_tiles) && j == (int)(cub->player.pos.x + visible_tiles))
					{
						draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){(cub->minimap.pos.x + cub->minimap.size - draw_x)  - cub->minimap.size / (visible_tiles * 2 + 1) , (cub->minimap.pos.y + cub->minimap.size - draw_y) - cub->minimap.size / (visible_tiles * 2 + 1)}, 0x00333333);
						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);
					}
					else if (i == (int)(cub->player.pos.y + visible_tiles))
					{
						draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){cub->minimap.size / (visible_tiles * 2 + 1) , (cub->minimap.pos.y + cub->minimap.size - draw_y) - cub->minimap.size / (visible_tiles * 2 + 1)}, 0x00333333);
						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);

					}
					else if (j == (int)(cub->player.pos.x + visible_tiles))
					{
						draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){(cub->minimap.pos.x + cub->minimap.size - draw_x)  - cub->minimap.size / (visible_tiles * 2 + 1) ,cub->minimap.size / (visible_tiles * 2  + 1) }, 0x00333333);
						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);

					}
					else
					{
						draw_square(cub->img, (t_vec2i){draw_x, draw_y}, cub->minimap.size / (visible_tiles * 2 + 1), 0x00333333);
						// put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);
					}
				}
				// else if (cub->map[i][j] >= 1)
				// {
				// 	if (i == (int)(cub->player.pos.y + visible_tiles))
				// 	{
				// 		draw_rectangle(cub->img, (t_vec2i){draw_x, draw_y}, (t_vec2i){cub->minimap.pos.x + cub->minimap.size - draw_x , cub->minimap.pos.y + cub->minimap.size - draw_y}, 0x00000000);
				// 		printf("Draw x: %d\n", cub->minimap.pos.x + cub->minimap.size - draw_x);
				// 	}
				// 	else
				// 	{
				// 		draw_square(cub->img, (t_vec2i){draw_x, draw_y}, cub->minimap.size / (visible_tiles * 2 + 1), 0x00000000);
				// 		put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFFFF);
				// 	}
				// }
			}
			else
			{
				// draw_square(cub->img, (t_vec2i){draw_x, draw_y}, cub->minimap.size / visible_tiles, 0x00000000);
				put_pixel(cub->img, (t_vec2i){draw_x, draw_y}, 0x00FFFF00);
			}
			j++;
		}
		i++;
	}


	int minimap_player_x = cub->minimap.pos.x + (cub->player.pos.x - (cub->player.pos.x - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));
	int minimap_player_y = cub->minimap.pos.y + (cub->player.pos.y - (cub->player.pos.y - visible_tiles)) * (cub->minimap.size / (2 * visible_tiles + 1));
	draw_circle(cub->img, (t_vec2i){minimap_player_x, minimap_player_y}, cub->minimap.size / visible_tiles / 8, 0x00FFFF00);
}

