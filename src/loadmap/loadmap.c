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
            printf("i: %i   j: %i \n", i, j);
            if (arr[i][j] == find)
            {
                arr[i][j] = replace;
                break;
            }
            if (arr[i][j] == '\0' || arr[i][j] == NULL)
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
    printf("nach linecount fd: %i    linecount: %i\n",fd, line_count);

    if (line_count < 8)
    {
        printf("Error\nnot enought information in map\n");
    }
    tmp =(char **)malloc((line_count + 1) * sizeof(char *));
    i = 0;
    char *test;
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

int get_line_of(char **arr, char *find)
{
    int line;
    int found;
    int i;

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

    line = get_line_of(arr, "NO");
    split = ft_split(arr[line], ' ');
    show_arr(split);

    //checks if size is ok
    if (get_arr_len(split) != 2)
        printf("Error\nelement has more then 2 information in the line\n");
    
    //checks if elemtent name is ok
    if (ft_strncmp(find, split[0], get_max_of_strlen(find, split[0])) != 0)
        printf("Error\nelement is not in the right order or has more characters\n");

    // checks the file of the element
    fd = open(split[1], O_RDONLY);
    if (fd == -1)
        printf("Error\ntexture file: %s is not valid\n", split[1]);
    close(fd);

    // copy file to output
    ret = ft_strdup(split[1]);
    printf("ret: >%s<\n", ret);

    // freeing split TODO
    return (ret);
}


int main(int argc, char **argv)
{   
    printf("huhu\n");
    char **splitted_file = J_load_file(argv[1]);
    printf("NO >%s<\n", get_text_path(splitted_file, "NO"));
    printf("EA >%s<\n", get_text_path(splitted_file, "EA"));
    printf("SO >%s<\n", get_text_path(splitted_file, "SO"));
    printf("WE >%s<\n", get_text_path(splitted_file, "WE"));

    /* TODO:
    get_text_path   gibt bei ERROR NULL zurück, das später gecheckt wird
    */

    return(0);
}

/*
cc -D BUFFER_SIZE=1 loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
*/ 