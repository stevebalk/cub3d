#include "j_header.h"

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
