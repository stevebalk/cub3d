#include "j_header.h"

int main(int argc, char **argv)
{   
	t_map map;
	#ifdef BONUS
		printf(" --- Check BONUS ---\n");
	#else
		printf(" --- Check ---\n");
	#endif

	int check_res;
	check_res = load_and_check(&map, argc, argv);
	if (check_res)
		printf("run GAME \n");
	free_s_map(&map);
	c_green();
	printf("-- programm END --\n\n");
	c_reset();
	if (check_res == 0)
		check_res++;
	if (check_res == 1)
		check_res--;
    return(check_res);
}