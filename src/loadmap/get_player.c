/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:32:38 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/26 12:09:15 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

t_player_pos get_pos(int x, int y, int view)
{
	t_player_pos pos;
	pos.x = x;
	pos.y = y;
	pos.view = view;
	return (pos);
}

t_player_pos check_and_get_player(char **arr)
{
	//t_player_pos pos;
	int nesw[4];
	int i;
	char *chr;
	chr = "NESW";

	i = -1;
	while(i++, i < 4)
		nesw[i] = count_char_in_arr(arr, chr[i]);

	c_yellow(); printf("check_only_one_player \n");
	c_blue();
	printf("N: %i\nE: %i\nS: %i\nW: %i\n\n", nesw[0], nesw[1], nesw[2], nesw[3]);
	c_reset();
	
	if (nesw[0] > 1 ||  nesw[1] > 1 || nesw[2] > 1 ||  nesw[3] > 1)
		return (get_pos(-1,-1,-1));
	if (nesw[0] == 1 && nesw[1] && 1 || nesw[2] & 1 || nesw[3] && 1)
		return (get_pos(-1,-1,-1));

	return (get_pos(-1,-1,-1));
}

// t_player_pos get_player_pos(char **arr)
// {
// 	int line;
// 	line = get_line_of(arr, "")
// }
