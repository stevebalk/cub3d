/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:36:57 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/30 11:10:37 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <time.h>

# define FOV_RAD 1.0471975512
# define FOV_HALF 30
# define FOV_HALF_RAD 0.52359877559

# define MINIMAP_SCALE 0.2

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define SPRITE_WIDTH 64
# define SPRITE_HEIGHT 64

# define WALL 1
# define SPRITE 2
# define ITEM 3
# define PLAYER 4

# define TRUE 1
# define FALSE 0

# define ERROR -1
# define SUCCESS 0

# define SPRITE_SCALE 0.5

// typedef struct s_sprite_cast
// {
// 	double		x;
// 	double		y;
// 	double		distance;
// 	double		angle;
// 	double		height;
// 	double		width;
// 	double		top;
// 	double		left;
// 	double		offset_x;
// 	double		offset_y;
// }				t_sprite_cast;


/********************************************************************/
/*                           CONFIG                                 */
/********************************************************************/

/******************* GENERAL **********************/

#define WIN_TITLE "Cub3D_Bonus"
#define WIN_WIDTH 2560
#define WIN_HEIGHT 1440
// #define WIN_WIDTH 640
// #define WIN_HEIGHT 480

/******************* PLAYER **********************/

#define MOUSE_SENSITIVITY 0.075
#define FOV 66
#define MOVE_SPEED 4
#define ROT_SPEED 2
// #define COLLISION_MARGIN 0.001

/******************* MINIMAP **********************/

// Size of minimap in percent (Calculated with windowsize.y)
#define MINIMAP_SIZE_PERCENT 25
// How many tiles are shown in every direction
#define MINIMAP_VISIBLE_TILES 10
#define MINIMAP_MARGIN_X_PERCENT 1
#define MINIMAP_MARGIN_Y_PERCENT 1
#define MINIMAP_COLOR_BLOCKED 0x00000000
#define MINIMAP_COLOR_FREE 0x00222222
#define MINIMAP_COLOR_PLAYER 0x00FFFF00
#define MINIMAP_COLOR_DIR_VEC 0x00FFFFFF


/******************* DEBUG **********************/

#define DEBUG_OVERLAY 1

/******************* RAYCAST **********************/

#define MAX_RAY_LENGTH 100

/******************* SPRITES **********************/

#define SPRITE_TRANSPARENCY 0x00980088

/********************************************************************/
/*                          CONST DEFINES                           */
/********************************************************************/

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3
#define PI 3.14159265359
#define TWO_PI 6.28318530718
#define TILE_SIZE 16 // FOR MINIMAP
#define MAP_WIDTH 24 // DELETE LATER
#define MAP_HEIGHT 24 // DELETE LATER
#define TEST_MAP_SIZE_X 24 // DELETE LATER
#define TEST_MAP_SIZE_Y 24 // DELETE LATER



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
	t_vec2			move_dir;
	t_vec2			plane;
	double			time;
	double			old_time;
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

typedef struct s_fps
{
	int		frames;
	int		fps;
	time_t	start_time;
	time_t	current_time;
	double	delta_time;
}				t_fps;

typedef struct s_minimap
{
	t_vec2i		pos;
	int			size;
	t_vec2i		global_size_end;
	int			tile_size;
	int			visible_tiles;
	int			color_blocked;
	int			color_free;
	int			color_player;
}				t_minimap;

typedef struct s_sprite
{
	int			id;
	t_vec2		pos;
	double		x;
	double		y;
	int			is_static;
	int			orientation;
	double		distance;
	int			animatable;
	int			frame_offset_x;
	int			frame_index;
	int			frame_width;
	double		frame_time;
	int			frame_count;
	double		frame_duration;
}				t_sprite;

typedef struct s_sprite_calc
{
	t_vec2		transform;
	t_vec2		dir;
	t_vec2i		size;
	t_vec2i		screen_pos;
	t_vec2i		draw_start;
	t_vec2i		draw_end;
	t_vec2i		tex;
	t_vec2i		tex_size;
	int			stripe;
	int			sprite_screen_x;
	int			color;
}				t_sprite_calc;

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
	t_minimap		minimap;
	char			*wall_texture_paths[4];
	t_texture		wall_textures[4];
	t_fps			fps;
	int				ceilling_color;
	int				floor_color;
	double			z_buffer[WIN_WIDTH];
	t_sprite		*sprites;
	t_sprite_calc	sc;
	int 			sprite_count;
	char			*sprite_paths[4];
	t_texture		sprite_textures[4];
	t_ray			ray;
	int				frames;
	double			last_frame_time;
	double			current_frame_time;
	double			delta_time;
	unsigned int	flags;
}					t_cub;

