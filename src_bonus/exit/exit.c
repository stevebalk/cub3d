/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:52:59 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 16:28:25 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	close_window(t_cub *cub)
{
	mlx_do_key_autorepeaton(cub->mlx);
	free_everything(cub);
	exit(0);
	return (0);
}

void	free_everything(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->wall_textures[i].img)
			mlx_destroy_image(cub->mlx, cub->wall_textures[i].img);
		i++;
	}
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->img && cub->img->img)
	{
		mlx_destroy_image(cub->mlx, cub->img->img);
		free(cub->img);
	}
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	ft_free_array((void **) cub->map);
}
