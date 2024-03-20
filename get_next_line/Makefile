NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =                   \
	get_next_line.c       \
	get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

AR = ar -rcs

all: ${NAME}

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ) get_next_line.h
	${AR} $(NAME) $(OBJ)

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
