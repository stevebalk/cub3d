
typedef struct s_map_lines
{
	int start;
	int end;
}	t_map_lines;

typedef enum e_tex
{
    NO,
    EA,
    SO,
    WE
} t_tex;

typedef struct s_color
{
    int r;
    int g;
    int b;
    int a;
}   t_color;

typedef struct s_map
{
	t_color	F;
	t_color	C;

	t_tex	e_texures;
	char	*textures[5];

	char	**map;
}	t_map;