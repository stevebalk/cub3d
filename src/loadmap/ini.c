#include "j_header.h"

// inizialize tex short names
void ini_tex_names(char **dst)
{
	dst = (char **)malloc((sizeof(char *) * (5)));
	dst[0] = ft_strdup("NO");
	dst[1] = ft_strdup("EA");
	dst[2] = ft_strdup("SO");
	dst[3] = ft_strdup("WE");
	dst[4] = NULL;
}

// set all vars to -1
void ini_player_pos(t_map *s_map)
{
	s_map->player_start_pos.view = -1;
	s_map->player_start_pos.x = -1;
	s_map->player_start_pos.y = -1;
}