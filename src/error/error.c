/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:08:47 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/23 17:00:23 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(t_cub *cub, char *msg, int use_errno, int shall_exit)
{
	free_everything(cub);
	ft_putendl_fd(msg, 2);
	if (shall_exit)
	{
		if (use_errno)
			exit(errno);
		exit(EXIT_FAILURE);
	}
}

void	exit_error(t_cub *cub, char *msg)
{
	error_msg(cub, msg, 0, 1);
}