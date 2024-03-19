# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:33:26 by dboire            #+#    #+#              #
#    Updated: 2024/03/19 15:48:40 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

OUT_NAME = pipex

LIBFT = ../libft
GNL = ./GNL
PRINTF = ./FT_PRINTF

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =     \
	main_bonus.c \
		ft_parse_bonus.c \
		ft_utils_bonus.c \
		ft_access_bonus.c

OBJ = ${SRC:.c=.o}

GREEN   = \033[32m
BOLD    = \033[1m
END     = \033[0m
CHECKMARK = $(END)$(BOLD)[$(GREEN)✔$(END)$(BOLD)]$(END)

all: make_dependencies pipex_message ${NAME}

%.o: %.c
	@$(CC) ${CFLAGS} -c -g $< -o $@

make_dependencies:
	@for library in $(LIBFT) $(GNL) $(PRINTF) ; do \
		make -qC $$library ; \
		is_done=$$? ; \
		if [ $$is_done -eq 0 ] ; then \
			echo "$(CHECKMARK) nothing to be done for $(BOLD)$$library$(END)." ; \
		else \
			make -s -C $$library ; \
			echo "$(CHECKMARK) make $(BOLD)$$library$(END) done." ; \
		fi ; \
	done

$(LIBFT)/libft.a $(GNL)/gnl.a $(PRINTF)/libftprintf.a: make_dependencies

pipex_message:
	@make -q $(NAME) ; \
	is_done=$$? ; \
	if [ $$is_done -eq 0 ] ; then \
		echo "$(CHECKMARK) nothing to be done for $(BOLD)$(OUT_NAME)$(END)." ; \
	else \
		make -s $(OUT_NAME) ; \
		echo "$(CHECKMARK) make $(BOLD)$(OUT_NAME)$(END) done." ; \
	fi ; \

$(NAME) $(OUT_NAME): $(OBJ) pipex.h
	@ar -rcs temp_$(NAME) $(OBJ)
	@ar -rcT $(NAME) temp_$(NAME) $(LIBFT)/libft.a $(GNL)/gnl.a $(PRINTF)/libftprintf.a
	@${CC} ${CFLAGS} -g -o $(OUT_NAME) ${NAME}
	@rm -f temp_$(NAME)

clean:
	@rm -f ${OBJ} ${BOBJ}
	@cd $(LIBFT)/ && make -s clean
	@cd $(GNL)/ && make -s clean
	@cd $(PRINTF)/ && make -s clean
	@echo "clean done."

fclean: clean
	@rm -f ${NAME}
	@rm -f ${OUT_NAME}
	@cd $(LIBFT)/ && make -s fclean
	@cd $(GNL)/ && make -s fclean
	@cd $(PRINTF)/ && make -s clean
	@echo "fclean done."

re: fclean all

.PHONY : all make_dependencies pipex_message clean fclean re