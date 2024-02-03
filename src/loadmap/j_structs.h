/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_structs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:35 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/03 16:02:01 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_STRUCTS_H
# define J_STRUCTS_H

typedef struct s_map_lines
{
	int	start;
	int	end;
}	t_map_lines;

typedef enum e_tex
{
	NO,
	EA,
	SO,
	WE
}	t_tex;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

// coordinates of the player; view in °   0° is norh  90° is east etc.
typedef struct s_player_pos
{
	int	x;
	int	y;
	int	view;
}	t_play_pos;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_map
{
	t_color			f;
	t_color			c;
	t_tex			e_texures;
	char			**textures;
	t_play_pos	player_start_pos;
	char			**map;
}	t_map;

#endif