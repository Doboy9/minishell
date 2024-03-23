/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:31 by wneel             #+#    #+#             */
/*   Updated: 2024/03/23 13:47:07 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_STRUCTS_H
#define PARSING_STRUCTS_H
# include "../wawa.h"

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
	char	*command_path;
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

#endif
