/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fields_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:45 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/05 14:51:50 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

void	show_flood(char **arr)
{
	if (SHOWFLOOD == 1)
	{
		usleep(5000);
		clear_screen();
		show_map(arr);
	}
}
#ifndef BONUS
int	check_field(char **arr, int x, int y)
{
	int	col_len;
	int	arr_len;

	col_len = ft_strlen(arr[y]);
	arr_len = get_arr_len(arr);
	if (x == 0 || x == col_len || y == 0 || y == arr_len - 1)
	{
		if (arr[y][x] != '1')
			return (0);
	}
	if (arr[y][x] == '0')
	{
		if (x == 0 || x == col_len - 1)
			return (0);
		if (y == 0 || y == arr_len - 1)
			return (0);
		replace_char_at_pos(arr, y, x, 'F');
		show_flood(arr);
	}
	else if (arr[y][x] == ' ')
		return (0);
	return (1);
}
#else

int	check_field(char **arr, int x, int y)
{
	int	col_len;
	int	arr_len;

	col_len = ft_strlen(arr[y]);
	arr_len = get_arr_len(arr);
	if (x == 0 || x == col_len || y == 0 || y == arr_len - 1)
	{
		if (arr[y][x] != '1')
			return (0);
	}
	if (arr[y][x] == '0' || arr[y][x] == '2'
	|| arr[y][x] == '3' || arr[y][x] == '4' || arr[y][x] == '5')
	{
		if (x == 0 || x == col_len - 1)
			return (0);
		if (y == 0 || y == arr_len - 1)
			return (0);
		replace_char_at_pos(arr, y, x, 'F');
		show_flood(arr);
	}
	else if (arr[y][x] == ' ')
		return (0);
	return (1);
}
#endif
