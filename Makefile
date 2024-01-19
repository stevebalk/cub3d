# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 11:18:26 by sbalk             #+#    #+#              #
#    Updated: 2024/01/19 11:34:08 by sbalk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
LIB_DIR		= libs/libft/
LIB_NAME	= libft.a
MLX_DIR		= libs/minilibx-linux/
MLX_NAME	= libmlx.a
CC			= cc
CFLAGS		= -Werror -Wall -Wextra -g
# CFLAGS		= -Werror -Wall -Wextra -fsanitize=address -g
RM			= rm
SRC_DIR		= src/
OBJ_DIR		= obj/
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
				init/mlx \
				init/player \
				init/map \
				draw/draw \
				draw/line \
				draw/basic_shapes \
				draw/map \
				player/getters \
				player/setters \
				player/rotation \
				player/movement \
				error/error \
				user_input/handler \
				user_input/keyboard \
				user_input/mouse \
				vector_utils/convert \
				vector_utils/vec2 \
				vector_utils/vec2i \


SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_DIRS		=	$(addprefix $(OBJ_DIR), $(SRC_FILES))

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIB_DIR)
			@make -C $(MLX_DIR)
#			Linux
			@$(CC) $(CFLAGS) $(OBJ) -L $(LIB_DIR) -lft -L $(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
#			MacOS
#			@$(CC) $(CFLAGS) $(OBJ) -L $(LIB_DIR) -lft minilibx-linux/libmlx.a minilibx-linux/libmlx_Darwin.a -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lm -o $(NAME)
			@echo "$(GREEN)Created $(NAME)!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIRS)
#			@mkdir -p $(OBJ_DIR)/user_input
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIB_DIR)
			@make clean -C $(MLX_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) -f $(NAME)
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

norm:
			@norminette $(SRC) include/$(NAME).h| grep -v Norme -B1 || true

git:		fclean
			@git status
			@git add *
			@git status

.PHONY:		all clean fclean re norm git
