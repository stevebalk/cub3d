/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 13:40:05 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[TEST_MAP_SIZE_X][TEST_MAP_SIZE_Y]= {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

// int	main(void)
// {
// 	t_cub cub;
// 	double cameraX;
// 	double rayDirX;
// 	double rayDirY;
// 	int mapX;
// 	int mapY;
	// double sideDistX;
	// double sideDistY;
	// double deltaDistX;
	// double deltaDistY;
	// double perpWallDist;
	// int stepX;
	// int stepY;
	// int hit;
	// int side;
	// int lineHeight;
	// int drawStart;
	// int drawEnd;
	// int color;
	// int x;
	// int y;
	// int i;
	// int w;

	// i = 0;
	// w = 100;
	// init_cub(&cub);

	// while (i < w)
	// {
		//calculate ray position and direction
		// cameraX = 2 * i / (double)cub.win_size.x - 1; //x-coordinate in camera space
		// rayDirX = cub.player.dir.x + cub.player.plane.x * cameraX;
		// rayDirY = cub.player.dir.y + cub.player.plane.y * cameraX;
		//which box of the map we're in
		// mapX = (int)cub.player.pos.x;
		// mapY = (int)cub.player.pos.y;
		//length of ray from current position to next x or y-side
		// double sideDistX;
		// double sideDistY;
		//length of ray from one x or y-side to next x or y-side
		// double deltaDistX;
		// double deltaDistY;
		//perpWallDist;
		//what direction to step in x or y-direction (either +1 or -1)
		// int stepX;
		// int stepY;
		//was there a wall hit?
		// int hit;
		//was a NS or a EW wall hit?
		// int side;
		//calculate step and initial sideDist
		// if (rayDirX < 0)
		// {
			// stepX = -1;
			// sideDistX = (cub.player.pos.x - mapX) * deltaDistX;
		// }
		// else
		// {
			// stepX = 1;
			// sideDistX = (mapX + 1.0 - cub.player.pos.x) * deltaDistX;
		// }
// 	}
// 	mlx_put_image_to_window(cub.mlx, cub.win, cub.img->img, 0, 0);
// 	mlx_loop(cub.mlx);
// 	return (0);
// }

void	transfers_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < TEST_MAP_SIZE_X)
	{
		j = 0;
		while (j < TEST_MAP_SIZE_Y)
		{
			cub->map[i][j] = worldMap[i][j];
			j++;
		}
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	t_vec2i	pos;
	t_vec2i	size;
	int		color;

	pos.x = cub->player.pos.x * TILE_SIZE_HALF;
	pos.y = cub->player.pos.y * TILE_SIZE_HALF;
	size.x = TILE_SIZE_HALF;
	size.y = TILE_SIZE_HALF;
	color = 0x00FFFFFF;
	draw_circle(cub->img, pos, size.x / 2, color);
}

int	main(void)
{
	t_cub cub;

	ft_bzero(&cub, sizeof(t_cub));
	init_cub(&cub);
	transfers_map(&cub);
	draw_map(&cub, (t_vec2i){0, 0});
	init_mouse(&cub);
	draw_player(&cub);
	move_mouse_to_center(&cub);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img->img, 0, 0);
	mlx_loop(cub.mlx);
	return (0);
}