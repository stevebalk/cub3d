/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:40:56 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 15:45:34 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	toggle_flag(unsigned int *flags, unsigned int bit_mask)
{
	*flags ^= bit_mask;
}

void	set_flag(unsigned int *flags, unsigned int bit_mask)
{
	*flags |= bit_mask;
}

void	unset_flag(unsigned int *flags, unsigned int bit_mask)
{
	*flags &= ~bit_mask;
}

int	is_flag_set(unsigned int flags, unsigned int bit_mask)
{
	return ((flags & bit_mask) != 0);
}
