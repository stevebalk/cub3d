/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:59:46 by jonas             #+#    #+#             */
/*   Updated: 2024/02/12 11:52:39 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

int	get_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

// returns the line count of the file
int	get_line_count(char *file)
{
	int		fd;
	int		count;
	char	buf;
	int		re;

	buf = 0;
	re = 1;
	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nfile loading\n");
		return (-1);
	}
	while (re > 0)
	{
		re = read(fd, &buf, 1);
		if (buf == '\n')
			count++;
	}
	if (count > 0)
		count++;
	close(fd);
	return (count);
}

// returns the line NR where find is in
int	get_line_of(char **arr, char *find, int rev)
{
	int	i;
	int	step;

	i = 0;
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
		if (ft_strnstr(arr[i], find, ft_strlen(arr[i])) != NULL)
			return (i);
		i += step;
	}
	return (-1);
}

// returns the bigger strlen of s1 or s2
int	get_max_of_strlen(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (len1);
	else
		return (len2);
}

// return 1 if all entry till arr_len are !NULL
int	check_if_arr_entrys_valid(char **arr, int arr_len)
{
	int	i;

	i = -1;
	while (i++, i < arr_len)
	{
		if (ft_strlen(arr[i]) == 0)
			return (printf("Error\ntexture path is not valid\n"), 0);
	}
	return (1);
}
