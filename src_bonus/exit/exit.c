/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:52:59 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/28 13:46:01 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	close_window(t_cub *cub)
{
	mlx_do_key_autorepeaton(cub->mlx);
	free_everything(cub);
	exit(0);
	return (0);
}
