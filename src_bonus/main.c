/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:35:27 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/05 16:21:11 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

int	main(int argc, char **argv)
{
	t_cub	cub;
	t_map	map;

	if (!load_and_check(&map, argc, argv))
	{
		free_s_map(&map);
		return (EXIT_FAILURE);
	}
	init_cub(&cub, &map);
	mlx_do_key_autorepeatoff(cub.mlx);
	mlx_loop_hook(cub.mlx, render_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
