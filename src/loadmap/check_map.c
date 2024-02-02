/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:05:59 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/02 14:08:39 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

int	check_map_valid(t_map *s_map)
{
	if (!check_player(&s_map->player_start_pos))
		return (printf("Error!\nno player or start position\n"), 0);
	return (1);
}
