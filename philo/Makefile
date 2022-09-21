NAME	= philo
FILE =
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rfv

OBJ = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
			$(RM) -rf $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re