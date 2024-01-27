/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:27:47 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/27 21:24:14 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calculate_fps(t_cub *cub)
{
	cub->fps.frames++;
	time(&cub->fps.current_time);
	cub->fps.delta_time = difftime(cub->fps.current_time, cub->fps.start_time);
	if (cub->fps.delta_time >= 1.0)
	{
		cub->fps.fps = cub->fps.frames / cub->fps.delta_time;
		cub->fps.frames = 0;
		time(&cub->fps.start_time);
	}
}

static void	draw_fps(t_cub *cub, t_vec2i pos)
{
	char	*fps_str;
	char	*tmp;

	tmp = ft_itoa(cub->fps.fps);
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
