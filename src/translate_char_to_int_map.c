/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_char_to_int_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:48:48 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 15:26:29 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		**translate_char_to_int_map(t_cub *cub, char **map)
{
	int		i;
	int		j;
	int		**int_map;

	i = 0;
	int_map = ft_calloc(sizeof(int *), cub->map_size.y + 1);
	while (i < cub->map_size.y)
	{
		j = 0;
		int_map[i] = ft_calloc(sizeof(int), cub->map_size.x + 1);
		while (j < cub->map_size.x)
		{
			if (ft_isalpha(map[i][j]) || ft_is_space(&map[i][j]))
				int_map[i][j] = 0;
			else
				int_map[i][j] = map[i][j] - '0';
			j++;
		}
		i++;
	}
	return (int_map);
}
