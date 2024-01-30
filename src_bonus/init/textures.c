/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:33 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/28 13:06:59 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	read_xpm(t_cub *cub, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(cub->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (0);
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->line_length,
			&texture->endian);
	return (1);
}

void	init_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!read_xpm(cub, &cub->wall_textures[i],
				cub->wall_texture_paths[i]))
		{
			exit_error(cub, 0, "Error: Texture could not be read!");
		}
		i++;
	}
}
