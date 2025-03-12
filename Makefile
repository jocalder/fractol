# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 20:01:28 by jocalder          #+#    #+#              #
#    Updated: 2025/03/12 17:55:01 by jocalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = fractol

SRCS            = main.c initialize.c free.c fractol_utils.c keys_mouse.c render_fractal.c color.c \
					parse_args.c math_fractals.c

OBJS            = $(SRCS:.c=.o)

LIBFT_DIR      	= ./libft

LIBFT			= $(LIBFT_DIR)/libft.a

PRINTF_DIR		=./printf

PRINTF			= $(PRINTF_DIR)/libftprintf.a

MLX_DIR			= ./minilibx

MLX				= $(MLX_DIR)/libmlx.a

CC              = cc

FLAGS           = -Wall -Wextra -Werror

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@echo "\033[32mCompiling libft...\033[0m"
	@make -C $(LIBFT_DIR) > /dev/null

$(PRINTF):
	@echo "\033[35mCompiling printf...\033[0m"
	@make -C $(PRINTF_DIR) > /dev/null

$(MLX):
	@echo "\033[36mCompiling minilibx...\033[0m"
	@make -C $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	@echo "\033[34mCompiling fractol...\033[0m"
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME) -lm -lXext -lX11

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "\033[33mCleaning libraries...\033[0m"
	rm -f $(OBJS) 
	@make -C $(LIBFT_DIR) > /dev/null clean
	@make -C $(PRINTF_DIR) > /dev/null clean
	@make -C $(MLX_DIR) > /dev/null clean

fclean: clean
	@echo "\033[31mCleaning executable and libraries...\033[0m"
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) > /dev/null fclean
	@make -C $(PRINTF_DIR) > /dev/null fclean
	@make -C $(MLX_DIR) > /dev/null clean

re: fclean all

.PHONY: all clean fclean re
