/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:15:01 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/30 15:18:55 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

void free_s_map(t_map *s_map)
{
	if (s_map->textures)
		ft_free_2darray((void ***)&s_map->textures);
	//free(s_map->textures);
	if (s_map->map)
		ft_free_2darray((void ***)&s_map->map);

	if (s_map->tex_names)
	{
		//printf("free text names\n");
		//free_n_null_2D((void ***)s_map->tex_names);
		ft_free_2darray((void ***)&s_map->tex_names);
	}
}