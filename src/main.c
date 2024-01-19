/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/19 20:04:56 by sbalk            ###   ########.fr       */
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
	t_vec2i	target;

	pos.x = cub->player.pos.x * TILE_SIZE / 2 + 400;
	pos.y = cub->player.pos.y * TILE_SIZE / 2;
	size.x = TILE_SIZE / 2;
	size.y = TILE_SIZE / 2;
	color = 0x00FFFFFF;

	target = add_vec2i(pos, v2_to_v2i(scale_vec2(cub->player.dir, 30)));
	draw_line(cub->img, pos, target, 0x00FFFF00);
	draw_circle(cub->img, pos, size.x / 2, color);
}

int	render_loop(t_cub *cub)
{
	input_handler(cub);
	ft_bzero(cub->img->addr, cub->img->line_length * WIN_HEIGHT);
	draw_rectangle(cub->img, (t_vec2i){0, 0}, (t_vec2i){cub->win_size.x, cub->win_size.y / 2}, 0x00000000);
	draw_rectangle(cub->img, (t_vec2i){0, cub->win_size.y / 2}, (t_vec2i){cub->win_size.x, cub->win_size.y}, 0x005555FF);
	raycast(cub, cub->player.pos, cub->player.dir);
	draw_map(cub, (t_vec2i){400, 0});
	draw_player(cub);

	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	if (DEBUG)
		draw_debug_overlay(cub, (t_vec2i){0, 0});

	return (0);
}

int	main(void)
{
	t_cub cub;

	ft_bzero(&cub, sizeof(t_cub));
	init_cub(&cub);
	transfers_map(&cub);
	init_mouse(&cub);
	move_mouse_to_center(&cub);
	mlx_loop_hook(cub.mlx, render_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}