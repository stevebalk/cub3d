/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:05:59 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/05 16:10:54 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

int	check_map_valid(t_map *s_map)
{
	if (!check_player(&s_map->player_start_pos))
		return (printf("Error!\nno player or start position\n"), 0);
	return (1);
}

t_map_lines	get_map_lines_master(char **arr)
{
	t_map_lines	map_lines;

	map_lines = get_map_lines(arr, " 01NESW", "01NESW");
	return (map_lines);
}

// return 0 if there are lines other than textures, color or map
int	check_for_bad_lines(char **arr)
{
	int			i;
	t_map_lines	map_lines;

	map_lines = get_map_lines_master(arr);
	i = -1;
	while (++i < map_lines.start)
	{
		if (check_line_for_str(arr[i], "NO "))
			continue ;
		if (check_line_for_str(arr[i], "EA "))
			continue ;
		if (check_line_for_str(arr[i], "SO "))
			continue ;
		if (check_line_for_str(arr[i], "WE "))
			continue ;
		if (check_line_for_str(arr[i], "F "))
			continue ;
		if (check_line_for_str(arr[i], "C "))
			continue ;
		if (!check_line_for_only(arr[i], ' '))
			return (0);
	}
	return (1);
}

// checks between the map start and end 
int	check_map_lines(char **arr, t_map_lines map_lines,
	char *charset, char *charset2)
{
	int	i;
	int	res;

	if ((map_lines.start == -1 || map_lines.end == -1)
		|| (map_lines.start == map_lines.end)
		|| (map_lines.end - map_lines.start + 1 < 3))
		return (0);
	res = 1;
	i = map_lines.start;
	while (i < map_lines.end && arr[i])
	{
		if (!check_line_for_chars(arr[i], charset)
			|| !has_at_least_one_occurence_of_charset(arr[i], charset2))
		{
			res = 0;
			break ;
		}
		i++;
	}
	return (res);
}

// returns 1 when there is no information after the map
int	check_after_map(t_map *s_map, char **arr)
{
	t_map_lines	map_lines;
	int			arr_len;

	(void)s_map;
	arr_len = get_arr_len(arr);
	map_lines = get_map_lines(arr, " 01NESW", "01NESW");
	if (arr_len - 1 == map_lines.end)
		return (1);
	return (0);
}
