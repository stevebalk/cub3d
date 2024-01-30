/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:54:02 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 13:04:14 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}
