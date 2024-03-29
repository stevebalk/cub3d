/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:53:57 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 13:43:30 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_window(t_cub *cub)
{
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (cub->win == NULL)
		error_msg(cub, "Error: mlx_new_window failed", 1, 1);
}

void	init_mlx_image(t_cub *cub, t_data **img, t_vec2i size)
{
	*img = ft_calloc(1, sizeof(t_data));
	if (img == NULL)
		error_msg(cub, "Error: init_mlx ft_calloc failed", 1, 1);
	(*img)->img = mlx_new_image(cub->mlx, size.x, size.y);
	if ((*img)->img == NULL)
		error_msg(cub, "Error: mlx_new_image failed", 0, 1);
	(*img)->addr = mlx_get_data_addr((*img)->img,
			&((*img)->bpp),
			&((*img)->line_length), &((*img)->endian));
	if ((*img)->addr == NULL)
		error_msg(cub, "Error: mlx_get_data_addr failed", 0, 1);
	(*img)->win_size = cub->win_size;
}

void	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		error_msg(cub, "Error: mlx_init failed", 1, 1);
	init_mlx_window(cub);
	init_mlx_image(cub, &cub->img, cub->win_size);
}

void	init_mlx_hooks(t_cub *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->win, 6, 1L << 6, mouse_move, cub);
	mlx_hook(cub->win, 17, 1L << 17, &close_window, cub);
}
