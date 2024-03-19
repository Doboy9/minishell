/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:31 by wneel             #+#    #+#             */
/*   Updated: 2024/03/19 16:00:38 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAWA_H
#define WAWA_H
# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

enum SPECIAL_CHARACTERS {
	TEXT = 0,
	PIPE = 1,
	ANGLE_BRACE_LEFT = 2,
	ANGLE_BRACE_RIGHT = 3,
	DOUBLE_ANGLE_BRACE_LEFT = 4,
	DOUBLE_ANGLE_BRACE_RIGHT = 5
};

enum INPUTS {
	STANDARD_INPUT = 0,
	FILE_INPUT = 1,
	PIPE_INPUT = 2,
	HERE_DOC_INPUT = 3
};

typedef struct	s_input
{
	int		file_fd;
	char	*file_path;
	int		input_type;
}				t_input;

enum OUTPUTS {
	STANDARD_OUTPUT = 0,
	FILE_OUTPUT = 1,
	PIPE_OUTPUT = 2
};

typedef struct	s_output
{
	int		file_fd;
	char	*file_path;
	int		output_type;
	int		append;
}				t_output;

typedef struct	s_command
{
	t_input	**inputs;
	int		argc;
	char	**argv;
	char	*command;
	int		flag_n;
	t_output	**outputs;
}				t_command;

typedef struct	s_quote_status
{
	int in_squotes;
	int in_dquotes;
}				t_quote_status;

typedef struct s_cmd_cursor
{
	int	start;
	int	end;
}						t_cmd_cursor;

typedef struct s_text_read
{
	char	*raw_text;
	char	*exp_text;
	int		is_metachar;
	int		is_attribution;
}				t_text_read;

int		ft_is_word_cutter(const char *str, int index);
char	**ft_split_bash_words(char const *s);
int		ft_wawa(int ac, char *av[], char *ev[]);
void	ft_print_text_read_tab(t_text_read **text_read);
void	ft_print_text_read_el(t_text_read *text_read);
void	ft_print_cmd_el(t_command *command);
void	ft_print_split(char **splitted);
int		var_name_end(char *str);
int		calc_expanded_size(char *str, int i);
void	assign_evar(char *str, char *expanded_char, int *j, int *k);
char	*expand_vars(char *str);
void	update_quote_status(char c, t_quote_status *quote_status);
void	ft_init_quote_status(t_quote_status *quote_status);
int		is_well_quoted(char *str);
int		char_tab_len(char **tab);
int		reverse_bool(int bool);
int		parse_flags(char **flags);
char	**make_chartab(int n, ...);
int		parse_word(char *bash_word);
#endif
