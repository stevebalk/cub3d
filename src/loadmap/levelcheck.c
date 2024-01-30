#include "j_header.h"

/*
Flood simulation.

1) copy map   	✓
2) setting startpoint to 'f' 	✓
3) Check near fields			✓
	a) 4 Check functions   up, right, down, left	 ✓
	b) if true --> write 'F' in array   ✓
		if 0 --> nothing                
		if ' ' --> -1 ---> ERROR!

Check einbauen, dass alle mit wänden umzingelt ist.

*/

void set_first_f(char **arr)
{
	replace_char_in_arr(arr, 'N', 'F');
	replace_char_in_arr(arr, 'E', 'F');
	replace_char_in_arr(arr, 'S', 'F');
	replace_char_in_arr(arr, 'W', 'F');
}

int check_field(char **arr, int x, int y)
{
	int col_len;
	int arr_len;

	col_len = ft_strlen(arr[y]);
	arr_len = get_arr_len(arr);

    //printf("\ncheck field   col_len: %i   arr_len: %i \n", col_len, arr_len);
	//printf("check field         x: %i         y: %i \n", x, y);
	if (x == 0 || x == col_len  || y == 0 || y == arr_len - 1)
	{
		if (arr[y][x] != '1')
		{
			printf("Error!\nspace in map or no wall\n");
			return (0);
		}
	}


	if (arr[y][x] == '0')
	{
		if (x == 0 || x == col_len - 1)
		{
			printf("ERROR!\nspace in map or no wall\n");
			return (0);
		}
		if (y == 0 || y == arr_len - 1)
		{	
			printf("ERROR!\nspace in map or no wall\n");
			return (0);
		}

		replace_char_at_pos(arr, y, x, 'F');
		usleep(5000);
		clear_screen();
		show_map(arr);
	}
	else if (arr[y][x] == ' ')
	{
		printf("Error!\nspace in map or no wall\n");
		return (0);
	}
	else
	{
		// printf("else\n");
		// exit(1);
	}

	return (1);
}

// checks all reachable fields of the acutal position and fills with F if possible
int check_near_fields(char **arr, int x, int y)
{
	int arr_len;

	arr_len = get_arr_len(arr);
	//printf("check_near_fields  x: %i   y: %i \n", x, y);
	//printf("arr len: %i\n", arr_len);
	// UP
	if (y - 1 >= 0)
	{
		if (x <= ft_strlen(arr[y - 1]))
		{
			//printf("up\n");
			if(!check_field(arr, x, y - 1))
				return (0);
		}
	}


	// right
	if (x + 1 <= ft_strlen(arr[y]))
	{
		if (y >= 0)
		{
			//printf("right\n");
			if(!check_field(arr, x + 1, y))
				return (0);
		}
	}

	// down
	if (y + 1 < arr_len )
	{
		if (x <= ft_strlen(arr[y + 1]))
		{
			//printf("down\n");
			if(!check_field(arr, x, y + 1))
				return (0);
		}
	}

	// left
	if (x - 1 >= 0)
	{
		if (y >= 0)
		{
			//printf("left\n");
			if(!check_field(arr, x - 1, y))
				return (0);
		}
	}

	return (1);
}


int flood(char **arr)
{
	//c_yellow(); printf("flood\n"); c_reset();
	int c;
	int r;
	int row_count;
	int col_count;

	row_count = get_arr_len(arr);
	r = 0;
	while(r < row_count)
	{
		c = 0;
		col_count = ft_strlen(arr[r]);
		while(c < col_count)
		{
			//printf("r: %i   c: %i \n", r, c);
			if (arr[r][c] == 'F')
			{
				if (!check_near_fields(arr, c, r))
					return (0);
			}
			c++;
		}
		r++;
	}

	return (1);
}

int check_map(t_map *s_map)
{
	char **f_map;
	int ret;
	t_xy tmp_pos;

	f_map = copy_arr(s_map->map);
	c_yellow(); printf("check_map --> after copy map\n"); c_reset();
	set_first_f(f_map);


	show_map(f_map);
	tmp_pos = get_pos_of_char_in_arr(f_map, 'F');
	ret = check_near_fields(f_map, tmp_pos.x, tmp_pos.y);
	//printf("ret: %i\n", ret);
	int i = -1;
	int arr_len = get_arr_len(f_map);
	int max_col = get_max_line(f_map, 0, arr_len);
	while (i++ < (arr_len * max_col))
	{
		if (!flood(f_map))
		{
			sleep(5);
			ret = 0;
			break;
		}
	}
	free_n_null_2D((void ***)f_map);
	return (ret);
}