# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:18:26 by sbalk             #+#    #+#              #
#    Updated: 2024/01/26 15:02:18 by sbalk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
NAME_BONUS	= cub3d_bonus
LIB_DIR		= libs/libft/
LIB_NAME	= libft.a
MLX_DIR		= libs/minilibx-linux/
MLX_NAME	= libmlx.a
CC			= cc
# CFLAGS		= -Werror -Wall -Wextra -g
CFLAGS		= -Werror -Wall -Wextra -O3
# CFLAGS		= -Werror -Wall -Wextra -fsanitize=address -g
RM			= rm
SRC_DIR		= src/
OBJ_DIR		= obj/

BSRC_DIR	= src_bonus/
BOBJ_DIR	= obj_bonus/

INCLUDE		= -I include -I ${LIB_DIR}include -I $(MLX_DIR) -I/opt/X11/include

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
				init/map \
				init/mlx \
				init/player \
				init/textures \
				draw/basic_shapes \
				draw/debug/overlay \
				draw/draw \
				draw/line \
				draw/map \
				error/error \
				exit/exit \
				flags/flag_utils \
				map/checks \
				math/math \
				player/checks \
				player/getters \
				player/movement \
				player/setters \
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

BSRC_FILES	=	main \
				init/cub \
				init/map \
				init/mlx \
				init/init_minimap \
				init/player \
				init/textures \
				draw/basic_shapes \
				draw/debug/overlay \
				draw/draw \
				draw/line \
				draw/map \
				error/error \
				exit/exit \
				flags/flag_utils \
				map/checks \
				math/math \
				player/checks \
				player/getters \
				player/movement \
				player/setters \
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
#			Linux
			@$(CC) $(CFLAGS) $(OBJ) -L $(LIB_DIR) -lft -L $(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
#			MacOS
#			@$(CC) $(CFLAGS) $(OBJ) -L $(LIB_DIR) -lft minilibx-linux/libmlx.a minilibx-linux/libmlx_Darwin.a -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lm -o $(NAME)
			@echo "$(GREEN)Created $(NAME)!$(DEF_COLOR)"

$(BONUS):	$(BOBJ)
			@make -C $(LIB_DIR)
			@make -C $(MLX_DIR)
#			Linux
			@$(CC) $(CFLAGS) $(BOBJ) -L $(LIB_DIR) -lft -L $(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME_BONUS)
#			MacOS
#			@$(CC) $(CFLAGS) $(BOBJ) -L $(LIB_DIR) -lft minilibx-linux/libmlx.a minilibx-linux/libmlx_Darwin.a -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lm -o $(NAME)
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
