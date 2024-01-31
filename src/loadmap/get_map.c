/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:06 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/31 12:48:12 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "j_header.h"

// return 1; if 1 charset character is in line
int has_at_least_one_occurence_of_charset(char *line, char *charset)
{
	int i;
	int res;
	// c_yellow(); printf("     > has_at_least_one_occurence_of_charset() "); 
	// c_purple(); printf(" >%s<  ", line);
	// c_cyan(); printf(" >%s<  \n", charset); 
	c_reset();

	res = 0;
	if (ft_strlen(line) == 0)
		return (/*printf("     > ret 0\n"),*/ 0);

	i = 0;
	while(line[i])
	{
		//printf("     > i: %i      c >%c<      charset >%s<\n", i, line[i], charset);
		if (check_char_in_chars(line[i], charset))
			res++;
		i++;
	}
	c_cyan();
	return (/*printf("     > ret %i\n", i),*/ 1);
}

// searches the arr; return the line number of the first line having only chars of the charset and at least 1 char of charset2
int get_line_of_chars(char **arr, char *charset, char *charset2, int rev)
{
	int i;
	int step;
	
	//c_blue(); printf("\n> get_line_of_chars() \n"); c_reset();
	step = 1;
	if (rev)
	{
		i = get_arr_len(arr) -1;
		step = -1;
	}
	else
		i = 0;
	
	while(arr[i])
	{
		if (check_line_for_chars(arr[i], charset) && has_at_least_one_occurence_of_charset(arr[i], charset2))
			return (/*printf("> ret %i\n", i),*/ i);
		i += step;
	}
	return (/*printf("> ret -1\n"),*/ -1);
}

// returns the start and end line number of the map
t_map_lines get_map_lines(char **arr, char *charset, char *charset2)
{
	t_map_lines lines;
	lines.start = get_line_of_chars(arr, " 01NESW", "01NESW", 0);
	lines.end = get_line_of_chars(arr, " 01NESW", "01NESW", 1);

	return (lines);
}

// checks between the map start and end 
int check_map_lines(char **arr, t_map_lines map_lines, char *charset, char *charset2)
{
	int i;
	int res;

	res = 1;
	i= map_lines.start;
	while(i < map_lines.end && arr[i])
	{
		//c_purple();printf("\n%i >%s<\n", i, arr[i]);c_reset();
		if (!check_line_for_chars(arr[i], charset) || !has_at_least_one_occurence_of_charset(arr[i], charset2))
		{
			res = 0;
			//c_red();printf("BREAK!!! \n\n");
			break;
		}
		i++;
	}
	//c_red();
	//printf("check_map_lines  line: %i   res: %i\n", i, res);
	return (res);
}


// returns the spaces before the map starts (spaces has to be in alle lines of the map!s)
int get_map_offset(char **arr, int start, int end)
{
	int offset;
	int i;

	offset = 99999999;
	i = 0;

	while(start < end && arr[start])
	{
		if (get_spaces_from_beginning(arr[start]) < offset)
			offset = get_spaces_from_beginning(arr[start]);
		start++;
	}
	//printf("map offset: %i \n", offset);
	return (offset);
}

void copy_arr_to_map(char **arr, t_map *s_map, t_map_lines lines, int offset)
{
	int i;
	int end_no_space;
	//c_yellow();printf("copy_arr_to_map  (line start: %i  end: %i)   offset: %i\n", lines.start, lines.end, offset); c_reset();

	s_map->map = (char **)(ft_calloc(lines.end - lines.start + 2, sizeof(char *)));
	i = 0;
	while(i < (lines.end - lines.start + 1))
	{
		//printf("i: %i   >%s< \n", i, arr[lines.start + i] + offset);
		//s_map->map[i] = ft_strdup(arr[lines.start + i] + offset);
		end_no_space = get_len_without_spaces_from_end(arr[lines.start + i]);
		//printf("end no space: %i\n", end_no_space);
		s_map->map[i] = ft_calloc(end_no_space - offset + 1, sizeof(char));
		ft_strlcpy(s_map->map[i], arr[lines.start + i] + offset, end_no_space + 1);
		
		//printf("map[%i] >%s<\n", i, s_map->map[i]);
		i++;
	}
	s_map->map[i] = NULL;
}

// returns 1 if map is ok; handles alle map loading
int get_map(t_map *s_map, char **arr)
{
	//c_yellow();printf("get_map\n"); c_reset();
	t_map_lines map_lines;
	t_map_lines offset;
	map_lines = get_map_lines(arr, " 01NESW", "01NESW");

	// c_green(); 
	// printf("first map line: %i\nlast  map line: %i\n", map_lines.start, map_lines.end);
	// printf("check map from line: %i till %i\n", map_lines.start, map_lines.end);
	// c_reset();

	if (!check_map_lines(arr, map_lines, " 01NESW", "01NESW"))
	{
		//printf("Error!\nMap not valid\n");
		return (0);
	}
	
	offset.start = get_map_offset(arr, map_lines.start, map_lines.end);
	offset.end = get_max_line(arr, map_lines.start, map_lines.end);
	
	copy_arr_to_map(arr, s_map, map_lines, offset.start);
	//show_arr(s_map->map);
	return (1);
}

// returns 1 when there is no information after the map
int check_after_map(t_map *s_map, char **arr)
{
	t_map_lines map_lines;
	int arr_len;
	
	arr_len = get_arr_len(arr);
	map_lines = get_map_lines(arr, " 01NESW", "01NESW");

	c_yellow();
	printf("check_after_map   arr_len: %i    map_line start: %i  end: %i \n", arr_len, map_lines.start, map_lines.end);
	c_reset();

	if (arr_len -1 == map_lines.end)
		return (printf("arr_len==map_lines.end\n"), 1);
	
	return (0);
	
}