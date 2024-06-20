SRC = 	main.c \
	init_fct.c \
	path.c \
	utils.c \


OBJ = $(SRC:.c=.o)

CC = cc

NAME = pipex

CFLAGS = -Wall -Werror -Wextra -g

INC = -Iincludes -I/usr/include -ILibft

LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C Libft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	rm -f ${OBJ}
	make -C Libft clean

fclean: clean
	rm -f ${NAME}
	make -C Libft fclean

re: fclean all

.PHONY: all clean fclean re