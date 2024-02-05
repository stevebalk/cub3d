/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:17 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/05 11:59:19 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// returns 1 if the str contains only c
int	check_line_for_only(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			str++;
		else
			return (0);
	}
	return (1);
}

// return 1 if str is in line
int	check_line_for_str(char *line, char *str)
{
	while (*line)
	{
		if (ft_strncmp(line, str, ft_strlen(str)) == 0)
			return (1);
		line++;
	}
	return (0);
}

// return the number of chars of charset in line
int	has_at_least_one_occurence_of_charset(char *line, char *charset)
{
	int	i;
	int	res;

	res = 0;
	if (ft_strlen(line) == 0)
		return (0);
	i = 0;
	while (line[i])
	{
		if (check_char_in_chars(line[i], charset))
			res++;
		i++;
	}
	return (res);
}

//return 1 if arr contains only printable characters
int	check_arr_for_printable_chars(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isprint(arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
