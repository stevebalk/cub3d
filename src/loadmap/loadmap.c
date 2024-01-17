#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

#include "../../libs/libft/include/libft.h"
#include "../../libs/libft/include/get_next_line.h"

int get_line_count(int fd)
{
    int count = 0;
    char buf;
    int re = 1;

    while(re > 0)
    {
        re = read(fd, &buf, 1);
        if (buf == '\n')
            count++;
    }
    if (count > 0)
        count++;
    
    //printf("get line count: %i\n", count);
    return (count);
}

void show_arr(char **arr)
{
    int i = -1;
    printf("show array \n");
    while(arr[i++])
        printf("i: %i  >%s<\n", i, arr[i]);
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
    printf("fd: %i \n",fd);
    line_count = get_line_count(fd);
    if (line_count < 8)
    {
        printf("Error\nnot enought information in map\n");
    }
    tmp =(char **)malloc((line_count + 1) * sizeof(char *));
    i = 0;
    while(i < line_count)
    {
        printf("fd: %i\n");
        tmp[i] = get_next_line(fd);
        printf("line: %i  >%s<\n", i, tmp[i]);
        if (tmp[i] == NULL)
            break;
        i++;
    }
    show_arr(tmp);
    //tmp = get_next_line(fd);
    
    close(fd);
    return (NULL);
}



int main(int argc, char **argv)
{   
    printf("huhu\n");
    char **splitted_file = J_load_file(argv[1]);
    
    return(0);
}

/*
cc loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
*/ 