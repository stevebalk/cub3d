all: 
	cc  levelcheck.c ini.c get_player.c check_map.c loadmap.c mem.c colors_a.c colors_b.c get_colors.c get_map.c get_textures.c show.c utils.c ../../libs/libft/libft.a -g
san:
	echo "san"
	cc  levelcheck.c ini.c get_player.c check_map.c loadmap.c mem.c colors_a.c colors_b.c get_colors.c get_map.c get_textures.c show.c utils.c ../../libs/libft/libft.a -fsanitize=address


#	cc  levelcheck.c ini.c get_player.c check_map.c loadmap.c mem.c colors_a.c colors_b.c get_colors.c get_map.c get_textures.c show.c utils.c ../../libs/libft/libft.a  -fsanitize=address
# -fsanitize=address -g

.PHONY: san all