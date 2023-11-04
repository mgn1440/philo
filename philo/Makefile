CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OBJS = $(addprefix objs/, $(SRCS:.c=.o))
OBJ_DIR = objs
NAME = philos #why?
SRCS = arg_utils.c \
	error.c \
	ft_atoi.c \
	main.c \
	mutex_utils.c \
	philo.c \
	get_time.c \
	fork.c \
	print_utils.c

all: $(NAME)

$(NAME): $(OBJ_DIR) mandatory

$(OBJ_DIR):
	@mkdir objs

mandatory: $(OBJS)
	@rm -f mandatory bonus $(NAME)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@touch $@

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@rm -f $(MAIN_MAND:.c=.o)
	@rm -f $(MAIN_BONUS:.c=.o)
	@rm -f mandatory bonus
	@rm -rf $(OBJ_DIR)

re: fclean
	@make all

.PHONY: all clean fclean re
