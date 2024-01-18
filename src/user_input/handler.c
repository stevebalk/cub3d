/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:00:25 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/18 17:03:51 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_handler(t_cub *cub)
{
	if (cub->key.w)
		move_forward(cub);
	if (cub->key.s)
		move_backward(cub);
	if (cub->key.a)
		move_left(cub);
	if (cub->key.d)
		move_right(cub);
}

void	input_handler(t_cub *cub)
{
	key_handler(cub);
}
