NAME = philo
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = check.c death.c init.c\
	main.c print.c routine.c\
	threads.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
