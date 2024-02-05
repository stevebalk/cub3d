all: 
	cc  check_fields_a.c check_fields_b.c levelcheck.c ini.c get_player.c check_map.c loadmap.c mem.c colors_a.c colors_b.c get_colors.c get_map.c get_textures.c show.c utils_a.c utils_b.c utils_c.c utils_d.c utils_e.c ../../libs/libft/libft.a -g -D TEST -D FLOOD -D BONUS
san:
	echo "san"
	cc  check_fields_a.c check_fields_b.c levelcheck.c ini.c get_player.c check_map.c loadmap.c mem.c colors_a.c colors_b.c get_colors.c get_map.c get_textures.c show.c utils_a.c utils_b.c utils_c.c utils_d.c utils_e.c ../../libs/libft/libft.a -fsanitize=address -D TEST -D FLOOD -D BONUS


#	cc  levelcheck.c ini.c get_player.c check_map.c loadmap.c mem.c colors_a.c colors_b.c get_colors.c get_map.c get_textures.c show.c utils.c ../../libs/libft/libft.a  -fsanitize=address
# -fsanitize=address -g

.PHONY: san all