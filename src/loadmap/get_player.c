/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:32:38 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/09 15:55:36 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// return i.e. 90 if c == E
int	get_player_view(char c)
{
	if (c == 'N')
		return (0);
	if (c == 'E')
		return (90);
	if (c == 'S')
		return (180);
	if (c == 'W')
		return (270);
	return (-1);
}

/*returns a player_pos struct. player is one of "NESW" 
... doesn´t checkt if player exists; but view will be -1 if no player*/
t_play_pos	find_player_and_get_pos(char **arr, char player)
{
	t_play_pos	ret_pos;
	int			row;
	int			row_count;
	int			col;

	row_count = get_arr_len(arr);
	row = 0;
	while (row < row_count)
	{
		col = get_pos_of_char(arr[row], player);
		if (col > -1)
		{
			ret_pos.view = get_player_view(player);
			ret_pos.x = col;
			ret_pos.y = row;
		}
		row++;
	}
	return (ret_pos);
}

// returns 0 if player pos is not valid
int	check_player(t_play_pos *player)
{
	if (player->x == -1 || player->y == -1 || player->view == -1)
		return (printf("Error\nno player or player position not valid\n"), 0);
	return (1);
}

// analize the int array. array has 4 rows ("NESW")
char	get_player_c(int *player_count)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0 && player_count[i] > 0)
			return ('N');
		if (i == 1 && player_count[i] > 0)
			return ('E');
		if (i == 2 && player_count[i] > 0)
			return ('S');
		if (i == 3 && player_count[i] > 0)
			return ('W');
		i++;
	}
	return (' ');
}

t_play_pos	get_player(char **arr)
{
	t_play_pos	pos;
	int			nesw[4];
	int			i;
	char		*chr;

	chr = "NESW";
	i = -1;
	while (i++, i < 4)
		nesw[i] = count_char_in_arr(arr, chr[i]);
	if (nesw[0] > 1 || nesw[1] > 1 || nesw[2] > 1 || nesw[3] > 1)
		return ((t_play_pos){-1, -1, -1});
	if (nesw[0] + nesw[1] + nesw[2] + nesw[3] > 1)
		return ((t_play_pos){-1, -1, -1});
	if (nesw[0] + nesw[1] + nesw[2] + nesw[3] == 0)
		return ((t_play_pos){-1, -1, -1});
	pos = find_player_and_get_pos(arr, get_player_c(nesw));
	return (pos);
}
