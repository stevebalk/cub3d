/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:54:02 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/02 16:24:48 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	convert_rgb_to_int(t_color *color)
{
	return (color->r << 16 | color->g << 8 | color->b);
}

int	convert_map_dir_to_render_dir(t_player_pos *player)
{
	if (player->view == 0)
		return (NORTH);
	else if (player->view == 90)
		return (EAST);
	else if (player->view == 180)
		return (SOUTH);
	else if (player->view == 270)
		return (WEST);
	return (-1);
}

void	convert_map(t_cub *cub, t_map *map)
{
	cub->map = translate_char_to_int_map(cub, map->map);
	cub->wall_texture_paths[EAST] = map->textures[EA];
	cub->wall_texture_paths[SOUTH] = map->textures[SO];
	cub->wall_texture_paths[WEST] = map->textures[WE];
	cub->wall_texture_paths[NORTH] = map->textures[NO];
	cub->ceilling_color = convert_rgb_to_int(&map->c);
	cub->floor_color = convert_rgb_to_int(&map->f);
	cub->player.pos = (t_vec2){map->player_start_pos.x + 0.5,
		map->player_start_pos.y + 0.5};
	cub->player.start_direction = convert_map_dir_to_render_dir(
			&map->player_start_pos);
	ft_free_array((void **)map->map);
	free(map->textures);
}

void	init_cub(t_cub *cub, t_map *map)
{
	ft_bzero(cub, sizeof(t_cub));
	convert_map(cub, map);
	cub->win_size = (t_vec2i){WIN_WIDTH, WIN_HEIGHT};
	cub->win_center = (t_vec2i){cub->win_size.x / 2, cub->win_size.y / 2};
	cub->delta_time = 0.0;
	cub->current_frame_time = get_time_seconds();
	cub->last_frame_time = cub->current_frame_time;
	cub->resolution = 1;
	init_map(cub);
	init_player(cub);
	init_minimap(cub);
	init_mlx(cub);
	init_mlx_hooks(cub);
	init_textures(cub);
	init_sprites(cub);
}
