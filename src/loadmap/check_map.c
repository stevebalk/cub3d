#include "j_header.h"

int check_map_valid(t_map *s_map)
{
	if (!check_player(&s_map->player_start_pos))
	{
		c_red();
		printf("Error!\nno player or start position\n");
		c_reset();
		return (0);
	}



	return (1);
}