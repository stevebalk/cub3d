#include "j_header.h"

// inizialize tex short names
char **ini_tex_names(void)
{
	char **ret;
	c_purple(); printf("ini_tex_names\n"); c_reset();
	ret = (char **)malloc((sizeof(char *) * (5)));
	ret[0] = ft_strdup("NO");
	ret[1] = ft_strdup("EA");
	ret[2] = ft_strdup("SO");
	ret[3] = ft_strdup("WE");
	ret[4] = NULL;
	c_purple(); printf("after ini_tex_names\n"); c_reset();
	show_arr(ret);
	return (ret);
}

// set all vars to -1
void ini_player_pos(t_map *s_map)
{
	s_map->player_start_pos.view = -1;
	s_map->player_start_pos.x = -1;
	s_map->player_start_pos.y = -1;
}