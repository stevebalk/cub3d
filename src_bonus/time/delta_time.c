/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:00:26 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/27 21:52:08 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double get_time_seconds()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

void	calculate_delta_time(t_cub *cub)
{
	cub->current_frame_time = get_time_seconds();
	cub->delta_time = cub->current_frame_time - cub->last_frame_time;
	cub->last_frame_time = cub->current_frame_time;
}
