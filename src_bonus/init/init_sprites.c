/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:59:40 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/28 15:58:10 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	count_sprites_in_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub->map_size.y)
	{
		j = 0;
		while (j < cub->map_size.x)
		{
			if (cub->map[i][j] >= 2 && cub->map[i][j] <= 5)
				cub->sprite_count++;
			j++;
		}
		i++;
	}
}

static void	read_sprite_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!read_xpm(cub, &cub->sprite_textures[i],
				cub->sprite_paths[i]))
		{
			exit_error(cub, 0, "Error: Texture could not be read!");
		}
		i++;
	}
}

static void	set_sprite_pos(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < cub->map_size.y)
	{
		j = 0;
		while (j < cub->map_size.x)
		{
			if (cub->map[i][j] >= 2 && cub->map[i][j] <= 5)
			{
				cub->sprites[k].x = j + 0.5;
				cub->sprites[k].y = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	set_sprite_ids(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < cub->map_size.y)
	{
		j = 0;
		while (j < cub->map_size.x)
		{
			if (cub->map[i][j] >= 2 && cub->map[i][j] <= 5)
			{
				cub->sprites[k].id = cub->map[i][j] - 2;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	init_sprites(t_cub *cub)
{
	read_sprite_textures(cub);
	count_sprites_in_map(cub);
	cub->sprites = malloc(sizeof(t_sprite) * cub->sprite_count);
	set_sprite_pos(cub);
	set_sprite_ids(cub);
	// cub->sprite_order = malloc(sizeof(int) * cub->sprite_count);
	// cub->sprite_distance = malloc(sizeof(double) * cub->sprite_count);
}
