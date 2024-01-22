#include "j_header.h"

int check_path(char *path)
{
	int res;
	int fd;

    // checks the file of the element
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
		c_red();
        printf("Error\ntexture file: %s is not valid\n", path);
		c_reset();
        res = 0;
    }
	else
		res = 1;
    close(fd);
	return (res);
}


// return the path of of the find argument, size is the array size i.e. 2 if ("NO ./texure")
char *get_text_path(char **arr, char *find)
{
    c_yellow(); printf("\nget_text_path of: %s\n", find); c_reset();
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
	// if get_line_of   reverse and not reverse are the same line, than there is only 1 occurence --> good
	if (get_line_of(arr, find, 0) == get_line_of(arr, find, 1))
    	line = get_line_of(arr, find, 0);
	else
	{
		c_red();
		printf("Error!\nhere are 2 lines with >%s< \n", find); c_reset();
		return (NULL);
	}
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
		c_red();
        printf("Error\nelement is not in the right order or has more characters\n");
		c_reset();
        //todo free split
        return (NULL);
    }

	
    // // checks the file of the element
    // fd = open(split[1], O_RDONLY);
    // if (fd == -1)
    // {
	// 	c_red();
    //     printf("Error\ntexture file: %s is not valid\n", split[1]);
	// 	c_reset();
    //     //todo free split
    //     return (NULL);
    // }
    // close(fd);

    // copy file to output
	if (check_path(split[1]))
	{
		ret = ft_strdup(split[1]);
		printf("ret: >%s<\n", ret);
		return (ret);
	}
	else 
		return (NULL);

    // freeing split TODO
}
