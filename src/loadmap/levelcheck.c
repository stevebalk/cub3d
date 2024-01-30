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
	if (x == 0 || x == col_len  || y == 0 || y == arr_len - 1)
	{
		if (arr[y][x] != '1')
			return (printf("Error!\nspace in map or no wall\n"), 0);
	}
	if (arr[y][x] == '0')
	{
		if (x == 0 || x == col_len - 1)
			return (printf("ERROR!\nspace in map or no wall\n"), 0);
		if (y == 0 || y == arr_len - 1)
			return (printf("ERROR!\nspace in map or no wall\n"), 0);

		replace_char_at_pos(arr, y, x, 'F');
		usleep(5000);
		clear_screen();
		show_map(arr);
	}
	else if (arr[y][x] == ' ')	
		return (printf("Error!\nspace in map or no wall\n"), 0);

	return (1);
}

// checks if the pos is valid
int check_down(char **arr, int x, int y)
{
	int arr_len;

	arr_len = get_arr_len(arr);
	if (y + 1 >= arr_len)
		return (0);
	if (x >= ft_strlen(arr[y + 1]))
		return (0);
	else
	{
		if(!check_field(arr, x, y + 1))
			return (0);
	}
	return (1);
}

// checks if the pos is valid
int check_up(char **arr, int x, int y)
{
	int arr_len;

	arr_len = get_arr_len(arr);
	if (y - 1 < 0)
		return (0);
	if (x >= ft_strlen(arr[y - 1]))
		return (0);
	else
	{
		if(!check_field(arr, x, y - 1))
			return (0);
	}
	return (1);
}

// checks if the pos is valid
int check_right(char **arr, int x, int y)
{
	if (x + 1 >= ft_strlen(arr[y]))
		return (0);
	else
	{
		if(!check_field(arr, x + 1, y))
			return (0);
	}
	return (1);
}

// checks if the pos is valid
int check_left(char **arr, int x, int y)
{
	if (x - 1 < 0)
		return (0);
	else
	{
		if(!check_field(arr, x - 1, y))
			return (0);
	}
	return (1);
}


// checks all reachable fields of the acutal position and fills with F if possible
int check_near_fields(char **arr, int x, int y)
{
	if (!check_up(arr, x, y))
		return (0);
	if (!check_right(arr, x, y))
		return (0);
	if (!check_down(arr, x, y))
		return (0);
	if (!check_left(arr, x, y))
		return (0);
	return (1);
}


int flood(char **arr)
{
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
			if (arr[r][c] == 'F')
			{
				if (!check_near_fields(arr, c, r))
				{
					printf("prob check_new_field\n");
					sleep(3);
					return (0);
				}
			}
			c++;
		}
		r++;
	}

	return (1);
}

int  set_and_fill_first_f(char **arr)
{
	t_xy tmp_pos;
	int ret;

	ret = 1;
	set_first_f(arr);
	tmp_pos = get_pos_of_char_in_arr(arr, 'F');
	ret = check_near_fields(arr, tmp_pos.x, tmp_pos.y);

	return (ret);
}

int check_map(t_map *s_map)
{
	char **f_map;
	int ret;
	int i;
	int len;

	f_map = copy_arr(s_map->map);
	ret = set_and_fill_first_f(f_map);

	len = get_arr_len(f_map) * get_max_line(f_map, 0, get_arr_len(f_map));
	i = -1;
	while (i++ < len)
	{
		if (!flood(f_map))
		{
			ret = 0;
			break;
		}
	}
	free_n_null_2D((void ***)f_map);
	return (ret);
}