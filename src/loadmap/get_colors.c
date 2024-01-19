#include "j_header.h"

int check_color(t_color color)
{
    printf("check color()\n");

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

t_color get_color_from_str(char **arr, char find)
{
    printf("get_color_from_str()  find: %c \n", find);

    int line;
    char str[2];
    str[0] = find;
    str[1] = '\0';
    
    t_color color;
    line = get_line_of(arr, str);
    printf("  > line: %i \n", line);
    // Check if line contains the find char ('F' or 'c') and 3 ','
    if ((count_char_in_str(arr[line], ',') != 2) || (count_char_in_str(arr[line], find) != 1))
    {
        printf("Line of >%c< contains not 2 Comma and 1 %c  line >%s<\n", find, find, arr[line]);
        return (get_color(-1, -1, -1, -1));
    }

    char **split;
    char *tmp_line;
    tmp_line = ft_strchr(arr[line],find);
    split = ft_split(++tmp_line, ',');
    show_arr(split);
    color.r = ft_atoi(split[0]);
    color.g = ft_atoi(split[1]);
    color.b = ft_atoi(split[2]);
    color.a = 0;

    return (color);
}