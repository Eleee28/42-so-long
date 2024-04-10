# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:16:19 by elena             #+#    #+#              #
#    Updated: 2024/04/10 11:46:30 by ejuarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR CODES

DEFAULT = \033[0m

GREEN = \033[92m

RED = \033[91m

YELLOW = \033[93m

BLUE = \033[36m

MAGENTA = \033[95m

CYAN = \033[96m

GRAY = \033[90m

BOLD = \033[1m

# VARIABLES

NAME = so_long

SRC_DIR = srcs

LIBFT_DIR = library

OS = $(shell uname -s)

ifeq ($(OS), Linux)
	MLX_DIR = mlx_linux
	MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

ifeq ($(OS), Darwin)
	MLX_DIR = mlx
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif


CC = cc

CFLAGS += -Wall -Werror -Wextra -g3

REMOVE = rm -f

LIB = ar -crs

INCLUDE = -Ilibrary

# SOURCES

SRCS =	$(SRC_DIR)/main.c \
		\
		$(SRC_DIR)/error.c \
		\
		$(SRC_DIR)/map.c	\
		$(SRC_DIR)/map_utils.c	\
		$(SRC_DIR)/map_utils2.c	\
		\
		$(SRC_DIR)/game.c	\
		$(SRC_DIR)/game_utils.c	\
		\
		$(SRC_DIR)/mlx_info.c	\
		\
		$(SRC_DIR)/position.c	\
		$(SRC_DIR)/player.c	\
		$(SRC_DIR)/enemies.c \
		\
		$(SRC_DIR)/print_game.c \
		$(SRC_DIR)/print_game_utils.c \
		\
		$(SRC_DIR)/sprites.c \
		$(SRC_DIR)/sprites2.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

MLX = $(MLX_DIR)/libmlx.a

all:	$(NAME) msg
		@echo " "

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo " "
	@echo "$(MAGENTA)🔶 MAKE PROGRAM 🔶$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(INCLUDE) -o $(NAME)
	@echo " "
	@echo "👉 $(CYAN) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(INCLUDE) -o $(NAME) $(DEFAULT)"
	@echo " "

msg:
	@echo "$(GREEN)✨ SO LONG!$(DEFAULT)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "🔍 $(YELLOW)Compiling... $< $(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	@echo " "
	@echo "$(MAGENTA)🔶 MAKE LIBS 🔶$(DEFAULT)"
	@echo " "
	@echo "$(GREEN)Libft lib...$(DEFAULT)"
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo " "
	@make -sC $(LIBFT_DIR)
	@echo "$(GREEN)Library compiled!$(DEFAULT)"

$(MLX):
	@echo " "
	@echo "$(MAGENTA)🔶 MAKE MLX 🔶$(DEFAULT)"
	@echo " "
	@echo "$(GREEN)Mlx lib...$(DEFAULT)"
	@$(MAKE) -sC $(MLX_DIR)
	@echo " "
	@make -sC $(MLX_DIR)
	@echo "$(GREEN)Library compiled!$(DEFAULT)"

clean:
	@echo " "
	@echo "$(MAGENTA)🔶 CLEAN 🔶$(DEFAULT)"
	@echo " "
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	@echo "$(CYAN)Library object files cleaned$(DEFAULT)"
	@$(REMOVE) $(OBJS)
	@echo "$(CYAN)So long object files cleaned$(DEFAULT)"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "$(CYAN)So long executable files cleaned!$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)Library executable files cleaned!$(DEFAULT)"
	
re: fclean
	@echo " "
	@echo "$(GREEN)Cleaned everything for so long!$(DEFAULT)"
	@$(MAKE) all

play: 
	./$(NAME) files/small_map.ber
	./$(NAME) files/big_map.ber
	./$(NAME) files/collec_after_exit.ber
	./$(NAME) files/with_enemies.ber
	

.PHONY: all clean fclean re