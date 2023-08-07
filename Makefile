# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:30:00 by avedrenn          #+#    #+#              #
#    Updated: 2023/08/07 17:11:11 by mrabourd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= srcs/

OBJ_DIR	= obj/

LIBFT	= /libft/libft.a

MLX		= /mlx-linux/libmlx.a

NAME	= miniRT

CC		= cc

HEADER	= miniRT.h

CFLAGS	= -Wall -Wextra -Werror

FILES	=	main	\
	
	
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exists

$(OBJF) :
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(LIBFT) -I $(MLX)

$(NAME): $(OBJ) $(HEADER) libft/libft.a mlx-linux/libmlx.a
	${CC} -$(CFLAGS) ${OBJ} -L ./libft -lft -L ./mlx-linux -lmlx -lXext -lX11 -lm -lbsd

# %.o: %.c libft/libft.a mlx-linux/libmlx.a
# 	$(CC) $(CFLAGS) -o $@ -c $< -I $(LIBFT) -I $(MLX)

libft/libft.a:
	${MAKE} -C libft

mlx-linux/libmlx.a :
	${MAKE} -C mlx-linux

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJF)
	${MAKE} -C libft clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean

re: fclean all

.PHONY: re all fclean clean