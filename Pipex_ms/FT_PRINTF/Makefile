# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 17:52:46 by dboire            #+#    #+#              #
#    Updated: 2023/11/16 11:16:12 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
	ft_switch.c \
	ft_write.c \
	ft_hexanum.c \
	ft_number.c \


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
