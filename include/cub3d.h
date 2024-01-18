/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:10:12 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 11:08:30 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

# define PI 3.14159265359
# define TWO_PI 6.28318530718

# define FOV 60
# define FOV_RAD 1.0471975512
# define FOV_HALF 30
# define FOV_HALF_RAD 0.52359877559

# define TILE_SIZE 64
# define TILE_SIZE_HALF 32

# define MINIMAP_SCALE 0.2

# define MOVE_SPEED 10
# define ROT_SPEED 0.1

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

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define SPRITE_SCALE 0.5

// typedef struct s_sprite
// {
// 	double		x;
// 	double		y;
// 	double		distance;
// }				t_sprite;

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

// typedef struct s_ray
// {
// 	double		angle;
// 	double		distance;
// 	double		wall_hit_x;
// 	double		wall_hit_y;
// 	int			was_hit_vertical;
// 	int			is_ray_facing_up;
// 	int			is_ray_facing_down;
// 	int			is_ray_facing_left;
// 	int			is_ray_facing_right;
// 	int			wall_hit_content;
// }				t_ray;

// typedef struct s_player
// {
// 	double		x;
// 	double		y;
// 	double		width;
// 	double		height;
// 	int			turn_direction;
// 	int			walk_direction;
// 	double		rotation_angle;
// 	double		walk_speed;
// 	double		turn_speed;
// }				t_player;

// typedef struct s_texture
// {
// 	void		*img;
// 	char		*addr;
// 	int			bpp;
// 	int			line_length;
// 	int			endian;
// 	int			width;
// 	int			height;
// }				t_texture;

// typedef struct s_map
// {
// 	int			rows;
// 	int			cols;
// 	int			tile_size;
// 	int			**grid;
// }				t_map;

/********************************************************************/
/*                          OWN DEFINES                             */
/********************************************************************/

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define WIN_WIDTH 640
#define WIN_HEIGHT 480

/********************************************************************/
/*                          OWN STRUCTS                             */
/********************************************************************/

/* For line calculation */ //DEBUG
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
	t_vec2			plane;
	double			time;
	double			old_time;
	int				turn_direction;
	int				walk_direction;
	double			rotation_angle;
	double			walk_speed;
	double			turn_speed;
}					t_player;

/* FdF main struct, data that 
is used everywhere */
typedef struct s_cub
{
	void			*mlx;
	void			*win;
	t_data			*img;
	t_vec2i			win_size;
	t_vec2i			map_size;
	t_vec2i			win_center;
	t_player		player;
}					t_cub;

/********************************************************************/
/*                          INIT                                    */
/********************************************************************/

void	init_mlx_window(t_cub *cub);
void	init_mlx_image(t_cub *cub, t_data **img, t_vec2i size);
void	init_mlx(t_cub *cub);
void	init_cub(t_cub *cub);

/********************************************************************/
/*                          DRAWING                                 */
/********************************************************************/

void	put_pixel(t_data *img, t_vec2i pos, int color);
void	draw_line(t_data *img, t_vec2i start, t_vec2i end, int color);
void	draw_square(t_data *img, t_vec2i pos, int size, int color);
void	draw_rectangle(t_data *img, t_vec2i pos, t_vec2i size, int color);
void	draw_circle(t_data *img, t_vec2i pos, int radius, int color);
void	draw_triangle(t_data *img, t_vec2i pos, int size, int color);

/********************************************************************/
/*                          PLAYER                                  */
/********************************************************************/

/* INIT */

void	init_player(t_player *player);

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

void	init_mlx_hooks(t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);
int		mouse_press(int button, int x, int y, t_cub *cub);
int		mouse_release(int button, int x, int y, t_cub *cub);
int		mouse_move(int x, int y, t_cub *cub);
int		close_window(t_cub *cub);

/********************************************************************/
/*                          ERROR                                   */
/********************************************************************/

void	error_msg(t_cub *cub, char *msg, int use_errno, int shall_exit);


#endif