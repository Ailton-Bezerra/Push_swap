NAME		= push_swap
SRCS		= main.c ./srcs/utils.c ./srcs/sort.c \
			 ./srcs/move.c ./srcs/check_error.c ./srcs/struct.c \
			 ./srcs/position.c  ./srcs/cost.c ./srcs/do_move.c
OBJS		:= $(SRCS:%.c=%.o)
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror -g3
RM			= rm -f
DIR_HEADER  = -Iincludes
DIR_LIBFT 	= -Ilibft
DIR_PRINTF 	= -Iprintf
NO_PRINT	= --no-print-directory

GREEN = \033[1;32m
END   = \033[0m

all: libft printf ${NAME}

libft:
	@make -s -C ./libft			${NO_PRINT}

printf:
	@make -s -C ./printf		${NO_PRINT}

%.o: %.c
	@${CC} ${CFLAGS} ${DIR_HEADER} ${DIR_LIBFT} ${DIR_PRINTF} -c $< -o $@
	
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -Llibft -lft -Lprintf -lftprintf -o ${NAME}
	@echo "$(GREEN)Done!$(END)"

clean:
	@make clean -C ./libft	 	${NO_PRINT}
	@make clean -C ./printf   	${NO_PRINT}
	@${RM} ${OBJS} ${OBJS_BONUS}
	@echo -n "$(GREEN)Cleaned$(END)"

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ./printf	${NO_PRINT}
	@make fclean -C ./libft		${NO_PRINT}
	@echo "$(GREEN) all!$(END)"

re: fclean all

.PHONY: all clean fclean re libft printf