NAME = minishell.a

OUT_NAME = minishell

LIBFT = ./libft
GNL = ./get_next_line

CC = cc
VG = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --suppressions=readlinesupp

CFLAGS = -Wall -Wextra -Werror
CLIB = -lreadline

PARSING_SRCS =          \
	parsing/utils.c        \
	parsing/parse_quotes.c  \
	parsing/parse_env_vars.c \
	parsing/parse_text_read.c \
	parsing/commands_inputs.c  \
	parsing/commands_outputs.c  \
	parsing/commands_arguments.c \

SRC =       \
	main.c     \
	wawa.c      \
	wawa_utils.c  \
	wawastuff/r.c  \
	wawa_printers.c \
	$(PARSING_SRCS)

OBJ = ${SRC:.c=.o}

GREEN   = \033[32m
BOLD    = \033[1m
END     = \033[0m
CHECKMARK = $(END)$(BOLD)[$(GREEN)✔$(END)$(BOLD)]$(END)

all: make_dependencies minishell_message ${NAME}

%.o: %.c
	@$(CC) ${CFLAGS} -c -g $< -o $@

make_dependencies:
	@for library in $(LIBFT) $(GNL) ; do \
		make -qC $$library ; \
		is_done=$$? ; \
		if [ $$is_done -eq 0 ] ; then \
			echo "$(CHECKMARK) nothing to be done for $(BOLD)$$library$(END)." ; \
		else \
			make -s -C $$library ; \
			echo "$(CHECKMARK) make $(BOLD)$$library$(END) done." ; \
		fi ; \
	done

$(LIBFT)/libft.a $(GNL)/get_next_line.a: make_dependencies

minishell_message:
	@make -q $(NAME) ; \
	is_done=$$? ; \
	if [ $$is_done -eq 0 ] ; then \
		echo "$(CHECKMARK) nothing to be done for $(BOLD)$(OUT_NAME)$(END)." ; \
	else \
		make -s $(OUT_NAME) ; \
		echo "$(CHECKMARK) make $(BOLD)$(OUT_NAME)$(END) done." ; \
	fi ; \

$(NAME) $(OUT_NAME): $(OBJ) wawa.h
	@ar -rc --thin $(NAME) $(OBJ) $(LIBFT)/libft.a $(GNL)/get_next_line.a
	@${CC} ${CFLAGS} $(CLIB) -g -o $(OUT_NAME) ${NAME}

clean:
	@rm -f ${OBJ}
	@cd $(LIBFT)/ && make -s clean
	@cd $(GNL)/ && make -s clean
	@echo "clean done."

fclean: clean
	@rm -f ${NAME}
	@rm -f ${OUT_NAME}
	@cd $(LIBFT)/ && make -s fclean
	@cd $(GNL)/ && make -s fclean
	@echo "fclean done."

re: fclean all

run:
	@make
	@./${OUT_NAME}

vrun:
	@make
	@${VG} ./${OUT_NAME}

.PHONY : all make_dependencies minishell_message clean fclean re
