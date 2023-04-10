# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 19:49:40 by ttavares          #+#    #+#              #
#    Updated: 2023/04/10 19:58:34 by ttavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

MINILIBX = ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = ./minilibx-linux

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCSOLONG =	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
			./srcs/main.c ./srcs/readmap.c ./srcs/errors.c ./srcs/check_map.c\
			./srcs/readmap_utils.c ./srcs/moves.c ./srcs/drawmap.c ./srcs/check_path.c \
			./srcs/flood_fill.c ./srcs/check_map_extra.c ./srcs/moves_extra.c ./srcs/moves_validation.c

NAME = so_long

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) -g $(SRCSOLONG) $(MINILIBX) -lXext -lX11 $(LIBFT) -o $(NAME)

bonus:

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean $(NAME)
