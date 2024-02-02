/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:57 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/02 14:23:45 by jopeters         ###   ########.fr       */
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
	if (!splitted_file)
		return (0);
	if (count_char_in_arr(splitted_file, '\t'))
		return(printf("Error!\nnot allowed tab in file\n"), ft_free_array((void **)splitted_file), 0);
	if (!get_text_paths_master(s_map->textures, splitted_file))
		return(printf("Error!\ntexture path is not valid\n"), ft_free_array((void **)splitted_file), 0);
	get_color_master(s_map, splitted_file);
    if (!check_color(s_map->F))
		return(printf("Error!\ninvalid floor color\n"), ft_free_array((void **)splitted_file), 0);
	if (!check_color(s_map->C))
		return(printf("Error!\ninvalid ceil color\n"), ft_free_array((void **)splitted_file), 0);
	//printf("---------------\n");
	if (!get_map(s_map, splitted_file))
		return(printf("Error!\nmap is not valid\n"), ft_free_array((void **)splitted_file), 0);
	if (!check_after_map(s_map, splitted_file))
		return(printf("Error!\ncontent after map lines\n"), ft_free_array((void **)splitted_file), 0);
	if (!check_for_bad_lines(splitted_file))
		return(printf("Error!\nline with non game related content\n"), ft_free_array((void **)splitted_file), 0);
	
	ft_free_array((void **)splitted_file);
	return (1);
}

void ini_map(t_map *s_map)
{
	int i;

	i = 0;
	s_map->textures = (char **)malloc(sizeof(char *) * 5);
	while (i < 5)
	{
		s_map->textures[i] = NULL;
		i++;
	}
	s_map->map = NULL;
	//s_map->tex_names = ini_tex_names();
}

// return 1 if file ending is ok
int check_file_ending(char *file, char *ending)
{
	int len_file;
	int len_ending;
	
	len_file = ft_strlen(file);
	len_ending = ft_strlen(ending);
	file += len_file-len_ending;
	
	if (ft_strncmp(file, ending, len_file) == 0)
		return (1);
	else	
		return (printf("Error!\nfile ending NOT ok\n"), 0);
}

int load_and_check(t_map *s_map, int argc, char **argv)
{
	ini_map(s_map);

	if (argc != 2)
		return (printf("Error!\nwrong amout of arguments ... only 1 map.cub argument is allowed\n"), 0);
	if (!check_file_ending(argv[1], ".cub"))
		return (0);
		
	if (!load_map(s_map, argv))
		return (0);
	//sleep(1);
	s_map->player_start_pos = get_player(s_map->map);
	if (!check_player(&(s_map->player_start_pos)))
		return (0);
	//sleep(1);
	if (!check_map_valid(s_map))
		return (0);
	//sleep(1);
	if (!check_map(s_map))
		return (0);
	//sleep(1);

	return (1);
}

int main(int argc, char **argv)
{   
	t_map map;

	int check_res;
	check_res = load_and_check(&map, argc, argv);
	if (check_res)
		printf("run GAME \n");

	free_s_map(&map);
	c_green();
	printf("-- programm END --\n\n");
	
    return(check_res);
}


/*
cc -D BUFFER_SIZE=1 loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub
cc loadmap.c ../../libs/libft/libft.a && ./a.out map1.cub

leaks -atExit -- ./a.out map1.cub
*/ 