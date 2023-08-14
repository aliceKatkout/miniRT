# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:30:00 by avedrenn          #+#    #+#              #
#    Updated: 2023/08/14 19:01:56 by avedrenn         ###   ########.fr        #
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
			parsing \
			utils 	\
			forms	\
			forms_utils \
			forms_init \
			parse_env	\
			ft_atof		\
			checks	\
			print_struc
	
	
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES))) 
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) libft/libft.a mlx-linux/libmlx.a
	${CC} $(CFLAGS) -o ${NAME} ${OBJ} -L ./libft -lft -L ./mlx-linux -lmlx -lXext -lX11 -lm -lbsd

$(OBJF) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) -ggdb $(CFLAGS) -o $@ -c $< -I $(LIBFT) -I $(MLX)

# %.o: %.c libft/libft.a mlx-linux/libmlx.a
# 	$(CC) $(CFLAGS) -o $@ -c $< -I $(LIBFT) -I $(MLX)

libft/libft.a:
	${MAKE} -C libft

mlx-linux/libmlx.a :
	${MAKE} -C mlx-linux


tests:
	${MAKE} -C tests

cleantest :
	${MAKE} -C tests clean

retest :
	${MAKE} -C tests re

clean:
	@rm -rf $(OBJ_DIR) 
	@rm -f $(OBJF)
	${MAKE} -C libft clean
	${MAKE} -C tests clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean
	${MAKE} -C tests clean

re: fclean all


.PHONY: re all fclean clean tests retest cleantest