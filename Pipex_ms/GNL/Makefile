# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 17:52:46 by dboire            #+#    #+#              #
#    Updated: 2024/03/04 17:04:33 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS =	get_next_line.c \
	get_next_line_utils.c \

OBJTS = ${SRCS:.c=.o}
CC	= cc
RM	= rm -f
AR	= ar -crs
CFLAGS = -Wall -Wextra -Werror
 
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
 	
$(NAME): ${OBJTS}
	${AR} ${NAME} ${OBJTS}
	
all : ${NAME}

clean : 
	${RM} ${OBJTS}
	
fclean : clean
	${RM} ${NAME}
	
re : fclean all
