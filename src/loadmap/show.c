/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:43 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/27 11:22:13 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

void show_arr(char **arr)
{
    int i = 0;
    printf("\nshow array \n");
    while(arr[i] != NULL)
    {
        printf("i: %i  >%s<\n", i, arr[i]);
        i++;
    }
    printf("--- End ---\n\n");
}

void show_color(t_color color)
{
    printf("show color\n");
    c_red();printf(" R: %i\n", color.r);
    c_green();printf(" G: %i\n", color.g);
    c_blue();printf(" B: %i\n", color.b); c_reset();
    printf(" A: %i\n\n", color.a);
}

void show_s_map(t_map *s_map)
{
	printf("--- show s_map ---\n");;
	
	printf("\ntexures: ");
	show_arr(s_map->textures);
	
	printf("\nColor F: \n");
	show_color(s_map->F);

	printf("\nColor C: \n");
	show_color(s_map->C);

	printf("\nmap:");
	show_arr(s_map->map);
}

void show_s_player(t_player_pos *s_player)
{
	printf("\n--- show_s_player ---\n");;
	printf("Player    X: %i\n", s_player->x);
	printf("Player    Y: %i\n", s_player->y);
	printf("Player View: %i\n\n", s_player->view);
}