#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

#include "../../libs/libft/include/libft.h"
#include "../../libs/libft/include/get_next_line.h"

int get_arr_len(char **arr)
{
    int i;

    i = 0;
    while(arr[i])
        i++;
    printf("arr len: %i\n", i);
    return (i); 
}

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

void show_arr(char **arr)
{
    int i = 0;
    printf("\nshow array \n");
    while(arr[i] != NULL)
    {
        printf("i: %i  >%s<\n", i, arr[i]);
        i++;
    }
    printf("--- End ---\n\n");
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

char **J_load_file(char *file)
{
    int fd;
    char **tmp;
    int line_count;
    int i;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\nfile loading\n");
        // exit
    }
    line_count = get_line_count(file);
    //printf("nach linecount fd: %i    linecount: %i\n",fd, line_count);

    if (line_count < 8)
    {
        printf("Error\nnot enought information in map\n");
    }
    tmp =(char **)malloc((line_count + 1) * sizeof(char *));
    i = 0;
    //char *test;
    while(i < line_count)
    {
        //printf("fd: %i\n", fd);
        tmp[i] = get_next_line(fd);
        //printf("line: %i  >%s<\n", i, tmp[i]);
        if (tmp[i] == NULL)
            break;
        i++;
    }
    tmp[i] = NULL;
    show_arr(tmp);
    replace_char_in_arr(tmp, '\n', '\0');
    show_arr(tmp);
    
    close(fd);
    return (tmp);
}
///////////////////////////////////
//int find_str_in_str()

// returns the line NR
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

// return the path of of the find argument, size is the array size i.e. 2 if ("NO ./texure")
char *get_text_path(char **arr, char *find)
{
    printf("\nget_text_path of: %s\n", find);
    /*
    1. Split ' ' 
    2. wenn array len != 2 ist --> Error
    3. wenn array len == 2 ist und in arr[0] nicht das gesuchte Element ist --> Error
    4. wenn arr[0] pfad keine Datei ist   ... vielleicht besser später machen */

    char **split;
    char *ret;
    int fd;
    int line;
    
    if (arr == NULL || find == NULL)
        return (NULL);

    line = get_line_of(arr, find);
    split = ft_split(arr[line], ' ');
    show_arr(split);

    //checks if size is ok
    if (get_arr_len(split) != 2)
    {
        printf("Error\nelement has more then 2 information in the line\n");
        //todo free split
        return (NULL);
    }
    //checks if elemtent name is ok
    if (ft_strncmp(find, split[0], get_max_of_strlen(find, split[0])) != 0)
    {
        printf("Error\nelement is not in the right order or has more characters\n");
        //todo free split
        return (NULL);
    }
    // checks the file of the element
    fd = open(split[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error\ntexture file: %s is not valid\n", split[1]);
        //todo free split
        return (NULL);
    }
    close(fd);

    // copy file to output
    ret = ft_strdup(split[1]);
    printf("ret: >%s<\n", ret);

    // freeing split TODO
    return (ret);
}

enum e_tex
{
    NO,
    EA,
    SO,
    WE
};

char *tex_names[5] = {"NO","EA","SO","WE", NULL};

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
typedef struct s_color
{
    int r;
    int g;
    int b;
    int a;
}   t_color;

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

void show_color(t_color color)
{
    printf("show color\n");
    printf(" R: %i\n", color.r);
    printf(" G: %i\n", color.g);
    printf(" B: %i\n", color.b);
    printf(" A: %i\n\n", color.a);
}

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

int main(int argc, char **argv)
{   
    printf("huhu\n");
    char **splitted_file = J_load_file(argv[1]);

    char *tex_paths[5];
    int i = -1;
    while(i++, i < 4)
        tex_paths[i] = get_text_path(splitted_file, tex_names[i]);

    tex_paths[i] = NULL;
    show_arr(tex_paths);
    
    printf(" > check arr: %i\n", check_if_arr_entrys_valid(tex_paths, 4));

    t_color f_color = get_color_from_str(splitted_file, 'F');
    show_color(f_color);
    if (!check_color(f_color))
        printf("Error\ninvalid color\n");

    return(0);
}


/*
cc -D BUFFER_SIZE=1 loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
cc -D BUFFER_SIZE=1 loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
*/ 