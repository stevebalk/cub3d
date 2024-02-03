/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:00:05 by jonas             #+#    #+#             */
/*   Updated: 2024/02/03 17:05:10 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// returns the space count before a different character 
int	get_spaces_from_beginning(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	return (i);
}

// returns line length without spaces on the right
int	get_len_without_spaces_from_end(char *line)
{
	int	i;

	i = ft_strlen(line);
	i--;
	while (line[i] == ' ' && line[i])
		i--;
	return (i + 1);
}

t_xy	get_xy_pos(int x, int y)
{
	t_xy	xy;

	xy.x = x;
	xy.y = y;
	return (xy);
}

// returs the pos of the first occurence of c in the array
t_xy	get_pos_of_char_in_arr(char **arr, char c)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (get_pos_of_char(arr[i], c) != -1)
			return (get_xy_pos(get_pos_of_char(arr[i], c), i));
		i++;
	}
	return (get_xy_pos(-1, -1));
}

// return 1 if only i.e ' ' are before char find
int	check_only_c_before_find(char *str, char c, char find)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != find)
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