/********************************************************************/
/*                          FLAGS                                   */
/********************************************************************/

#define FLAG_MOUSE_CONTROL 1
#define FLAG_DEBUG_OVERLAY 2

void	toggle_flag(unsigned int *flags, unsigned int bit_mask);
void	set_flag(unsigned int *flags, unsigned int bit_mask);
void	unset_flag(unsigned int *flags, unsigned int bit_mask);
int		is_flag_set(unsigned int flags, unsigned int bit_mask);

/********************************************************************/
/*                          INIT                                    */
/********************************************************************/

void	init_cub(t_cub *cub);
void	init_map(t_cub *cub);
void	init_mlx_window(t_cub *cub);
void	init_mlx_image(t_cub *cub, t_data **img, t_vec2i size);
void	init_mlx(t_cub *cub);
void	init_minimap(t_cub *cub);
void	init_sprites(t_cub *cub);
void	init_textures(t_cub *cub);
int		read_xpm(t_cub *cub, t_texture *texture, char *path);

/********************************************************************/
/*                          DRAWING                                 */
/********************************************************************/

void	put_pixel(t_data *img, t_vec2i pos, int color);
void	draw_line(t_data *img, t_vec2i start, t_vec2i end, int color);
void	draw_square(t_data *img, t_vec2i pos, int size, int color);
void	draw_rectangle(t_data *img, t_vec2i pos, t_vec2i size, int color);
void	draw_circle(t_data *img, t_vec2i pos, int radius, int color);
void	draw_triangle(t_data *img, t_vec2i pos, int size, int color);
// void	draw_minimap(t_cub *cub, t_vec2i position);
void	draw_minimap(t_cub *cub);
void	draw_background(t_data *data, t_vec2i size, int color);
void	draw_ceilling(t_cub *cub);
void	draw_floor(t_cub *cub);

/* Debug overlay */
void	draw_debug_overlay(t_cub *cub, t_vec2i pos);

/********************************************************************/
/*                          DRAWING                                 */
/********************************************************************/

void	draw_sprites(t_cub *cub);

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

/* Collision */

int		is_colliding(t_cub *cub, t_vec2 position);

/* SETTERS */

void	set_player_pos(t_player *player, t_vec2 pos);
void	set_player_dir(t_player *player, t_vec2 dir);
void	set_player_plane(t_player *player, t_vec2 plane);
void	set_player_time(t_player *player, double time);
void	set_player_old_time(t_player *player, double old_time);
void	set_player(t_player *player, t_vec2 pos, t_vec2 dir, t_vec2 plane);
void	set_player_time_old_time(t_player *player, double time, double old_time);

/* GETTERS */

t_vec2	get_player_pos(t_player *player);
t_vec2	get_player_dir(t_player *player);
t_vec2	get_player_plane(t_player *player);
double	get_player_time(t_player *player);
double	get_player_old_time(t_player *player);

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
t_vec2	mult_vec2(t_vec2 a, t_vec2 b);
t_vec2	div_vec2(t_vec2 a, t_vec2 b);
t_vec2	mod_vec2(t_vec2 a, t_vec2 b);
t_vec2	scale_vec2(t_vec2 a, double scale);
t_vec2	get_target_vec2(t_vec2 from, t_vec2 to);

/* VECTOR 2 INTEGER */

t_vec2i	add_vec2i(t_vec2i a, t_vec2i b);
t_vec2i	sub_vec2i(t_vec2i a, t_vec2i b);
t_vec2i	mult_vec2i(t_vec2i a, t_vec2i b);
t_vec2i	div_vec2i(t_vec2i a, t_vec2i b);
t_vec2i	mod_vec2i(t_vec2i a, t_vec2i b);
t_vec2i	scale_vec2i(t_vec2i a, int scale);
t_vec2i	get_target_vec2i(t_vec2i from, t_vec2i to);

/* CONVERT */

t_vec2	v2i_to_v2(t_vec2i vec);
t_vec2i	v2_to_v2i(t_vec2 vec);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);

/********************************************************************/
/*                          TIME                                    */
/********************************************************************/

double	get_time_seconds();
void	calculate_delta_time(t_cub *cub);

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