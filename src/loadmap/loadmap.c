/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:57 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/30 14:45:10 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

char **load_map_file(char *file)
{
    int fd;
    char **tmp;
    int line_count;
    int i;

    fd = open(file, O_RDONLY);
    if (fd == -1)
		return (printf("Error\nfile loading\n"), NULL);
    line_count = get_line_count(file);

    if (line_count < 8)
		return (printf("Error\nnot enough information in map\n"), NULL);
    tmp =(char **)malloc((line_count + 1) * sizeof(char *));
    i = 0;
    while(i < line_count)
    {
        tmp[i] = get_next_line(fd);
        if (tmp[i] == NULL)
            break;
        i++;
    }
    tmp[i] = NULL;
    replace_char_in_arr(tmp, '\n', '\0');    
    close(fd);
    return (tmp);
}

int load_map(t_map *s_map, char **argv)
{
	char **splitted_file;
	splitted_file = load_map_file(argv[1]);
	if (!get_text_paths_master(s_map->textures, splitted_file, s_map->tex_names))
		return(printf("Error!\ntexture paths are not valid\n"), free_n_null_2D((void ***)splitted_file), 0);
    s_map->F = get_color_from_str(splitted_file, 'F');
	s_map->C = get_color_from_str(splitted_file, 'C');
    if (!check_color(s_map->F))
		return(printf("Error!\ninvalid floor color\n"), free_n_null_2D((void ***)splitted_file), 0);
	if (!check_color(s_map->C))
		return(printf("Error!\ninvalid ceil color\n"), free_n_null_2D((void ***)splitted_file), 0);
	if (!get_map(s_map, splitted_file))
		return(printf("Error!\nmap is not valid\n"), free_n_null_2D((void ***)splitted_file), 0);
	free_n_null_2D((void ***)splitted_file);
	return (1);
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
	s_map->tex_names = ini_tex_names();
}

// return 1 if file ending is ok
int check_file_ending(char *file, char *ending)
{
	c_yellow(); printf("check_file_ending   file >%s<    ending >%s< \n", file, ending);
	int len_file;
	int len_ending;
	
	len_file = ft_strlen(file);
	len_ending = ft_strlen(ending);
	file += len_file-len_ending;
	printf("file >%s<\n", file);
	
	if (ft_strncmp(file, ending, len_file) == 0)
	{
		c_green(); printf("file ending ok\n"); c_reset();
		return (1);
	}
	else	
	{
		c_red(); printf("Error!\nfile ending NOT ok\n"); c_reset();
		return (0);
	}
}

int load_and_check(t_map *s_map, int argc, char **argv)
{
	if (!check_file_ending(argv[1], ".cub"))
		return (0);
		
	ini_map(s_map);

	if (!load_map(s_map, argv))
		return (0);
		
	s_map->player_start_pos = get_player(s_map->map);
	
	if (!check_player(&(s_map->player_start_pos)))
		return (0);
	if (!check_map_valid(s_map))
		return (0);
	if (!check_map(s_map))
		return (0);

	return (1);
}

int main(int argc, char **argv)
{   
    printf("huhu\n");
	t_map map;

	load_and_check(&map, argc, argv);

	free_s_map(&map);
	c_green();
	printf("-- programm END --\n\n");
	
    return(0);
}


/*
cc -D BUFFER_SIZE=1 loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
cc loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub

leaks -atExit -- ./a.out map1.cub
*/ 