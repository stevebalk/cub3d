/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:16 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/09 15:55:36 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// return 1 if color is valid
int	check_color(t_color color)
{
	if (color.r < 0 || color.r > 255)
		return (0);
	if (color.g < 0 || color.g > 255)
		return (0);
	if (color.b < 0 || color.b > 255)
		return (0);
	if (color.a < 0 || color.a > 255)
		return (0);
	return (1);
}

// checks if more elements than 1 are i a splittet , , section. 
int	check_color_section(char *str)
{
	char	**tmp;
	int		arr_len;

	tmp = ft_split(str, ' ');
	arr_len = get_arr_len(tmp);
	ft_free_array((void **)tmp);
	if (arr_len > 1)
		return (0);
	else
		return (1);
}

// return -1 if color not good
t_color	check_array_for_color(char *line, char find)
{
	char	**split;
	char	*tmp_line;
	t_color	color;

	tmp_line = ft_strchr(line, find);
	split = ft_split(++tmp_line, ',');
	if (get_arr_len(split) == 3)
	{
		if (check_color_section(split[0])
			&& check_line_for_chars(split[0], " 0123456789"))
			color.r = ft_atoi(split[0]);
		if (check_color_section(split[1])
			&& check_line_for_chars(split[1], " 0123456789"))
			color.g = ft_atoi(split[1]);
		if (check_color_section(split[2])
			&& check_line_for_chars(split[2], " 0123456789"))
			color.b = ft_atoi(split[2]);
		color.a = 0;
	}
	else
		color = get_color(-1, -1, -1, -1);
	ft_free_array((void **)split);
	return (color);
}

// returns the color of find ('C' or 'f') if not color is (-1, -1, -1, -1)
t_color	get_color_from_str(char **arr, char find)
{
	int		line;
	char	str[2];

	str[0] = find;
	str[1] = '\0';
	line = -1;
	if (get_line_of(arr, str, 0) == get_line_of(arr, str, 0))
		line = get_line_of(arr, str, 0);
	else
		return (get_color(-1, -1, -1, -1));
	if (line == -1)
		return (get_color(-1, -1, -1, -1));
	if (!check_only_c_before_find(arr[line], ' ', find))
		return (get_color(-1, -1, -1, -1));
	if ((count_char_in_str(arr[line], ',') != 2)
		|| (count_char_in_str(arr[line], find) != 1))
		return (get_color(-1, -1, -1, -1));
	if (!check_line_for_chars(arr[line], " ,FC0123456789"))
		return (get_color(-1, -1, -1, -1));
	return (check_array_for_color(arr[line], find));
}

int	get_check_color_master(t_map *s_map, char **splitted_file)
{
	s_map->f = get_color_from_str(splitted_file, 'F');
	s_map->c = get_color_from_str(splitted_file, 'C');
	if (!check_color(s_map->f))
		return (printf("Error\ninvalid floor color\n"), 0);
	if (!check_color(s_map->c))
		return (printf("Error\ninvalid ceil color\n"), 0);
	return (1);
}
