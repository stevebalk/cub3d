/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:06 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/05 16:04:27 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

/* searches the arr; return the line number of the first line having only chars
of the charset and at least 1 char of charset2*/
int	get_line_of_chars(char **arr, char *charset, char *charset2, int rev)
{
	int	i;
	int	step;

	step = 1;
	if (rev)
	{
		i = get_arr_len(arr) - 1;
		step = -1;
	}
	else
		i = 0;
	while (arr[i])
	{
		if (check_line_for_chars(arr[i], charset)
			&& has_at_least_one_occurence_of_charset(arr[i], charset2))
			return (i);
		i += step;
		if (step == -1)
			break ;
	}
	return (-1);
}

// returns the start and end line number of the map
t_map_lines	get_map_lines(char **arr, char *charset, char *charset2)
{
	t_map_lines	lines;

	lines.start = get_line_of_chars(arr, charset, charset2, 0);
	lines.end = get_line_of_chars(arr, charset, charset2, 1);
	return (lines);
}

/* returns the spaces before the map starts (spaces has to be in
alle lines of the map!s) */
int	get_map_offset(char **arr, int start, int end)
{
	int	offset;

	offset = 99999999;
	while (start < end && arr[start])
	{
		if (get_spaces_from_beginning(arr[start]) < offset)
			offset = get_spaces_from_beginning(arr[start]);
		start++;
	}
	return (offset);
}

void	copy_arr_to_map(char **arr, t_map *s_map, t_map_lines lines, int offset)
{
	int	i;
	int	end_no_space;

	s_map->map = (char **)(ft_calloc(lines.end - lines.start + 2,
				sizeof(char *)));
	i = 0;
	while (i < (lines.end - lines.start + 1))
	{
		end_no_space = get_len_without_spaces_from_end(arr[lines.start + i]);
		s_map->map[i] = ft_calloc(end_no_space - offset + 1, sizeof(char));
		ft_strlcpy(s_map->map[i], arr[lines.start + i] + offset,
			end_no_space + 1);
		i++;
	}
	s_map->map[i] = NULL;
}

// returns 1 if map is ok; handles alle map loading
int	get_map(t_map *s_map, char **arr)
{
	t_map_lines	map_lines;
	t_map_lines	offset;

	map_lines = get_map_lines(arr, " 012345NESW", "012345NESW");
	if (!check_map_lines(arr, map_lines, " 012345NESW", "012345NESW"))
		return (0);

	offset.start = get_map_offset(arr, map_lines.start, map_lines.end);
	offset.end = get_max_line(arr, map_lines.start, map_lines.end);
	copy_arr_to_map(arr, s_map, map_lines, offset.start);
	return (1);
}
