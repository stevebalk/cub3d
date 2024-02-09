/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levelcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:43 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/09 15:55:36 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

void	set_first_f(char **arr)
{
	replace_char_in_arr(arr, 'N', 'F');
	replace_char_in_arr(arr, 'E', 'F');
	replace_char_in_arr(arr, 'S', 'F');
	replace_char_in_arr(arr, 'W', 'F');
}

int	flood(char **arr)
{
	int	c;
	int	r;
	int	row_count;
	int	col_count;

	row_count = get_arr_len(arr);
	r = 0;
	while (r < row_count)
	{
		c = 0;
		col_count = ft_strlen(arr[r]);
		while (c < col_count)
		{
			if (arr[r][c] == 'F')
			{
				if (!check_near_fields(arr, c, r))
					return (0);
			}
			c += 1;
		}
		r += 1;
	}
	return (1);
}

int	set_and_fill_first_f(char **arr)
{
	t_xy	tmp_pos;
	int		ret;

	ret = 1;
	set_first_f(arr);
	tmp_pos = get_pos_of_char_in_arr(arr, 'F');
	ret = check_near_fields(arr, tmp_pos.x, tmp_pos.y);
	return (ret);
}

static int	check_enclosure(char **map, int x, int y)
{
	if (map[y][x] == ' ' || map[y] == NULL || map[y][x] == 0)
		return (printf("Error\nmap has empty space or no wall\n"), 0);
	if (x < 0 || y < 0)
		return (0);
	if (map[y][x] == 'F' || map[y][x] == '1')
		return (1);
	map[y][x] = 'F';
	return (check_enclosure(map, x - 1, y) && check_enclosure(map, x, y - 1)
		&& check_enclosure(map, x + 1, y) && check_enclosure(map, x, y + 1));
}

int	check_map(t_map *s_map)
{
	char			**f_map;
	int				ret;
	t_play_pos		pos;

	f_map = copy_arr(s_map->map);
	pos = get_player(f_map);
	if (!check_enclosure(f_map, pos.x, pos.y))
		ret = 0;
	else
		ret = 1;
	if (SHOWFLOOD == 1)
		show_map(f_map);
	ft_free_array((void **)f_map);
	return (ret);
}
