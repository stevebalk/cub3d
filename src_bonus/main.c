/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:35:27 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 20:31:32 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int worldMap[TEST_MAP_SIZE_X][TEST_MAP_SIZE_Y]= {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1},
		{1,0,1,2,1,2,1,0,1,2,1,2,1,0,1,2,1,2,1,0,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,3,0,3,0,3,0,0,0,0,0,0,2,5,1,5,2,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,1,5,5,0,0,0,0,0,1},
		{1,0,3,0,4,0,3,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,1,5,5,0,0,0,0,0,1},
		{1,0,3,0,3,0,3,0,0,0,0,0,0,2,5,1,5,2,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

int		celling_color = 0x000000FF;
int		floor_color = 0x00333333;

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

int	render_loop(t_cub *cub)
{
	calculate_delta_time(cub);
	input_handler(cub);
	draw_ceilling(cub);
	draw_floor(cub);
	move(cub);
	raycast(cub);
	draw_sprites(cub);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	if (is_flag_set(cub->flags, FLAG_DEBUG_OVERLAY))
		draw_debug_overlay(cub, (t_vec2i){0, 0});
	return (0);
}

int	main(void)
{
	t_cub cub;

	ft_bzero(&cub, sizeof(t_cub));
	// cub.wall_texture_paths[0] = "textures/east.xpm";
	// cub.wall_texture_paths[1] = "textures/south.xpm";
	// cub.wall_texture_paths[2] = "textures/west.xpm";
	// cub.wall_texture_paths[3] = "textures/north.xpm";
	cub.wall_texture_paths[0] = "textures/wall_1.xpm";
	cub.wall_texture_paths[1] = "textures/wall_2.xpm";
	cub.wall_texture_paths[2] = "textures/wall_3.xpm";
	cub.wall_texture_paths[3] = "textures/wall_4.xpm";
	cub.sprite_paths[3] = "sprites/barrel.xpm";
	cub.sprite_paths[0] = "sprites/flaming_barrel_test.xpm";
	cub.sprite_paths[1] = "sprites/pillar.xpm";
	cub.sprite_paths[2] = "sprites/knight_statue.xpm";


	init_cub(&cub);
	mlx_do_key_autorepeatoff(cub.mlx);
	cub.ceilling_color = celling_color;
	cub.floor_color = floor_color;
	// set_flag(&cub.flags, FLAG_DEBUG_OVERLAY);
	// set_flag(&cub.flags, FLAG_MOUSE_CONTROL);
	transfers_map(&cub);
	init_sprites(&cub);
	mlx_loop_hook(cub.mlx, render_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}