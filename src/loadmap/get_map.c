#include "j_header.h"

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
			return (printf("     > ret 1\n"), 1);
		i++;
	}
	c_red();
	return (printf("     > ret 0\n"), 0);
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
		return (printf("  > ret 0\n"), 0);

	i = 0;
	while(line[i])
	{
			//printf("  > i: %i      c >%c<      charset >%s<\n", i, line[i], charset);
		if (!check_char_in_chars(line[i], charset))
			return (printf("  > ret 0\n"), 0);
		i++;
	}
	return (printf("  > ret 1\n"), 1);
}

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
		return (printf("     > ret 0\n"), 0);

	i = 0;
	while(line[i])
	{
		//printf("     > i: %i      c >%c<      charset >%s<\n", i, line[i], charset);
		if (check_char_in_chars(line[i], charset))
			res++;
		i++;
	}
	return (printf("     > ret %i\n", i), 1);
}

// searches the arr; return the line number of the first line having only chars of the charset and at least 1 char of charset2
int get_line_of_chars(char **arr, char *charset, char *charset2, int rev)
{
	int i;
	int step;
	
	c_blue(); printf("\n> get_line_of_chars() \n"); c_reset();
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
			return (printf("> ret %i\n", i), i);
		i += step;
	}
	return (printf("> ret -1\n"), -1);
}

t_map_lines get_map_lines(char **arr, char *charset, char *charset2)
{
	t_map_lines lines;
	lines.start = get_line_of_chars(arr, " 01NESW", "01NESW", 0);
	lines.end = get_line_of_chars(arr, " 01NESW", "01NESW", 1);

	return (lines);
}

int check_map_lines(char **arr, t_map_lines map_lines, char *charset, char *charset2)
{
	int i;
	int res;

	res = 1;
	i= map_lines.start;
	while(i < map_lines.end && arr[i])
	{
		c_purple();printf("\n%i >%s<\n", i, arr[i]);c_reset();
		if (!check_line_for_chars(arr[i], charset) || !has_at_least_one_occurence_of_charset(arr[i], charset2))
		{
			res = 0;
			c_red();
			printf("BREAK!!! \n\n");
			break;
		}
		i++;
	}
	c_red();
	printf("check_map_lines  line: %i   res: %i\n", i, res);
	return (res);
}

void get_map(char **arr)
{
	c_yellow();printf("get_map\n"); c_reset();

	// int map_line_first = -11;
	// int map_line_last = -11;
	
	// map_line_first = get_line_of_chars(arr, " 01NESW", "01NESW", 0);
	// map_line_last = get_line_of_chars(arr, " 01NESW", "01NESW", 1);
	t_map_lines map_lines;
	map_lines = get_map_lines(arr, " 01NESW", "01NESW");

	c_green(); 
	printf("first map line: %i\nlast  map line: %i\n", map_lines.start, map_lines.end);
	c_reset();
	
	c_cyan(); 
	printf("check map from line: %i till %i\n", map_lines.start, map_lines.end);
	c_reset();

	check_map_lines(arr, map_lines, " 01NESW", "01NESW");
}