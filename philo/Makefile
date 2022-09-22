NAME	= philo
FILE = src/main.c src/util.c src/init_philosopher.c src/action_philo.c src/view_philo.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rfv

OBJ = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
			$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJ)

clean:
			$(RM) -rf $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re