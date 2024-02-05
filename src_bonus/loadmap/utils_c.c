/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:00:02 by jonas             #+#    #+#             */
/*   Updated: 2024/02/03 17:04:39 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// returns 0 if c != one of the charset
int	check_char_in_chars(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* checks every char in the string; 
f it is not one of the charset --> return 0; */
int	check_line_for_chars(char *line, char *charset)
{
	int	i;

	if (ft_strlen(line) == 0)
		return (0);
	i = 0;
	while (line[i])
	{
		if (!check_char_in_chars(line[i], charset))
			return (0);
		i++;
	}
	return (1);
}

/* returns the max line char count of an array; start/end are the rows
where to search; spaces at the end of the line will not be counted*/
int	get_max_line(char **arr, int start, int end)
{
	int	max;

	max = 0;
	while (start < end && arr[start])
	{
		if (get_len_without_spaces_from_end(arr[start]) > max)
			max = get_len_without_spaces_from_end(arr[start]);
		start++;
	}
	return (max);
}

// copys an array and allocate mem   // not testet
char	**copy_arr(char **src)
{
	char	**ret;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = get_arr_len(src);
	ret = (char **)malloc((sizeof(char *) * (len + 1)));
	i = -1;
	while (i++, src[i])
		ret[i] = ft_strdup(src[i]);
	ret[i] = NULL;
	return (ret);
}

// returs the index where c is in line the first time
int	get_pos_of_char(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
