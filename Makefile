# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:30:00 by avedrenn          #+#    #+#              #
#    Updated: 2023/08/14 17:37:44 by mrabourd         ###   ########.fr        #
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


################################################################################
#                              	TEST VARIABLES					   		   	   #
################################################################################

CR_HEADER_PATH	=	-I${HOME}/Criterion/include/criterion
T_NAME			= 	test_project
T_SRCS			=	test/test_1.c
T_CC			=	gcc $(CR_HEADER_PATH) $(CR_LIB_PATH) $(CFLAGS) $(T_FLAGS)
CR_LIB_PATH		=	-Wl,-rpath=${HOME}/Criterion/build/src -L${HOME}/Criterion/build/src
T_FLAGS			=	-lcriterion
T_OBJECTS 		=	$(subst /,/build/,${T_SRCS:.c=.o})

################################################################################
#                                TEST RULES								       #
################################################################################

${T_OBJECTS}: $(subst .o,.c,$(subst /build/,/,$@))
	@if [ ! -d "./$(dir $@)" ]; then\
		echo "${_BOLD}${_UNDER}${_BLUE}"mkdir -p $(dir $@)"${_END}";\
		mkdir -p $(dir $@);\
	fi
	@echo "${_BOLD}${_BLUE}"$(T_CC) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@"${_END}"
	@$(T_CC) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@

tests:	${OBJ} ${T_OBJECTS}
	@echo "${_UNDER}${_RED}Creating binary for Tests${_END}"
	@echo "${_BOLD}${_GREEN}${T_CC} -o ${T_NAME} ${OBJ} ${T_OBJECTS} ${_END}"
	@${T_CC} -o ${T_NAME} ${OBJECTS} ${T_OBJECTS}
	@./${T_NAME}

	
clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJF)
	${MAKE} -C libft clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean

re: fclean all

.PHONY: re all fclean clean