NAME		= push_swap
SRCS		= main.c ./srcs/check_input.c ./srcs/handle_errors.c ./srcs/stack.c \
			./srcs/struct.c ./srcs/sort.c ./srcs/position.c ./srcs/cost.c \
			./moves/push.c ./moves/swap.c ./moves/rotates.c ./moves/do_move.c
OBJS		:= $(SRCS:%.c=%.o)
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror -g3
RM			= rm -f
DIR_HEADER  = -Iincludes
DIR_LIBFT 	= -Ilibft
NO_PRINT	= --no-print-directory
VALGRIND 	= valgrind --leak-check=full --track-origins=yes

GREEN = \033[1;32m
END   = \033[0m

all: libft ${NAME}

libft:
	@make -s -C ./libft			${NO_PRINT}

%.o: %.c
	@${CC} ${CFLAGS} ${DIR_HEADER} ${DIR_LIBFT} -c $< -o $@
	
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME}
	@echo "$(GREEN)Done!$(END)"

clean:
	@make clean -C ./libft	 	${NO_PRINT}
	@${RM} ${OBJS} ${OBJS_BONUS}
	@echo -n "$(GREEN)Cleaned$(END)"

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ./libft		${NO_PRINT}
	@echo "$(GREEN) all!$(END)"

re: fclean all


test2:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					$(VALGRIND) ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Moves: "
					@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re libft test2 test3 test5 test100 test500 test1000