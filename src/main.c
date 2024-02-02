/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/02 12:39:44 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int		celling_color = 0x000000FF;
// int		floor_color = 0x00333333;

int	render_loop(t_cub *cub)
{
	input_handler(cub);
	draw_ceilling(cub);
	draw_floor(cub);
	move(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
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
