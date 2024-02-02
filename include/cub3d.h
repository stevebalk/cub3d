/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:10:12 by sbalk             #+#    #+#             */
/*   Updated: 2024/02/02 12:07:11 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "j_header.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>

/********************************************************************/
/*                           CONFIG                                 */
/********************************************************************/

/******************* GENERAL **********************/

#define WIN_TITLE "Cub3D"
//#define WIN_WIDTH 640 * 3
//#define WIN_HEIGHT 480 * 3
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

/******************* PLAYER **********************/

#define MOUSE_SENSITIVITY 0.05
#define FOV 66
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.015

/******************* DEBUG **********************/

#define DEBUG_OVERLAY 1

/******************* RAYCAST **********************/

#define MAX_RAY_LENGTH 100


/********************************************************************/
/*                          CONST DEFINES                           */
/********************************************************************/

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define PI 3.14159265359
#define TWO_PI 6.28318530718

/********************************************************************/
/*                          OWN STRUCTS                             */
/********************************************************************/

/* For line calculation */
typedef struct s_line
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	err2;
}				t_line;

/* Vector 2 floating point */
typedef struct s_vec2
{
	double	x;
	double	y;
}				t_vec2;

/* Vector 2 only integers */
typedef struct s_vec2i
{
	int	x;
	int	y;
}				t_vec2i;

/* Image data for the mlx lib*/
typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	t_vec2i		win_size;
	int			endian;
}				t_data;

typedef struct s_player
{
	t_vec2			pos;
	t_vec2			dir;
	int				start_direction;
	t_vec2			velocity;
	t_vec2			plane;
	double			time;
	double			old_time;
	int				turn_direction;
	int				walk_direction;
	double			rotation_angle;
	double			walk_speed;
	double			turn_speed;
}					t_player;

typedef struct s_mouse
{
	int				x;
	int				y;
}					t_mouse;

typedef struct s_key
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_key;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct ray
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2i		map_check;
	t_vec2		step_size;
	t_vec2i		step;
	t_vec2		length;
	t_vec2i		tex;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		perp_wall_dist;
	double		wall_x;
	int			was_hit_vertical;
	int			hit_direction;
	int			wall_hit_content;
}				t_ray;


/* cub3D main struct, data that 
is used everywhere */
typedef struct s_cub
{
	void			*mlx;
	void			*win;
	t_data			*img;
	int				**map;
	t_vec2i			win_size;
	t_vec2i			map_size;
	t_vec2i			win_center;
	t_player		player;
	t_mouse			mouse;
	t_key			key;
	t_texture		wall_textures[4];
	char			*wall_texture_paths[4];
	int				ceilling_color;
	int				floor_color;
	t_ray			ray;
	int				frames;
	int				fps;
	time_t			start_time;
	time_t			current_time;
	double			delta_time;
	unsigned int	flags;
}					t_cub;

/********************************************************************/
/*                          FLAGS                                   */
/********************************************************************/

#define FLAG_MOUSE_CONTROL 1

void	toggle_flag(unsigned int *flags, unsigned int bit_mask);
void	set_flag(unsigned int *flags, unsigned int bit_mask);
void	unset_flag(unsigned int *flags, unsigned int bit_mask);
int		is_flag_set(unsigned int flags, unsigned int bit_mask);

/********************************************************************/
/*                          INIT                                    */
/********************************************************************/

void	init_mlx_window(t_cub *cub);
void	init_mlx_image(t_cub *cub, t_data **img, t_vec2i size);
void	init_mlx(t_cub *cub);
void	init_textures(t_cub *cub);
void	init_map(t_cub *cub);
void	init_cub(t_cub *cub, t_map *map);

/********************************************************************/
/*                          DRAWING                                 */
/********************************************************************/

void	put_pixel(t_data *img, t_vec2i pos, int color);
void	draw_ceilling(t_cub *cub);
void	draw_floor(t_cub *cub);

/********************************************************************/
/*                          PLAYER                                  */
/********************************************************************/

/* INIT */

void	init_player(t_cub *cub);

/* TRANSFORMATION, ROTATION */

void	move_forward(t_cub *cub);
void	move_backward(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);
void	rotate_player(t_cub *cub, double angle);
void	move(t_cub *cub);

/********************************************************************/
/*                          INPUT HANDLING                          */
/********************************************************************/

/* Init */

void	init_mlx_hooks(t_cub *cub);
void	init_mouse(t_cub *cub);

/* Handler */

void	input_handler(t_cub *cub);

/* Keyboard */

int		key_press(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);

/* Mouse */

int		mouse_press(int button, int x, int y, t_cub *cub);
int		mouse_release(int button, int x, int y, t_cub *cub);
int		mouse_move(int x, int y, t_cub *cub);
void	move_mouse_to_center(t_cub *cub);
t_vec2i	get_relative_mouse_pos(t_cub *cub);

/* Window */

int		close_window(t_cub *cub);

/********************************************************************/
/*                          Textures                                */
/********************************************************************/

int		get_pixel_color_int(t_texture *texture, int x, int y);

/********************************************************************/
/*                          Raycasting                              */
/********************************************************************/

void	calculate_step_size(t_ray *ray);
void	calculate_ray_length(t_ray *ray);
void	calculate_ray_dir(t_ray *ray, t_cub *cub, int i);
void	calculate_perpendicular_wall_dist(t_ray *ray);
void	calculate_line_height(t_ray *ray, t_cub *cub);
void	calculate_wall_x(t_ray *ray);
void	calculate_texture_x(t_ray *ray, t_cub *cub);
int		get_compass_hit_direction(t_ray *ray);
int		is_ray_hitting(t_cub *cub, t_ray *ray);
void	draw_pixel_from_texture(t_ray *ray, t_cub *cub, int i, int j);
void	draw_line_from_texture(t_ray *ray, t_cub *cub, int i);
void	raycast(t_cub *cub);

/********************************************************************/
/*                          CHECKS                                  */
/********************************************************************/

int		is_cell_occopied(t_cub *cub, t_vec2i pos);
int		is_inside_map(t_cub *cub, t_vec2i position);

/********************************************************************/
/*                          MATH                                    */
/********************************************************************/

/* VECTOR 2 DOUBLE */

t_vec2	add_vec2(t_vec2 a, t_vec2 b);
t_vec2	sub_vec2(t_vec2 a, t_vec2 b);
t_vec2	scale_vec2(t_vec2 a, double scale);

/* VECTOR 2 INTEGER */

t_vec2i	add_vec2i(t_vec2i a, t_vec2i b);
t_vec2i	sub_vec2i(t_vec2i a, t_vec2i b);
t_vec2i	scale_vec2i(t_vec2i a, int scale);

/* CONVERT */

t_vec2	v2i_to_v2(t_vec2i vec);
t_vec2i	v2_to_v2i(t_vec2 vec);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);

/********************************************************************/
/*                          MAP FILE HANDLING                       */
/********************************************************************/


int	**translate_char_to_int_map(t_cub *cub, char **map);

/********************************************************************/
/*                          ERROR                                   */
/********************************************************************/

void	error_msg(t_cub *cub, char *msg, int use_errno, int shall_exit);
void	exit_error(t_cub *cub, int use_errno, char *msg);

/********************************************************************/
/*                          FREEING/EXIT                            */
/********************************************************************/

void	free_everything(t_cub *cub);

#endif