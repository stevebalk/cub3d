/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:17 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/29 10:24:32 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

int get_arr_len(char **arr)
{
    int i;

    i = 0;
    while(arr[i])
        i++;
    //printf("arr len: %i\n", i);
    return (i); 
}

// returns the line count of the file
int get_line_count(char *file)
{
    int fd;
    int count = 0;
    char buf;
    int re = 1;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\nfile loading\n");
        // exit
        return (-1);
    }
    while(re > 0)
    {
        re = read(fd, &buf, 1);
        if (buf == '\n')
            count++;
        //printf("%c", buf);
    }
    if (count > 0)
        count++;
    close(fd);
    //printf("get line count: %i\n", count);
    return (count);
}

// returns the line NR where find is in
int get_line_of(char **arr, char *find, int rev)
{
    int i;
    //char *tmp_find;
	int step;

    // tmp_find = ft_strdup(find);
    // ft_strlcat(tmp_find, " \0", ft_strlen(find) + 2);
    // printf ("get_line_of  tmp_find >%s< \n", tmp_find);

    i = 0;

	step = 1;
	if (rev)
	{
		i = get_arr_len(arr) - 1;
		step = -1;
	}
	else
		i = 0;

    while(arr[i])
    {
        if (ft_strnstr(arr[i], find, ft_strlen(arr[i])) != NULL)
			return (i);
        i += step;
    }

    // if (found > 1)
    //     printf("found more than one !!!\n");
	// if (found == 0)
	// 	printf("found NO!!!\n");
	//printf("get_line_of  line: %i\n", i);
	
    return (-1);
}

// returns the bigger strlen of s1 or s2
int get_max_of_strlen(char *s1, char *s2)
{
    int len1;
    int len2;
    
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);

    if (len1 > len2)
        return (len1);
    else
        return (len2);
}

// return 1 if all entry till arr_len are !NULL
int check_if_arr_entrys_valid(char **arr, int arr_len)
{
    int i;

    i = -1;
    while (i++, i < arr_len)
    {
        if (!arr[i])
            return (0);
    }
    return (1);
}

// returns the count of a char in a string
int count_char_in_str(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i])
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
	int count;
	int i;

	i = -1;
	count = 0;

	while (arr[++i])
		count += count_char_in_str(arr[i], c);
	
	printf("count %c in array  >> %i\n", c, count);

	return (count);
}	

// builds a t_color from ints
t_color get_color(int r, int g, int b, int a)
{
    t_color color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return (color);
}

void replace_char_in_arr(char **arr, char find, char replace)
{
    int i;
    int j;
    //printf("\nreplace_char_in_arr   find: %c   replace: %c \n", find, replace);
    i = 0;
    while(arr[i])
    {
        j = 0;
        while(j < ft_strlen(arr[i]))
        {
            //printf("i: %i   j: %i \n", i, j);
            if (arr[i][j] == find)
            {
                arr[i][j] = replace;
                break;
            }
            if (arr[i][j] == '\0' )//|| arr[i])
                break;
            j++;
        }
        i++;
    }
    //printf("--- End ---\n");
}

// returns 0 if c != one of the charset
int check_char_in_chars(char c, char *charset)
{
	//c_yellow(); printf("     > check_char_in_chars() \n"); 
	c_reset();

	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (/*printf("     > ret 1\n"),*/ 1);
		i++;
	}
	//c_red();
	return (/*printf("     > ret 0\n"), */0);
}

// checks every char in the string; if it is not one of the charset --> return 0;
int check_line_for_chars(char *line, char *charset)
{
	int i;
	//c_yellow(); printf("  > check_line_for_chars() "); 
	//c_purple(); printf(" >%s<  ", line);
	//c_cyan(); printf(" >%s<  \n", charset); 
	c_reset();

	if (ft_strlen(line) == 0)
		return (/*printf("  > ret 0\n"),*/ 0);

	i = 0;
	while(line[i])
	{
			//printf("  > i: %i      c >%c<      charset >%s<\n", i, line[i], charset);
		if (!check_char_in_chars(line[i], charset))
			return (/*printf("  > ret 0\n"),*/ 0);
		i++;
	}
	return (/*printf("  > ret 1\n"),*/ 1);
}

// returns the max line char count of an array; start/end are the rows where to search
int get_max_line(char **arr, int start, int end)
{
	int max;

	max = 0;
	while(start < end && arr[start])
	{
		if (ft_strlen(arr[start]) > max)
			max = ft_strlen(arr[start]);
		start++;
	}
	//printf("get_max_line: %i\n", max);
	return (max);
}

// copys an array and allocate mem   // not testet
char **copy_arr(char **src)
{
	char **ret;
	int len;
	int i;
	
	if (!src)
		return (NULL);
		
	len = get_arr_len(src);
	ret = (char **)malloc((sizeof(char *) * (len + 1)));
	i = -1;
	while (i++, src[i])
		ret[i] = ft_strdup(src[i]);

	return (ret);
}



// returs the index where c is in line the first time
int get_pos_of_char(char *line, char c)
{
	int i;

	//c_yellow(); printf("get_pos_of_char  >%c \n", c);

	i = 0;
	while(line[i])
	{
		//printf("i: %i   >%s<", i, line);
		if (line[i] == c)	
			return (i);
		i++;
	}
	return (-1);
}
