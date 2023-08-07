# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 12:19:41 by avedrenn          #+#    #+#              #
#    Updated: 2023/01/19 16:13:59 by avedrenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= ft_isascii.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_atoi.c ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_bzero.c ft_isprint.c  ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
ft_calloc.c ft_itoa.c  ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
ft_isalnum.c  ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
ft_isalpha.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
ft_lstadd_back.c ft_lstmap.c ft_lstadd_front.c ft_lstnew.c \
ft_lstclear.c ft_lstsize.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
ft_printf.c type_fts.c type_fts2.c ft_realloc.c ft_strslen.c \
get_next_line.c get_next_line_utils.c

NAME= libft.a

OBJ= $(SRC:.c=.o)

CC= gcc

HEADER = libft.h

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean
