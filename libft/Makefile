# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailbezer <ailbezer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 11:08:49 by ailbezer          #+#    #+#              #
#    Updated: 2025/01/11 14:43:01 by ailbezer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_strlen.c ft_isprint.c \
		ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_abs.c get_next_line.c get_next_line_utils.c
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			ft_lstadd_back_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	@ar rc ${NAME} ${OBJ}

bonus: ${OBJ_BONUS}
	@ar rc ${NAME} ${OBJ_BONUS}

clean:
	@rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re