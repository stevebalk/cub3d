/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:45:40 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/05 16:00:52 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_wall_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->wall_textures[i].img)
			mlx_destroy_image(cub->mlx, cub->wall_textures[i].img);
		if (cub->wall_texture_paths[i])
			free(cub->wall_texture_paths[i]);
		i++;
	}
}

void	free_sprite_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->sprite_textures[i].img)
			mlx_destroy_image(cub->mlx, cub->sprite_textures[i].img);
		i++;
	}
}

void	free_sprites(t_cub *cub)
{
	if (cub->sprites)
		free(cub->sprites);
}

void	free_mlx(t_cub *cub)
{
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
}

void	free_everything(t_cub *cub)
{
	free_wall_textures(cub);
	free_sprite_textures(cub);
	free_sprites(cub);
	free_mlx(cub);
	ft_free_array((void **) cub->map);
}
