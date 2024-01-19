
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
void get_map(char **arr);

// get_textures
char *get_text_path(char **arr, char *find);

// show
void show_arr(char **arr);
void show_color(t_color color);

// util 
int get_arr_len(char **arr);
int get_line_count(char *file);
int get_line_of(char **arr, char *find);
int get_max_of_strlen(char *s1, char *s2);
int check_if_arr_entrys_valid(char **arr, int arr_len);
int count_char_in_str(char *str, char c);
t_color get_color(int r, int g, int b, int a);
void replace_char_in_arr(char **arr, char find, char replace);

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