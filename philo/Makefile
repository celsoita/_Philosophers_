CC = cc

NAME = philo

SRC = main.c ft_philo_utils.c ft_check_args.c ft_philo_init.c ft_death_check.c ft_free_program.c ft_routine.c ft_philo_alone.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

CFLAGS = -Wall -Wextra -Werror -pthread -g

%.o:%.c $(HEADER)
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