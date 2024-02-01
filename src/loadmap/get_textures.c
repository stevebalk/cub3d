/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:43 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/01 14:52:43 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

//static char *tex_names[5] = {"NO","EA","SO","WE", NULL};

int check_path(char *path)
{
	int res;
	int fd;

    // checks the file of the element
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
		// c_red();
        // printf("Error\ntexture file: %s is not valid\n", path);
		// c_reset();
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
    //c_yellow(); printf("\nget_text_path of: %s\n", find); c_reset();
    /*
    1. Split ' ' 
    2. wenn array len != 2 ist --> Error
    3. wenn array len == 2 ist und in arr[0] nicht das gesuchte Element ist --> Error
    4. wenn arr[0] pfad keine Datei ist   ... vielleicht besser später machen */

    char **split;
    char *ret;
    int fd;
    int line;

	ret = NULL;
    
    if (arr == NULL || find == NULL)
		return (ret = ft_strdup(""), ret);
	// if get_line_of   reverse and not reverse are the same line, than there is only 1 occurence --> good
	if (get_line_of(arr, find, 0) == -1)
		return (ret = ft_strdup(""), ret);
	if (get_line_of(arr, find, 0) == get_line_of(arr, find, 1))
    	line = get_line_of(arr, find, 0);
	else
		return (ret = ft_strdup(""), ret);
	
	if (arr[line])
    	split = ft_split(arr[line], ' ');
	else
		return (ret = ft_strdup(""), ret);
		
	// c_red();
    // show_arr(split);
	// c_reset();

    //checks if size is ok
    if (get_arr_len(split) != 2)
    {
        printf("Error\nelement has more then 2 information in the line\n");
		ft_free_array((void **)split);
        ret = ft_strdup("");
		return (ret);
    }
    //checks if elemtent name is ok
    if (ft_strncmp(find, split[0], get_max_of_strlen(find, split[0])) != 0)
    {
        printf("Error\nelement is not in the right order or has more characters\n");
		ft_free_array((void **)split);
		ret = ft_strdup("");
		return (ret);
	}

	show_arr(split);

    // copy file to output if path is valid
	//if (split[1] != NULL)
	{
		if (check_path(split[1]))
		{
			ret = ft_strdup(split[1]);
			printf("ret >%s<\n", ret);
			ft_free_array((void **)split);
			//printf("after free \n");
			return (ret);
		}
		else 
		{
			ft_free_array((void **)split);
			ret = ft_strdup("");
			return (ret);
		}
	}
	ret = ft_strdup("");
	return (ret);
}

// fills a array of texture paths
int get_text_paths_master(char **tex_paths, char **splitted_file)
{
 	//char *tmp_tex_paths[5];
    // int i = -1;
    // while(i++, i < 4)
	// {
    //     tex_paths[i] = get_text_path(splitted_file, tex_names[i]);
	// 	//printf("i: %i  \n", i);
	// }
	tex_paths[0] = get_text_path(splitted_file, "NO");
	tex_paths[1] = get_text_path(splitted_file, "EA");
	tex_paths[2] = get_text_path(splitted_file, "SO");
	tex_paths[3] = get_text_path(splitted_file, "WE");

    tex_paths[4] = NULL;
    //show_arr(tex_paths);
    
    //printf(" > check arr: %i\n", check_if_arr_entrys_valid(tex_paths, 4));
	return(check_if_arr_entrys_valid(tex_paths, 4));
}
