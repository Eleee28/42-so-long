# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:16:19 by elena             #+#    #+#              #
#    Updated: 2024/07/10 08:30:28 by ejuarros         ###   ########.fr        #
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

# Bonus executable
BONUS	= so_long_bonus

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

INCLUDE	= -Ilibrary

################################################################################

# Possible source files path
VPATH = srcs:srcs_bonus

# Library file
LIB = $(LIB_DIR)/libft.a

# Mlx file
MLX = $(MLX_DIR)/libmlx.a

# Source files
SRCS =	main.c 				\
		error.c 			\
		map.c				\
		map_utils.c			\
		map_utils2.c		\
		game.c				\
		game_utils.c		\
		mlx_info.c			\
		position.c			\
		player.c			\
		print_game.c 		\
		print_game_utils.c 	\
		sprites.c 			\
		sprites2.c 			\
		print_sprites.c

SRCS_BONUS = 	main_bonus.c 				\
				error_bonus.c 				\
				map_bonus.c					\
				map_utils_bonus.c			\
				map_utils2_bonus.c			\
				game_bonus.c				\
				game_utils_bonus.c			\
				mlx_info_bonus.c			\
				position_bonus.c			\
				player_bonus.c				\
				enemies_bonus.c 			\
				print_game_bonus.c 			\
				print_game_utils_bonus.c 	\
				sprites_bonus.c 			\
				sprites2_bonus.c 			\
				print_sprites_bonus.c

# Object files
OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(BIN_DIR)/%.o)

################################################################################

# Main rule
all:	$(NAME) msg
		@echo

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
	@echo "$(MAGENTA)🔶 MAKE MLX 🔶$(DEFAULT)"
	@echo
	@make -C $(MLX_DIR)
	@echo "$(GREEN)✨ MLX LIB!$(DEFAULT)"
	@echo

################################################################################

# Bonus compilation
bonus: $(BONUS) msg_bonus
	@echo

$(BONUS): $(LIB) $(MLX) $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIB) $(MLX_FLAGS) $(INCLUDE) -o $(BONUS)
	@echo

################################################################################

aux_clean:
	@$(REMOVE) $(OBJS) $(OBJS_BONUS) $(BIN_DIR)
	@echo "$(CYAN)So long object files cleaned$(DEFAULT)"

clean: msg_clean
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	@make aux_clean
	@echo

fclean: msg_clean aux_clean
	@$(REMOVE) $(NAME) $(BONUS)
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

msg_bonus:
	@echo
	@echo "$(GREEN)✨ SO LONG BONUS!$(DEFAULT)"

msg_clean:
	@echo
	@echo "$(MAGENTA)🔶 CLEAN 🔶$(DEFAULT)"
	@echo

################################################################################

play: all
	./$(NAME) maps/small_map.ber
	./$(NAME) maps/big_map.ber
	./$(NAME) maps/collec_after_exit.ber

play_bonus: bonus
	./$(BONUS) maps/small_map.ber
	./$(BONUS) maps/big_map.ber
	./$(BONUS) maps/collec_after_exit.ber
	./$(BONUS) maps/with_enemies.ber

################################################################################
.PHONY: all bonus aux_clean clean fclean re msg  msg_bonus msg_clean play