#include "j_header.h"

char *tex_names[5] = {"NO","EA","SO","WE", NULL};

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