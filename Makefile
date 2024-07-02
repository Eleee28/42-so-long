# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:16:19 by elena             #+#    #+#              #
#    Updated: 2024/07/02 08:18:41 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################### COLORS ####################################
DEFAULT	= \033[0m
GREEN	= \033[92m
YELLOW	= \033[93m
MAGENTA	= \033[95m
CYAN	= \033[96m
################################## VARIABLES ###################################

# Mandatory executable
NAME	= so_long

# Library directory
LIB_DIR	= library

# Objects directory
BIN_DIR	= bin

# Temporary file for traking compilation
TMP			= $(BIN_DIR)/.tmp

################################################################################

OS = $(shell uname -s)

ifeq ($(OS), Linux)
	MLX_DIR = mlx_linux
	MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

ifeq ($(OS), Darwin)
	MLX_DIR = mlx
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

################################################################################

# Compilation variables
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra

# Remove flags
REMOVE	:= rm -rf

# Make flags
MAKEFLAGS	+= -s

INCLUDE = -Ilibrary

################################################################################

# Possible source files path
VPATH = srcs

# Library file
LIB = $(LIB_DIR)/libft.a

# Mlx file
MLX = $(MLX_DIR)/libmlx.a

# Source files
SRCS =	main.c 				\
\
		error.c 			\
\
		map.c				\
		map_utils.c			\
		map_utils2.c		\
\
		game.c				\
		game_utils.c		\
\
		mlx_info.c			\
\
		position.c			\
		player.c			\
		enemies.c 			\
\
		print_game.c 		\
		print_game_utils.c 	\
\
		sprites.c 			\
		sprites2.c 			\
		print_sprites.c

# Object files
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

################################################################################

# Main rule
all:	$(NAME) msg
		@echo " "

# So long compilation
$(NAME): $(LIB) $(MLX) $(OBJS)
	@rm -rf $(TMP)
	@echo
	@$(CC) $(OBJS) $(LIB) $(MLX_FLAGS) $(INCLUDE) -o $(NAME)

# Objects compilation
$(BIN_DIR)/%.o: %.c
	@mkdir -p $(BIN_DIR)
	@if [ ! -e $(TMP) ]; then \
		touch $(TMP); \
		echo "$(MAGENTA)🔶 MAKE PROGRAM 🔶$(DEFAULT)\n"; \
	fi
	@echo -n "\033[2K\r🔍 $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	

# Library compilation
$(LIB): 
	@echo
	@echo "$(MAGENTA)🔶 MAKE LIBS 🔶$(DEFAULT)"
	@echo
	@make -C $(LIB_DIR)

# Mlx compilation
$(MLX):
#@echo
	@echo "$(MAGENTA)🔶 MAKE MLX 🔶$(DEFAULT)"
	@echo
#@echo "$(GREEN)Mlx lib...$(DEFAULT)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN)✨ MLX LIB!$(DEFAULT)"
	@echo
#@echo "$(GREEN)Library compiled!$(DEFAULT)"

################################################################################

bonus: all

################################################################################

aux_clean:
	@$(REMOVE) $(OBJS) $(BIN_DIR)
	@echo "$(CYAN)So long object files cleaned$(DEFAULT)"

clean: msg_clean
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	@make aux_clean
	@echo

fclean: msg_clean aux_clean
	@$(REMOVE) $(NAME)
	@echo "$(CYAN)So long executable files cleaned!$(DEFAULT)"
	@echo
	@make fclean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)

re: fclean
	@echo "$(GREEN)Cleaned everything for so long!$(DEFAULT)"
	@make all

################################################################################

msg:
	@echo
	@echo "$(GREEN)✨ SO LONG!$(DEFAULT)"

msg_clean:
	@echo
	@echo "$(MAGENTA)🔶 CLEAN 🔶$(DEFAULT)"
	@echo

################################################################################

play: 
	./$(NAME) files/small_map.ber
	./$(NAME) files/big_map.ber
	./$(NAME) files/collec_after_exit.ber
	./$(NAME) files/with_enemies.ber

################################################################################
.PHONY: all bonus aux_clean clean fclean re msg msg_clean play