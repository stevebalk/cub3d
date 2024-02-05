# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopeters <jopeters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:18:26 by sbalk             #+#    #+#              #
#    Updated: 2024/02/05 15:50:46 by jopeters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
NAME_BONUS	= cub3d_bonus
UNAME_S		:= $(shell uname -s)
LIB_DIR		= libs/libft/
LIB_NAME	= libft.a
MLX_DIR		= libs/minilibx-linux/
MLX_NAME	= libmlx.a
CC			= cc
RM			= rm
CFLAGS		= -Werror -Wall -Wextra -O3
# CFLAGS		= -Werror -Wall -Wextra -O3
# CFLAGS		= -Werror -Wall -Wextra -fsanitize=address -g
SRC_DIR		= src/
OBJ_DIR		= obj/
BSRC_DIR	= src_bonus/
BOBJ_DIR	= obj_bonus/

INCLUDE		:= -I include -I ${LIB_DIR}include -I $(MLX_DIR)
LIBS		:= -L $(LIB_DIR) -lft -L $(MLX_DIR) -lmlx 
ifeq ($(UNAME_S), Linux)
	LIBS		+= -L/usr/lib -lXext -lX11 -lm -lz
	INCLUDE		+= -I /opt/X11/include
else ifeq ($(UNAME_S), Darwin)
	LIBS		+= -L $(MLX_DIR) -lmlx_Darwin -L /usr/X11/lib -lX11 -lXext -lm
	INCLUDE		+= -I /usr/X11/include
else
	$(error "OS not supported")
endif

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	main \
				init/cub \
				init/mlx \
				init/player \
				init/textures \
				draw/draw \
				error/error \
				exit/exit \
				flags/flag_utils \
				map/checks \
				math/math \
				player/movement \
				player/rotation \
				raycasting/raycast \
				raycasting/ray_calculate_ray \
				raycasting/ray_calculate_texture \
				raycasting/ray_checks \
				raycasting/ray_draw \
				user_input/handler \
				user_input/keyboard \
				user_input/mouse \
				vector_utils/convert \
				vector_utils/vec2 \
				vector_utils/vec2i \
				loadmap/get_textures \
				loadmap/check_map \
				loadmap/colors_a \
				loadmap/colors_b \
				loadmap/mem \
				loadmap/levelcheck \
				loadmap/utils_e \
				loadmap/get_colors \
				loadmap/loadmap \
				loadmap/utils_a \
				loadmap/get_map \
				loadmap/utils_d \
				loadmap/translate_char_to_int_map \
				loadmap/get_player \
				loadmap/check_fields_b \
				loadmap/utils_c \
				loadmap/show \
				loadmap/ini \
				loadmap/check_fields_a \
				loadmap/utils_b \

BSRC_FILES	=	main \
				init/cub \
				init/map \
				init/mlx \
				init/init_minimap \
				init/player \
				init/textures \
				init/init_sprites \
				draw/basic_shapes \
				draw/debug/overlay \
				draw/draw \
				draw/line \
				draw/minimap \
				draw/sprites \
				error/error \
				exit/exit \
				flags/flag_utils \
				free/free \
				map/checks \
				math/math \
				player/checks \
				player/movement \
				player/rotation \
				raycasting/raycast \
				raycasting/ray_calculate_ray \
				raycasting/ray_calculate_texture \
				raycasting/ray_checks \
				raycasting/ray_draw \
				time/delta_time \
				user_input/handler \
				user_input/keyboard \
				user_input/mouse \
				vector_utils/convert \
				vector_utils/vec2 \
				vector_utils/vec2i \
				loadmap/get_textures \
				loadmap/check_map \
				loadmap/colors_a \
				loadmap/colors_b \
				loadmap/mem \
				loadmap/levelcheck \
				loadmap/utils_e \
				loadmap/get_colors \
				loadmap/loadmap \
				loadmap/utils_a \
				loadmap/get_map \
				loadmap/utils_d \
				loadmap/translate_char_to_int_map \
				loadmap/get_player \
				loadmap/check_fields_b \
				loadmap/utils_c \
				loadmap/show \
				loadmap/ini \
				loadmap/check_fields_a \
				loadmap/utils_b 

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_DIRS		=	$(addprefix $(OBJ_DIR), $(SRC_FILES))

BSRC			=	$(addprefix $(BSRC_DIR), $(addsuffix .c, $(BSRC_FILES)))
BOBJ			=	$(addprefix $(BOBJ_DIR), $(addsuffix .o, $(BSRC_FILES)))
BOBJ_DIRS		=	$(addprefix $(BOBJ_DIR), $(BSRC_FILES))

BONUS		= bonus

all:		$(NAME)

bonus:		$(BONUS)

$(NAME):	$(OBJ)
			@make -C $(LIB_DIR)
			@make -C $(MLX_DIR)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS) $(INCLUDE)
			@echo "$(GREEN)Created $(NAME)!$(DEF_COLOR)"

$(BONUS):	$(BOBJ)
			@make -C $(LIB_DIR)
			@make -C $(MLX_DIR)
			@$(CC) $(CFLAGS) $(BOBJ) -o $(NAME_BONUS) $(LIBS) $(INCLUDE) -D BONUS
			@echo "$(GREEN)Created $(NAME_BONUS)!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIRS)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BOBJ_DIR)%.o: $(BSRC_DIR)%.c
			@mkdir -p $(BOBJ_DIRS)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf $(BOBJ_DIR)
			@make clean -C $(LIB_DIR)
			@make clean -C $(MLX_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME_BONUS)
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

norm:
			@norminette $(SRC) include/$(NAME).h| grep -v Norme -B1 || true
			@norminette $(BSRC) include/$(NAME).h| grep -v Norme -B1 || true


.PHONY:		all clean fclean re norm bonus
