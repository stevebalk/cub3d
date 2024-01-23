/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:57 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/23 15:24:13 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

static char *tex_names[5] = {"NO","EA","SO","WE", NULL};

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
    //show_arr(tmp);
    replace_char_in_arr(tmp, '\n', '\0');
    show_arr(tmp);
    
    close(fd);
    return (tmp);
}
///////////////////////////////////



int load_map(t_map *s_map, char **argv)
{
	int ret;
	
	ret = 1;
    char **splitted_file = J_load_file(argv[1]);
	
	if (!get_text_paths_master(s_map->textures, splitted_file))
	{
		ret = 0;
		c_red();
		printf("Error!\ntexture paths are not valid\n");
	}

    s_map->F = get_color_from_str(splitted_file, 'F');
	s_map->C = get_color_from_str(splitted_file, 'C');

    if (!check_color(s_map->F))
	{
		ret = 0;
		c_red();
		printf("Error\ninvalid floor color\n");
	}
	if (!check_color(s_map->C))
	{
		ret = 0;
		c_red();
       	printf("Error\ninvalid ceil color\n");
	}
	// show_color(s_map->F);
	// show_color(s_map->C);

	if (!get_map(s_map, splitted_file))
	{
		ret = 0;
		c_red();
		printf("Error!\nmap is not valid\n");
	}	
	free_n_null_2D((void ***)splitted_file);
	return (ret);
}

void ini_map(t_map *s_map)
{
	int i;

	i = 0;
	s_map->textures = (char **)malloc(sizeof(char *) *5);
	while(i <= 5)
	{
		s_map->textures[i] = NULL;
		i++;
	}
}

int main(int argc, char **argv)
{   
    printf("huhu\n");
	t_map map;
	ini_map(&map);
	if (load_map(&map, argv))
		printf("map loaded OK\n");
	else
		printf("map loading failed!\n");


	c_cyan(); printf("--- after load map ---\n"); c_reset();
	//show_arr(map.map);
	// show_arr(map.textures);
	// show_color(map.C);
	// show_color(map.F);

	free_s_map(&map);

	
    return(0);
}


/*
cc -D BUFFER_SIZE=1 loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
cc loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub

leaks -atExit -- ./a.out map1.cub
*/ 