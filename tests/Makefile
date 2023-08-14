CFLAGS	= -Wall -Wextra -Werror 

FILES	=	parsing \
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

SRC_DIR	= ../srcs/

OBJ_DIR	= ../obj/

LIBFT	= ../../libft/libft.a

MLX		= ../../mlx-linux/libmlx.a

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
	$(CC) -ggdb $(CFLAGS) -o $@ -c $< -I $(LIBFT) -I $(MLX)
################################################################################
#                              	TEST VARIABLES					   		   	   #
################################################################################

CR_HEADER_PATH	=	-I${HOME}/Criterion/include/criterion
T_NAME			= 	test_miniRT
T_SRCS			=	$(addsuffix .c, $(T_FILES))
T_FILES			=	test_checks 
T_CC			=	gcc $(CR_HEADER_PATH) $(CR_LIB_PATH) $(CFLAGS) $(T_FLAGS)
CR_LIB_PATH		=	-Wl,-rpath=${HOME}/Criterion/build/src -L${HOME}/Criterion/build/src 
T_FLAGS			=	-lcriterion
T_OBJECTS 		=	$(subst /,/build/,${T_SRCS:.c=.o})

################################################################################
#                                TEST RULES								       #
################################################################################

all : ${T_NAME}

${T_OBJECTS}: $(subst .o,.c,$(subst /build/,/,$@)) 
	@if [ ! -d "./$(dir $@)" ]; then\
		mkdir -p $(dir $@);\
	fi
	$(T_CC) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@

${T_NAME}: ${T_OBJECTS} 
	@echo "Creating binary for Tests"
	@${T_CC} -o ${T_NAME} ${OBJ} ${T_OBJECTS} -L ../libft -lft -L ../mlx-linux -lmlx -lXext -lX11 -lm -lbsd 
	@./${T_NAME}


clean:
	@rm -rf ${T_OBJECTS}

fclean: clean
	rm -f $(T_NAME)

re: fclean all

.PHONY: re all fclean clean