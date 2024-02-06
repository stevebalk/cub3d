LIB_DIR		= ../libs/libft/

all: 
	@make -C $(LIB_DIR)
	cc  ../src/loadmap/check_fields_a.c ../src/loadmap/check_fields_b.c ../src/loadmap/levelcheck.c ../src/loadmap/ini.c ../src/loadmap/get_player.c ../src/loadmap/check_map.c ../src/loadmap/loadmap.c ../src/loadmap/mem.c ../src/loadmap/colors_a.c ../src/loadmap/colors_b.c ../src/loadmap/get_colors.c ../src/loadmap/get_map.c ../src/loadmap/get_textures.c ../src/loadmap/show.c ../src/loadmap/utils_a.c ../src/loadmap/utils_b.c ../src/loadmap/utils_c.c ../src/loadmap/utils_d.c ../src/loadmap/utils_e.c ../libs/libft/libft.a -g -D TEST -D FLOOD -D BONUS
san:
	echo "san"
	@make -C $(LIB_DIR)
	cc  ../src/loadmap/check_fields_a.c ../src/loadmap/check_fields_b.c ../src/loadmap/levelcheck.c ../src/loadmap/ini.c ../src/loadmap/get_player.c ../src/loadmap/check_map.c ../src/loadmap/loadmap.c ../src/loadmap/mem.c ../src/loadmap/colors_a.c ../src/loadmap/colors_b.c ../src/loadmap/get_colors.c ../src/loadmap/get_map.c ../src/loadmap/get_textures.c ../src/loadmap/show.c ../src/loadmap/utils_a.c ../src/loadmap/utils_b.c ../src/loadmap/utils_c.c ../src/loadmap/utils_d.c ../src/loadmap/utils_e.c ../libs/libft/libft.a -fsanitize=address -D TEST -D FLOOD -D BONUS


#	cc  levelcheck.c ini.c get_player.c check_map.c loadmap.c mem.c colors_a.c colors_b.c get_colors.c get_map.c get_textures.c show.c utils.c ../../libs/libft/libft.a  -fsanitize=address
# -fsanitize=address -g

.PHONY: san all
