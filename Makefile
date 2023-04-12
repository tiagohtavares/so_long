# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 19:49:40 by ttavares          #+#    #+#              #
#    Updated: 2023/04/10 21:49:45 by ttavares         ###   ########.fr        #
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

SRCSOLONG_BONUS =	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
					./srcs/bonus/so_long_bonus.c ./srcs/bonus/readmap_bonus.c ./srcs/bonus/errors_bonus.c ./srcs/bonus/check_map_bonus.c\
					./srcs/bonus/readmap_utils_bonus.c ./srcs/bonus/moves_bonus.c ./srcs/bonus/drawmap_bonus.c ./srcs/bonus/check_path_bonus.c \
					./srcs/bonus/flood_fill_bonus.c ./srcs/bonus/check_map_extra_bonus.c ./srcs/bonus/moves_extra_bonus.c ./srcs/bonus/moves_validation_bonus.c \
					./srcs/bonus/animate_bonus.c

NAME = so_long

NAME_BONUS = so_long_bonus

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) -g $(SRCSOLONG) $(MINILIBX) -lXext -lX11 $(LIBFT) -o $(NAME)

$(NAME_BONUS):
	$(CC) -g $(SRCSOLONG_BONUS) $(MINILIBX) -lXext -lX11 $(LIBFT) -o $(NAME_BONUS)

bonus: $(NAME) $(NAME_BONUS)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re:	fclean all bonus
