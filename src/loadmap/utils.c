#include "j_header.h"

int get_arr_len(char **arr)
{
    int i;

    i = 0;
    while(arr[i])
        i++;
    printf("arr len: %i\n", i);
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
int get_line_of(char **arr, char *find)
{
    int line;
    int found;
    int i;
    char *tmp_find;

    tmp_find = ft_strdup(find);
    ft_strlcat(tmp_find, " \0", ft_strlen(find) + 2);
    printf ("get_line_of  tmp_find >%s< \n", tmp_find);

    found = 0;
    i = 0;
    line = -1;
    while(arr[i])
    {
        if (ft_strnstr(arr[i], find, ft_strlen(arr[i])) != NULL)
        {
            found++;
            line = i;
        }
        i++;
    }

    if (found > 1)
        printf("found more than one !!!\n");

    return (line);
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
    printf("\nreplace_char_in_arr   find: %c   replace: %c \n", find, replace);
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
    printf("--- End ---\n");
}