/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:29 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/05 16:05:15 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_HEADER_H
# define J_HEADER_H
# include "j_structs.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> 
# include "../libs/libft/include/libft.h"

# ifdef FLOOD
#  define SHOWFLOOD 1
# else
#  define SHOWFLOOD 0
# endif

int			load_and_check(t_map *s_map, int argc, char **argv);

// get_colors
int			check_color(t_color color);
t_color		get_color_from_str(char **arr, char find);
int			get_check_color_master(t_map *s_map, char **splitted_file);

// get_map
int			get_map(t_map *s_map, char **arr);
int			check_after_map(t_map *s_map, char **arr);
int			check_for_bad_lines(char **arr);
t_map_lines	get_map_lines(char **arr, char *charset, char *charset2);

// check_map
int			check_map_valid(t_map *s_map);
int			check_map_lines(char **arr, t_map_lines map_lines,
				char *charset, char *charset2);
int			check_after_map(t_map *s_map, char **arr);

// get_textures
char		*get_text_path(char **arr, char *find);
int			get_text_paths_master(char **tex_paths, char **splitted_file);

// check_fields
int			check_near_fields(char **arr, int x, int y);
int			check_field(char **arr, int x, int y);

// show
void		show_arr(char **arr);
void		show_color(t_color color);
void		show_s_map(t_map *s_map);
void		show_map(char **arr);

// util 
int			get_arr_len(char **arr);
int			get_line_count(char *file);
int			get_line_of(char **arr, char *find, int rev);
int			get_max_of_strlen(char *s1, char *s2);
int			check_if_arr_entrys_valid(char **arr, int arr_len);
int			count_char_in_str(char *str, char c);
int			count_char_in_arr(char **arr, char c);
t_color		get_color(int r, int g, int b, int a);
void		replace_char_in_arr(char **arr, char find, char replace);
int			check_char_in_chars(char c, char *charset);
int			check_line_for_chars(char *line, char *charset);
int			get_max_line(char **arr, int start, int end);
char		**copy_arr(char **src);
int			get_pos_of_char(char *line, char c);
int			get_spaces_from_beginning(char *line);
int			get_len_without_spaces_from_end(char *line);
void		replace_char_at_pos(char **arr, int row, int col, char c);
t_xy		get_xy_pos(int x, int y);
t_xy		get_pos_of_char_in_arr(char **arr, char c);
int			check_only_c_before_find(char *str, char c, char find);
int			check_line_for_only(char *str, char c);
int			check_line_for_str(char *line, char *str);
int			has_at_least_one_occurence_of_charset(char *line, char *charset);
int			check_arr_for_printable_chars(char **arr);

// ini
char		**ini_tex_names(void);
void		ini_player_pos(t_map *s_map);
void		ini_map(t_map *s_map);

// get_player
t_play_pos	get_player(char **arr);
int			check_player(t_play_pos *player);

// level check
int			check_map(t_map *s_map);

// mem
void		free_s_map(t_map *s_map);

// colors
void		c_red(void);
void		c_green(void);
void		c_blue(void);
void		c_purple(void);
void		c_yellow(void);
void		c_cyan(void);
void		clear_screen(void);
void		c_reset(void);

#endif