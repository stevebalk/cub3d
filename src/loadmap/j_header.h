/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:29 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/26 12:05:52 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_HEADER_H
# define J_HEADER_H
#include "j_structs.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

#include "../../libs/libft/include/libft.h"
#include "../../libs/libft/include/get_next_line.h"


// get_colors
int check_color(t_color color);
t_color get_color_from_str(char **arr, char find);

// get_map
int get_map(t_map *s_map, char **arr);

// get_textures
char *get_text_path(char **arr, char *find);
int get_text_paths_master(char **tex_paths, char **splitted_file);

// show
void show_arr(char **arr);
void show_color(t_color color);
void show_s_map(t_map *s_map);

// util 
int get_arr_len(char **arr);
int get_line_count(char *file);
int get_line_of(char **arr, char *find, int rev);
int get_max_of_strlen(char *s1, char *s2);
int check_if_arr_entrys_valid(char **arr, int arr_len);
int count_char_in_str(char *str, char c);
int	count_char_in_arr(char **arr, char c);
t_color get_color(int r, int g, int b, int a);
void replace_char_in_arr(char **arr, char find, char replace);
int check_char_in_chars(char c, char *charset);
int check_line_for_chars(char *line, char *charset);
int get_max_line(char **arr, int start, int end);

// get_player
t_player_pos check_and_get_player(char **arr);


// mem
void	free_s_map(t_map *s_map);
void	free_n_null(void **ptr);
void	free_n_null_2D(void ***ptr);

// colors
void	c_red(void);
void	c_green(void);
void	c_blue(void);
void	c_purple(void);
void	c_yellow(void);
void	c_cyan(void);
void	clear_screen(void);
void	c_reset(void);


#endif