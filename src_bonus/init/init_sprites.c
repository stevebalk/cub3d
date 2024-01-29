/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:59:40 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/29 15:50:29 by sbalk            ###   ########.fr       */
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
				cub->sprites[k].pos.x = j + 0.5;
				cub->sprites[k].pos.y = i + 0.5;
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

void	set_animatable_sprite(t_cub *cub, int texture_id, int frame_count, double frame_duration)
{
	int	i;

	i = 0;
	while (i < cub->sprite_count)
	{
		if (cub->sprites[i].id == texture_id)
		{
			cub->sprites[i].animatable = 1;
			cub->sprites[i].frame_count = frame_count;
			cub->sprites[i].frame_duration = frame_duration;
			cub->sprites[i].frame_width = cub->sprite_textures[cub->sprites[i].id].width / frame_count;
			cub->sprites[i].is_static = 1;
			cub->sprites[i].orientation = EAST;
		}
		i++;
	}
}

void	init_sprites(t_cub *cub)
{
	int	i;

	i = 0;
	read_sprite_textures(cub);
	count_sprites_in_map(cub);
	cub->sprites = ft_calloc(cub->sprite_count, sizeof(t_sprite));
	set_sprite_ids(cub);
	set_sprite_pos(cub);
	set_animatable_sprite(cub, 0, 3, 0.1);
	while (i < cub->sprite_count)
	{
		if (!cub->sprites[i].animatable)
			cub->sprites[i].frame_width = cub->sprite_textures[cub->sprites[i].id].width;
		i++;
	}
}
