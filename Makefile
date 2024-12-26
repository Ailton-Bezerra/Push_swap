SRCS	= main.c utils.c
OBJS	:= $(SRCS:%.c=%.o)
NAME	= push_swap
CC		= cc
RM		= rm -f
CFLAGS 	= -Wall -Wextra -Werror -g3 -fsanitize=address

BLUE = \033[1;34m
GREEN=\033[0;32m
END=\033[0m

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -Ilibft -Iprintf -c $? -o $@
	@make -C ./libft --no-print-directory
	@make -C ./printf --no-print-directory
	

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o push_swap


clean:
	@echo "$(GREEN)cleaning...$(END)"
	@make clean -C ./libft --no-print-directory
	@make clean -C ./printf --no-print-directory
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@${RM} push_swap
	@make -C ./printf --no-print-directory fclean
	@make -C ./libft --no-print-directory fclean
	@echo "$(GREEN) all cleaned!$(END)"

re: fclean all

.PHONY: all clean fclean