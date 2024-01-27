/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:57 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/27 11:41:52 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

//static char *tex_names[5] = {"NO","EA","SO","WE", NULL};

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
    //show_arr(tmp);
    
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
	s_map->map = NULL;
	
	ini_tex_names(s_map->tex_names);
}

int main(int argc, char **argv)
{   
    printf("huhu\n");
	t_map map;
	ini_map(&map);
	if (load_map(&map, argv))
	{
		c_green();
		printf("\n\n ===================\n"); 
		printf(" => map loaded OK  =\n"); 
		printf(" ===================\n\n"); c_reset();

		show_s_map(&map);

	}
	else
	{
		c_red();
		printf("==========================\n");
		printf("==> map loading failed!  =\n");
		printf("==========================\n\n");
		c_reset();

	}

	c_cyan(); printf("--- after load map ---\n"); c_reset();
	map.player_start_pos = check_and_get_player(map.map);
	if (!check_player(&map.player_start_pos))
	{
		c_red();
		printf("Error!\nno player or start position\n");
		c_reset();
	}

	free_s_map(&map);

	
    return(0);
}


/*
cc -D BUFFER_SIZE=1 loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
cc loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub

leaks -atExit -- ./a.out map1.cub
*/ 