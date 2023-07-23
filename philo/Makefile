CC = cc

NAME = philo

SRC = main.c ft_philo_utils.c ft_check_args.c ft_philo_init.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pthread -g

%.o:%.c
	$(CC) $(CFLAGS) -c  $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus