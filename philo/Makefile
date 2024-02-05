NAME	= philo
FILE = src/main.c src/init_philosopher.c	\
		src/creating_philosopher.c src/acting_philosopher.c \
		src/utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
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