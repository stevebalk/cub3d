/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:10:12 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/17 11:20:54 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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

# define SPRITE_SCALE 0.5

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_sprite
{
	double		x;
	double		y;
	double		distance;
}				t_sprite;

typedef struct s_sprite_cast
{
	double		x;
	double		y;
	double		distance;
	double		angle;
	double		height;
	double		width;
	double		top;
	double		left;
	double		offset_x;
	double		offset_y;
}				t_sprite_cast;

typedef struct s_ray
{
	double		angle;
	double		distance;
	double		wall_hit_x;
	double		wall_hit_y;
	int			was_hit_vertical;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
	int			wall_hit_content;
}				t_ray;

typedef struct s_player
{
	double		x;
	double		y;
	double		width;
	double		height;
	int			turn_direction;
	int			walk_direction;
	double		rotation_angle;
	double		walk_speed;
	double		turn_speed;
}				t_player;

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

typedef struct s_map
{
	int			rows;
	int			cols;
	int			tile_size;
	int			**grid;
}				t_map;

#endif
