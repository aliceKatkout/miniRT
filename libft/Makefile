# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avedrenn <avedrenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 12:19:41 by avedrenn          #+#    #+#              #
#    Updated: 2022/11/11 17:46:50 by avedrenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= ft_isascii.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_atoi.c ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
ft_bzero.c ft_isprint.c  ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
ft_calloc.c ft_itoa.c  ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
ft_isalnum.c  ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
ft_isalpha.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c

BONUS= ft_lstadd_back.c ft_lstmap.c ft_lstadd_front.c ft_lstnew.c \
ft_lstclear.c ft_lstsize.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c

NAME= libft.a

OBJ= $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

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
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)

.PHONY: re all fclean clean bonus
