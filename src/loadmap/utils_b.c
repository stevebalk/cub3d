/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:59:58 by jonas             #+#    #+#             */
/*   Updated: 2024/02/03 17:01:48 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// returns the count of a char in a string
int	count_char_in_str(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

// returns the count of a char in an array
int	count_char_in_arr(char **arr, char c)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (arr[++i])
		count += count_char_in_str(arr[i], c);
	return (count);
}

// builds a t_color from ints
t_color	get_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

void	replace_char_in_arr(char **arr, char find, char replace)
{
	int		i;
	size_t	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (j < ft_strlen(arr[i]))
		{
			if (arr[i][j] == find)
			{
				arr[i][j] = replace;
				break ;
			}
			if (arr[i][j] == '\0')
				break ;
			j++;
		}
		i++;
	}
}

// replace char at pos
void	replace_char_at_pos(char **arr, int row, int col, char c)
{
	int	count_row;
	int	len_col;

	count_row = get_arr_len(arr);
	len_col = ft_strlen(arr[row]);
	if (row > count_row || col > len_col)
	{
	}
	else
		arr[row][col] = c;
}
