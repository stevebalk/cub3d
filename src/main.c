/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/01 17:27:22 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "j_header.h"


int		celling_color = 0x000000FF;
int		floor_color = 0x00333333;

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
	// t_cub	cub;
	t_map	map;

	if (!load_and_check(&map, argc, argv))
	{
		free_s_map(&map);
		return (EXIT_FAILURE);
	}
	// ft_bzero(&cub, sizeof(t_cub));
	// cub.wall_texture_paths[0] = "textures/wall_1.xpm";
	// cub.wall_texture_paths[1] = "textures/wall_2.xpm";
	// cub.wall_texture_paths[2] = "textures/wall_3.xpm";
	// cub.wall_texture_paths[3] = "textures/wall_4.xpm";

	// init_cub(&cub);
	// mlx_do_key_autorepeatoff(cub.mlx);
	// cub.ceilling_color = celling_color;
	// cub.floor_color = floor_color;
	// transfers_map(&cub);
	// mlx_loop_hook(cub.mlx, render_loop, &cub);
	// mlx_loop(cub.mlx);
	return (0);
}
