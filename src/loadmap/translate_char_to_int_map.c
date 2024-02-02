/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_char_to_int_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:48:48 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/02 12:14:48 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_int_map(int **map, t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	printf("\nshow int map \n");
	while (i < cub->map_size.y)
	{
		j = 0;
		printf("i: %3i   |", i);
		while (j < cub->map_size.x)
		{
			printf("%i", map[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
	printf("--- End ---\n\n");
}

int		**translate_char_to_int_map(t_cub *cub, char **map)
{
	int		i;
	int		j;
	int		**int_map;

	i = 0;
	cub->map_size.y = get_arr_len(map);
	cub->map_size.x = get_max_line(map, 0, cub->map_size.y);
	int_map = ft_calloc(sizeof(int *), cub->map_size.y + 1);
	while (i < cub->map_size.y)
	{
		j = 0;
		int_map[i] = ft_calloc(sizeof(int), cub->map_size.x + 1);
		while (j < (int)ft_strlen(map[i]))
		{
			if (ft_isalpha(map[i][j]) || ft_is_space(&map[i][j]))
				int_map[i][j] = 0;
			else
				int_map[i][j] = map[i][j] - '0';
			j++;
		}
		i++;
	}
	// printf_int_map(int_map, cub);
	// ft_free_2darray((void ***) &map);
	return (int_map);
}
