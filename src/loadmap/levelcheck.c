/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levelcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:43 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/03 17:44:16 by jonas            ###   ########.fr       */
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
			c++;
		}
		r++;
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

int	check_map(t_map *s_map)
{
	char			**f_map;
	int				ret;
	unsigned long	i;
	unsigned long	len;

	f_map = copy_arr(s_map->map);
	ret = set_and_fill_first_f(f_map);
	if (!ret)
		return (0);
	len = get_arr_len(f_map) * get_max_line(f_map, 0, get_arr_len(f_map));
	i = 0;
	while (i++ <= len)
	{
		if (!flood(f_map))
		{
			ret = 0;
			break ;
		}
	}
	ft_free_array((void **)f_map);
	return (ret);
}
