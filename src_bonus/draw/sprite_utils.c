/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:24:43 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/05 16:25:43 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Sort sprites from farthest to closest
void	sort_sprites(t_cub *cub)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < cub->sprite_count)
	{
		j = 0;
		while (j < cub->sprite_count - 1)
		{
			if (cub->sprites[j].distance < cub->sprites[j + 1].distance)
			{
				tmp = cub->sprites[j];
				cub->sprites[j] = cub->sprites[j + 1];
				cub->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	calculate_sprite_distances(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->sprite_count)
	{
		cub->sprites[i].distance = ((cub->player.pos.x - cub->sprites[i].pos.x)
				* (cub->player.pos.x - cub->sprites[i].pos.x)
				+ (cub->player.pos.y - cub->sprites[i].pos.y)
				* (cub->player.pos.y - cub->sprites[i].pos.y));
		i++;
	}
}

int	is_sprite_visible(t_cub *cub, t_sprite_calc *sc)
{
	if (cub->sc.transform.y > 0 && sc->stripe > 0
		&& sc->stripe < cub->win_size.x
		&& cub->sc.transform.y < cub->z_buffer[sc->stripe])
		return (1);
	return (0);
}
