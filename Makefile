# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 11:13:01 by ttavares          #+#    #+#              #
#    Updated: 2023/03/28 12:37:21 by ttavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

MINILIBX = ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = ./minilibx-linux

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCSOLONG =	so_long.c

NAME = so_long

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) $(SRCSOLONG) $(MINILIBX) -lXext -lX11 $(LIBFT) -o $(NAME)

bonus:

clean:
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean $(NAME)

.PHONY:	all clean fclean re bonus
