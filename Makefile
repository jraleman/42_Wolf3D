# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:56:04 by jaleman           #+#    #+#              #
#    Updated: 2017/02/21 15:56:05 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME       = wolf3d

# Compiling flags
FLAGS      = -Wall -Wextra -Werror -g -Ofast

# Folders
SRC_DIR    = ./srcs/
OBJ_DIR    = ./obj/
INC_DIR    = ./includes/
LIBFT_DIR  = ./libft/
MINLBX_DIR = ./minilibx/

# Source files and object files
SRC_FILES  = w3d_main.c w3d_raycast.c w3d_set_hooks.c w3d_set_movement.c \
				w3d_set_collision.c w3d_set_map.c w3d_set_hud.c \
				w3d_set_weapons.c w3d_set_debug.c
OBJ_FILES  = $(SRC_FILES:.c=.o)

# Paths
SRC        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT      = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX     = $(addprefix $(MINLBX_DIR), libmlx.a)

# Libft and Minilibx linkers
LNK        = -L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
				-Ofast -lmlx -framework OpenGL -framework AppKit

# all rule
all: obj $(LIBFT) $(MINLBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(LIBFT_DIR)/includes -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBX):
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generated!"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINLBX_DIR) clean
	@echo "¯\_(ツ)_/¯ Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) removed!"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
