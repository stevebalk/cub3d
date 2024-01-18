/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:58:39 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 11:59:58 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_cub *cub)
{
	int		**map;
	int		i;
	int		j;

	i = 0;
	map = (int **)malloc(sizeof(int *) * cub->map_size.x);
	while (i < cub->map_size.x)
	{
		j = 0;
		map[i] = (int *)malloc(sizeof(int) * cub->map_size.y);
		while (j < cub->map_size.y)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	cub->map = map;
}
