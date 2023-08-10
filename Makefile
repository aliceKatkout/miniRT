# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:30:00 by avedrenn          #+#    #+#              #
#    Updated: 2023/08/10 15:07:13 by avedrenn         ###   ########.fr        #
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
			parse_env	\
			ft_atof		\
			checks
	
	
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

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJF)
	${MAKE} -C libft clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean

re: fclean all

.PHONY: re all fclean clean