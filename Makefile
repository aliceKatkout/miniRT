# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:30:00 by avedrenn          #+#    #+#              #
#    Updated: 2023/08/07 16:38:43 by avedrenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= srcs/main.c

NAME= miniRT

LIBFT= /libft/libft.a

MLX= /mlx-linux/libmlx.a

OBJ= $(SRCS:.c=.o)

CC= gcc

HEADER = miniRT.h

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) libft/libft.a mlx-linux/libmlx.a
	${CC} -o $@ ${OBJ} -L ./libft -lft -L ./mlx-linux -lmlx -lXext -lX11 -lm -lbsd

%.o: %.c libft/libft.a mlx-linux/libmlx.a
	$(CC) $(CFLAGS) -o $@ -c $< -I $(LIBFT) -I $(MLX)

libft/libft.a:
	${MAKE} -C libft

mlx-linux/libmlx.a :
	${MAKE} -C mlx-linux

clean:
	rm -f $(OBJ)
	${MAKE} -C libft clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean

re: fclean all

.PHONY: re all fclean clean