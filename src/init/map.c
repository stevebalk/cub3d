/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:58:39 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/23 17:29:03 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_cub *cub)
{
	int		**map;
	int		i;
	int		j;

	i = 0;
	map = (int **)ft_calloc(cub->map_size.x + 1, sizeof(int *));
	if (!map)
		exit_error(cub, 1, "Malloc failed");
	while (i < cub->map_size.x)
	{
		j = 0;
		map[i] = (int *)ft_calloc(cub->map_size.y + 1, sizeof(int));
		if (!map[i])
			exit_error(cub, 1, "Malloc failed");
		while (j < cub->map_size.y)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	cub->map = map;
}
