#include "j_header.h"

/*
Flood simulation.

1) copy map
2) setting startpoint to 'f'
3) Check near fields
	a) 4 Check functions   up, right, down, left	
	b) if true --> write 'F' in array
		if 0 --> nothing
		if ' ' --> -1 ---> ERROR!



*/

int check_map(t_map *s_map)
{
	char **f_map;

	f_map = copy_arr(s_map->map);
	c_yellow();
	printf("check_map --> after copy map\n");
	show_map(f_map);


	return (1);
}