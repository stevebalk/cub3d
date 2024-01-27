/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:27:47 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/19 20:03:26 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <time.h>

static void	calculate_fps(t_cub *cub)
{
	cub->frames++;
	time(&cub->current_time);
	cub->delta_time = difftime(cub->current_time, cub->start_time);
	if (cub->delta_time >= 1.0)
	{
		cub->fps = cub->frames / cub->delta_time;
		cub->frames = 0;
		time(&cub->start_time);
	}
}

static void	draw_fps(t_cub *cub, t_vec2i pos)
{
	char	*fps_str;
	char	*tmp;

	tmp = ft_itoa(cub->fps);
	fps_str = ft_strjoin("FPS: ", tmp);
	free(tmp);
	mlx_string_put(cub->mlx, cub->win, pos.x, pos.y, 0x00FFFFFF, fps_str);
	free(fps_str);
}

void	draw_debug_overlay(t_cub *cub, t_vec2i pos)
{
	int	offeset_v;

	offeset_v = 20;
	calculate_fps(cub);
	draw_fps(cub, add_vec2i(pos, (t_vec2i){pos.x, pos.y + offeset_v}));
}
