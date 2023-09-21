# This is a minimal set of ANSI/VT100 color codes
_END=$'\033[0m
_BOLD=$'\033[1m
_UNDER=$'\033[4m
_REV=$'\033[7m

# Colors
_GREY=$'\033[30m
_RED=$'\033[31m
_GREEN=$'\033[32m
_YELLOW=$'\033[33m
_BLUE=$'\033[34m
_PURPLE=$'\033[35m
_CYAN=$'\033[36m
_WHITE=$'\033[37m

################################################################################
#                                VARIABLES									   #
################################################################################

SRCS			=	srcs/creation_tuple.c	\
					srcs/operation_tuples.c	\
					srcs/operation_tuples2.c	\
					srcs/operation_tuples3.c	\
					srcs/colors.c	\
					srcs/matrix.c	\
					srcs/matrix_ops.c	\
					srcs/matrix_3.c	\
					srcs/matrix_4.c	\
					srcs/matrix_inversion.c	\
					srcs/transformations.c	\
					srcs/rotations.c	\
					srcs/shearing.c	\
					srcs/rays.c	\
					srcs/objs.c	\
					srcs/light.c \
					srcs/reflection.c	\
					srcs/world.c \
					srcs/shadow.c 	\
					srcs/intersections.c \
					srcs/intersections_cy.c \
					srcs/camera.c \
					srcs/p_parsing.c \
					srcs/p_utils.c \
					srcs/p_parse_env.c \
					srcs/p_parse_cam.c \
					srcs/p_parse_light.c \
					srcs/p_ft_atof.c \
					srcs/p_forms_utils.c \
					srcs/p_forms_init.c \
					srcs/p_forms.c \
					srcs/p_parse_cylinder.c \
					srcs/p_checks.c \
					srcs/utils.c \
					srcs/canvas.c \
					srcs/hook.c	\
					srcs/exit.c
MAIN_SRCS		=	srcs/main.c
NAME			= 	miniRT
RM				= 	rm -rf
CC				=	gcc -ggdb $(CFLAGS)
CFLAGS			=	-Wall -Werror -Wextra
OBJECTS 		=	$(subst /,/build/,${SRCS:.c=.o})
M_OBJECTS 		=	$(subst /,/build/,${MAIN_SRCS:.c=.o})

################################################################################
#                                MAIN RULES								       #
################################################################################

all:	$(NAME)

libft/libft.a:
	${MAKE} -C libft

${NAME}:	${OBJECTS} ${M_OBJECTS} libft
	@echo "${_UNDER}${_RED}Creating binary for Project${_END}"
	@echo "${_BOLD}${_GREEN}${CC} -o ${NAME} ${OBJECTS} ${M_OBJECTS}${_END}"
	@${CC} -o ${NAME} ${M_OBJECTS} ${OBJECTS} -L ./libft -lft -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

${M_OBJECTS}: $(subst .o,.c,$(subst /build/,/,$@))
	@echo "${_BOLD}${_BLUE}"$(CC) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@"${_END}"
	@$(CC) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@

${OBJECTS}: $(subst .o,.c,$(subst /build/,/,$@))
	@if [ ! -d "./$(dir $@)" ]; then\
		echo "${_BOLD}${_UNDER}${_BLUE}"mkdir -p $(dir $@)"${_END}";\
		mkdir -p $(dir $@);\
	fi
	@echo "${_BOLD}${_BLUE}"$(CC) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@"${_END}"
	@$(CC) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@

################################################################################
#                              	TEST VARIABLES					   		   	   #
################################################################################

CR_HEADER_PATH	=	-I${HOME}/Criterion/include/criterion
T_NAME			= 	test_project
T_SRCS			=	tests/test_tuples.c \
					tests/test_tuples_ops.c	\
					tests/test_colors.c	\
					tests/test_matrix.c	\
					tests/test_transformations.c\
					tests/test_rotations.c\
					tests/test_shearing.c\
					tests/test_chaining.c\
					tests/test_rays.c	\
					tests/test_reflection.c\
					tests/test_camera.c \
					tests/test_plane.c \
					tests/test_cylinders.c \
					tests/test_intersections.c\
					#tests/test_shadow.c \
					tests/test_world.c \
					tests/test_lights.c
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

tests:	${OBJECTS} ${T_OBJECTS} libft/libft.a
	@echo "${_UNDER}${_RED}Creating binary for Tests${_END}"
	@echo "${_BOLD}${_GREEN}${T_CC} -o ${T_NAME} ${OBJECTS} ${T_OBJECTS} ${_END}"
	@${T_CC} -o ${T_NAME} ${OBJECTS} ${T_OBJECTS} -lm -L ./libft -lft
	@./${T_NAME}

################################################################################
#                               	CLEANUP								       #
################################################################################

clean:
	@echo "${_UNDER}${_RED}Deleting Objects and Dependencies${_END}"
	@echo "${_BOLD}${_YELLOW}"${RM} ${OBJECTS} ${M_OBJECTS} ${T_OBJECTS} ${DEPEND}"${_END}"
	@${RM} ${OBJECTS} ${M_OBJECTS} ${T_OBJECTS} ${DEPEND}
	@echo "${_BOLD}${_YELLOW}"${RM} /build"${_END}"
	@${RM} /build

fclean: clean
	@echo "${_UNDER}${_RED}Deleting Executable${_END}"
	@echo "${_BOLD}${_RED}"${RM} ${NAME} ${T_NAME}"${_END}"
	@${RM} ${NAME} ${T_NAME}

re:	fclean all

retests: fclean tests

.PHONY:		all clean fclean re tests