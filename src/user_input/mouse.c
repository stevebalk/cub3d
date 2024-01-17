/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:37 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/17 15:57:36 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_press(int button, int x, int y, t_cub *cub)
{
	(void)cub;
	printf("button: %d\n", button);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	return (0);
}

int	mouse_release(int button, int x, int y, t_cub *cub)
{
	(void)cub;
	printf("button: %d\n", button);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	return (0);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	(void)cub;
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	return (0);
}
