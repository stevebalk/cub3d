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
	if (arr[y][x] == '0')
	{
		if (x == 0 || x == col_len - 1)
		{
			printf("ERROR!   x == 0 || x == col_len\n");
			sleep(2);
			exit(1);
		}
		if (y == 0 || y == arr_len - 1)
		{
			printf("ERROR!   (y == 0 || y == arr_len)\n");
			sleep(2);
			exit(1);
			
		}

		replace_char_at_pos(arr, y, x, 'F');
		usleep(5000);
		clear_screen();
		show_map(arr);
	}
	else if (arr[y][x] == ' ')
	{
		c_red();
		printf("Error!\nspace in map or no wall\n"); c_reset();
		exit(1);
		return (0);
	}
	else
	{

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
			check_field(arr, x, y - 1);
		}
	}


	// right
	if (x + 1 <= ft_strlen(arr[y]))
	{
		if (y >= 0)
		{
			//printf("right\n");
			check_field(arr, x + 1, y);
		}
	}

	// down
	if (y + 1 < arr_len )
	{
		if (x <= ft_strlen(arr[y + 1]))
		{
			//printf("down\n");
			check_field(arr, x, y + 1);
		}
	}

	// left
	if (x - 1 >= 0)
	{
		if (y >= 0)
		{
			//printf("left\n");
			check_field(arr, x - 1, y);
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
				check_near_fields(arr, c, r);

			c++;
		}

		r++;
	}

	return (1);
}

int check_map(t_map *s_map)
{
	char **f_map;

	f_map = copy_arr(s_map->map);
	c_yellow(); printf("check_map --> after copy map\n"); c_reset();
	set_first_f(f_map);
	show_map(f_map);

	int i = -1;
	int arr_len = get_arr_len(f_map);
	int max_col = get_max_line(f_map, 0, arr_len);
	while (i++ < (arr_len * max_col))
		flood(f_map);
		
	return (1);
}