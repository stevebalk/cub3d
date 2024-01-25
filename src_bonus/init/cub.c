/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:54:02 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/26 00:14:00 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_rays(t_cub *cub)
{
	int i;
	int number_of_threads;

	i = 0;
	number_of_threads = 4;
	while (i < number_of_threads)
	{
		cub->rays[i].id = i;
		cub->rays[i].number_of_threads = number_of_threads;
		cub->rays[i].pos = &(cub->player.pos);
		cub->rays[i].win_size = &(cub->win_size);
		cub->rays[i].map_size = &(cub->map_size);
		cub->rays[i].player_dir = &(cub->player.dir);
		cub->rays[i].plane = &(cub->player.plane);
		cub->rays[i].textures = cub->wall_textures;
		cub->rays[i].img = cub->img;
		cub->rays[i].map = cub->map;
		i++;
	}
}

void	init_cub(t_cub *cub)
{
	cub->win_size = (t_vec2i){WIN_WIDTH, WIN_HEIGHT};
	cub->map_size.x = TEST_MAP_SIZE_X;
	cub->map_size.y = TEST_MAP_SIZE_Y;
	cub->win_center = (t_vec2i){cub->win_size.x / 2, cub->win_size.y / 2};
	cub->player.start_direction = EAST;
	init_map(cub);
	init_player(cub);
	init_mlx(cub);
	init_mlx_hooks(cub);
	init_textures(cub);
	init_rays(cub);
	// init_mlx_hooks(cub);
}
