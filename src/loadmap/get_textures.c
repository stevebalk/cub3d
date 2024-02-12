/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:43 by jopeters          #+#    #+#             */
/*   Updated: 2024/02/12 11:13:03 by jopeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_header.h"

int	check_path(char *path)
{
	int	res;
	int	fd;

	fd = open (path, O_RDONLY);
	if (fd == -1)
		res = 0;
	else
	{
		res = 1;
		close(fd);
	}
	return (res);
}

int	tmp_get_line(char **arr, char *find)
{
	int	line;

	if (get_line_of(arr, find, 0) == get_line_of(arr, find, 1))
		line = get_line_of(arr, find, 0);
	else
		line = -1;
	return (line);
}

/* return the path of of the find argument, size is the
array size i.e. 2 if ("NO ./texure") */
char	*get_text_path(char **arr, char *find)
{
	char	**split;
	char	*ret;
	int		line;

	if (arr == NULL || find == NULL || get_line_of(arr, find, 0) == -1)
		return (ret = ft_strdup(""), ret);
	line = tmp_get_line(arr, find);
	if (line == -1)
		return (ret = ft_strdup(""), ret);
	if (arr[line])
		split = ft_split(arr[line], ' ');
	else
		return (ret = ft_strdup(""), ret);
	if (get_arr_len(split) != 2
		|| ft_strncmp(find, split[0], get_max_of_strlen(find, split[0])) != 0)
		return (ret = ft_strdup(""), ft_free_array((void **)split), ret);
	if (check_path(split[1]))
		return (ret = ft_strdup(split[1]), ft_free_array((void **)split), ret);
	else
		return (ret = ft_strdup(""), ft_free_array((void **)split), ret);
	ret = ft_strdup("");
	return (ret);
}

// fills a array of texture paths
int	get_text_paths_master(char **tex_paths, char **splitted_file)
{
	tex_paths[0] = get_text_path(splitted_file, "NO");
	tex_paths[1] = get_text_path(splitted_file, "EA");
	tex_paths[2] = get_text_path(splitted_file, "SO");
	tex_paths[3] = get_text_path(splitted_file, "WE");
	tex_paths[4] = NULL;
	return (check_if_arr_entrys_valid(tex_paths, 4));
}
