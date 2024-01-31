/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:16 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/31 13:19:42 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

int check_color(t_color color)
{
    //printf("check color()\n");

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
int check_color_section(char *str)
{
	char **tmp;
	int arr_len;
	
	tmp = ft_split(str, ' ');
	//c_cyan();printf("check_color_section() >%s<\n", str);c_reset();
	//show_arr(tmp);
	arr_len = get_arr_len(tmp);

	ft_free_array((void **)tmp);
	if (arr_len > 1)
		return (0);
	else
		return (1);
}

t_color get_color_from_str(char **arr, char find)
{
    //printf("  find: %c \n", find);

    int line;
    char str[2];
	char **split;
    char *tmp_line;
    str[0] = find;
    str[1] = '\0';
	//c_cyan();printf("get_color_from_str  find >%c< \n", find); c_reset();
    t_color color;
	if (get_line_of(arr, str, 0) == get_line_of(arr, str, 0))
	    line = get_line_of(arr, str, 0);
	else
	{
		//printf("Error!\there are 2 lines with >%s< \n", str);
		return (get_color(-1, -1, -1, -1));
	}
	if (line == -1)
	{
		//printf("Error!\there is no line with >%s< \n", str);
		return (get_color(-1, -1, -1, -1));
	}


    // printf("  > line: %i \n", line);
	
    // Check if line contains the find char ('F' or 'c') and 3 ','
    if ((count_char_in_str(arr[line], ',') != 2) || (count_char_in_str(arr[line], find) != 1))
    {
        //printf("Line of >%c< contains not 2 Comma and 1 %c  line >%s<\n", find, find, arr[line]);
        return (get_color(-1, -1, -1, -1));
    }

	// check for not allowed chars
	if (!check_line_for_chars(arr[line], " ,FC0123456789"))
	{
		//printf("Line of >%c< contains not allowed characters\n",  find);
		return (get_color(-1, -1, -1, -1));
	}

    tmp_line = ft_strchr(arr[line],find);
    split = ft_split(++tmp_line, ',');
    //show_arr(split);
	if (check_color_section(split[0]) && check_line_for_chars(split[0], " 0123456789"))
    	color.r = ft_atoi(split[0]);
	if (check_color_section(split[1]) && check_line_for_chars(split[1], " 0123456789"))
    	color.g = ft_atoi(split[1]);
	if (check_color_section(split[2]) && check_line_for_chars(split[2], " 0123456789"))
    	color.b = ft_atoi(split[2]);
    color.a = 0;

	//free(tmp_line);
	//tmp_line = NULL;
	ft_free_array((void **)split);
    return (color);
}