/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fields_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:32:52 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/03 16:30:17 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// checks if the pos is valid
int	check_down(char **arr, int x, int y)
{
	int	arr_len;

	arr_len = get_arr_len(arr);
	if (y + 1 >= arr_len)
		return (0);
	if (x >= (int)ft_strlen(arr[y + 1]))
		return (0);
	else
	{
		if (!check_field(arr, x, y + 1))
			return (0);
	}
	return (1);
}

// checks if the pos is valid
int	check_up(char **arr, int x, int y)
{
	if (y - 1 < 0)
		return (0);
	if (x >= (int)ft_strlen(arr[y - 1]))
		return (0);
	else
	{
		if (!check_field(arr, x, y - 1))
			return (0);
	}
	return (1);
}

// checks if the pos is valid
int	check_right(char **arr, int x, int y)
{
	if (x + 1 >= (int)ft_strlen(arr[y]))
		return (0);
	else
	{
		if (!check_field(arr, x + 1, y))
			return (0);
	}
	return (1);
}

// checks if the pos is valid
int	check_left(char **arr, int x, int y)
{
	if (x - 1 < 0)
		return (0);
	else
	{
		if (!check_field(arr, x - 1, y))
			return (0);
	}
	return (1);
}

/* checks all reachable fields of the acutal position
and fills with F if possible */
int	check_near_fields(char **arr, int x, int y)
{
	if (!check_up(arr, x, y))
		return (printf("Error!\nmap has empty space or no wall\n"), 0);
	if (!check_right(arr, x, y))
		return (printf("Error!\nmap has empty space or no wall\n"), 0);
	if (!check_down(arr, x, y))
		return (printf("Error!\nmap has empty space or no wall\n"), 0);
	if (!check_left(arr, x, y))
		return (printf("Error!\nmap has empty space or no wall\n"), 0);
	return (1);
}
