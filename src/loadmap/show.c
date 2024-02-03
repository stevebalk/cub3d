/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:43 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/03 16:45:34 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

void	show_arr(char **arr)
{
	int	i;

	i = 0;
	printf("\nshow array \n");
	while (arr[i] != NULL)
	{
		printf("i: %i  >%s<\n", i, arr[i]);
		i++;
	}
	printf("--- End ---\n\n");
}

void	show_line(char *line)
{
	int	j;

	j = 0;
	while (j < ft_strlen(line))
	{
		if (line[j] == '0')
			c_cyan();
		if (line[j] == '1')
			c_yellow();
		if (line[j] == 'F')
			c_purple();
		if (line[j] == 'N' || line[j] == 'E'
			|| line[j] == 'S' || line[j] == 'W')
			c_green();
		printf("%c", line[j]);
		c_reset();
		j++;
	}
}

void	show_map(char **arr)
{
	int	i;

	i = 0;
	printf("\nshow map \n");
	c_reset();
	while (arr[i] != NULL)
	{
		printf("i: %3i   |", i);
		show_line(arr[i]);
		printf("|\n");
		i++;
	}
	printf("--- End ---\n\n");
	c_reset();
}

void	show_color(t_color color)
{
	printf("show color\n");
	c_red();
	printf(" R: %i\n", color.r);
	c_green();
	printf(" G: %i\n", color.g);
	c_blue();
	printf(" B: %i\n", color.b);
	c_reset();
	printf(" A: %i\n\n", color.a);
}

void	show_s_map(t_map *s_map)
{
	printf("--- show s_map ---\n");
	printf("\ntexures: ");
	show_arr(s_map->textures);
	printf("\nColor F: \n");
	show_color(s_map->f);
	printf("\nColor C: \n");
	show_color(s_map->c);
	printf("\nmap:");
	show_arr(s_map->map);
	printf("\nplayer pos:");
	printf("\n--- show_s_player ---\n");
	printf("Player    X: %i\n", s_map->player_start_pos.x);
	printf("Player    Y: %i\n", s_map->player_start_pos.y);
	printf("Player View: %i\n\n", s_map->player_start_pos.view);
}
