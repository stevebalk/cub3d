/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:15:01 by jopeters          #+#    #+#             */
/*   Updated: 2024/01/30 14:53:52 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

// emptys the pointer and set it to NULL
void	free_n_null(void **ptr)
{
	if (*ptr)
	{
		printf("free 1D    >%s<\n",  (char*)ptr);
		free(*ptr);
	}
	*ptr = NULL;
}

// emptys the pointer and set it to NULL
void	free_n_null_2D(void ***ptr)
{
	int i;

	i = 0;
	while(ptr[i] != NULL)
	{
		free(ptr[i]);
		ptr[i] = NULL;	
		i++;
	}
	
	// while(ptr[i] != NULL)
	// {
	// 	free_n_null(ptr[i]);
	// 	i++;
	// }

    // Free the array itself
    free(ptr);

    // Set the original pointer to NULL
    *ptr = NULL;
}

void free_s_map(t_map *s_map)
{
	if (s_map->textures)
		free_n_null_2D((void ***)s_map->textures);
	//free(s_map->textures);
	if (s_map->map)
		free_n_null_2D((void ***)s_map->map);

	if (s_map->tex_names)
	{
		//printf("free text names\n");
		free_n_null_2D((void ***)s_map->tex_names);
	}
}