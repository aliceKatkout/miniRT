# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:30:00 by avedrenn          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/08/07 17:19:36 by mrabourd         ###   ########.fr        #
=======
#    Updated: 2023/08/07 17:28:15 by avedrenn         ###   ########.fr        #
>>>>>>> 9b6f7c2 (Change executable name)
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

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) libft/libft.a mlx-linux/libmlx.a
	${CC} $(CFLAGS) -o ${NAME} ${OBJ} -L ./libft -lft -L ./mlx-linux -lmlx -lXext -lX11 -lm -lbsd

$(OBJF) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(LIBFT) -I $(MLX)

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