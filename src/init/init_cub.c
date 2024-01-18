/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:54:02 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 11:10:53 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	cub->win_size = (t_vec2i){WIN_WIDTH, WIN_HEIGHT};
	cub->map_size = (t_vec2i){24, 24};
	cub->win_center = (t_vec2i){cub->win_size.x / 2, cub->win_size.y / 2};
	init_player(&cub->player);
	init_mlx(cub);
	init_mlx_hooks(cub);
	// init_mlx_hooks(cub);
}
