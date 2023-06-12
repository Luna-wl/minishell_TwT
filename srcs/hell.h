#ifndef HELL_H
# define HELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include "./libft.h"
# include "./get_next_line_bonus.h"
# include "./ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "colours.h"

enum token {
	GREAT, // output >
	LESS, // input <
	APPEND, // >>
	HEREDOC, // <<
};

typedef struct s_lexer
{
	char			*str;
	int				index;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_cmd
{
	char			**str;
	int				all_infile;
	int				all_outfile;
	int				cnt_infile;
	int				cnt_heredoc;
	int				cnt_outfile;
	int				cnt_append;
	char			**infile_name;
	char			**outfile_name;
	char			**heredoc_file;
	char			**append_file;
	int				fd_redirect;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_main
{
	char	*input;
	char	**str_cmd;
	int		num_pipe;
	t_cmd	*cmd;
	t_lexer	*lexer;
	char	*pwd;
	char	*old_pwd;
	char	**envp;
	char	**path;

	pid_t	*pid;
	int		heredoc;
	int		cur;
	int		fd_file;
	int		tmp_fd;
	int		found_path;
	int		pfd[2];
	int		status;
	int		cmd_nbr;

	struct s_command	*command;
}	t_main;

typedef struct s_command
{
	char				**cmd;
	struct s_command	*next;
}	t_command;

extern char **environ;

// into_cmd.c
void		get_cmd(t_main *main, char *str);
char		**get_envp();
//del everything
void		free_all(t_main *main);
// lexer1
int			check_quote(char **s);
char		*my_split_lexer(char *s);
char		**cut_cmd(char *s);
int			check_error(char **s);
// lexer2
int			check_word_2(char *s);
int			count_len_quote(char *s);
int			check_word_lexer(char *s, int len, int i);
int			count_letter_split(char *s, int i);
int			count_letter_lexer(char *s);
int			count_letter2(char *s, int i, int j);
// lexer3
int			find_len_split(char **s);
void		add_last(t_lexer **list, t_lexer *last);
void		init_list(t_lexer **list, char *str);
void		insert_index(t_lexer **list, int len);
t_lexer		*spilt_to_list(char **str, t_lexer *list);
// handle_problems.c
int			is_space(char c);
int			is_tokens(char c);
int			is_quote(char c);
// error404.c
void		del_split(char **str);
void		print_str(char *s);
void		del_list_lexer(t_lexer **list);
void		del_cmd(t_cmd **cmd);
// parser_1.c
int			find_pipe(t_main *main);
int			find_cmd_num(t_lexer *list);
void		next_cmd(t_lexer **list, int index);
t_cmd		*list_cmd(t_main *main);
// parser_2.c
int			stack_lenght(t_lexer **list);
char		**copy_two_stars(t_lexer **list);
void		add_last_cmd(t_cmd **cmd, t_cmd *last);
void		create_list_cmd(t_cmd **cmd, t_lexer *list);
// parser_3.c
int			cnt_infile(char **cmd);
int			cnt_heredoc(char **cmd);
int			cnt_outfile(char **cmd);
int			cnt_append(char **cmd);
// parser_4.c
char		**check_heredoc(char **cmd, int hc);
char		**check_infile(char **cmd, int inf);
char		**check_outfile(char **cmd, int of);
char		**check_append(char **cmd, int ap);
// print_sth.c
void		pim_cmd(t_cmd *cmd);
void		pim_split(char **s);
void		pim_list(t_lexer *list);
// signal.c
void		init_signal(void);
void		sig_handler_c(int sig);
// builtin.c
void		into_builtin(t_main *main);
void		into_builtin2(t_cmd *cmd, int i);
// buildin.c
void		print_word(char *str);
void		builtin_echo(t_cmd *cmd);
void		builtin_env();
void		builtin_pwd(t_cmd *cmd);
// expander.c
void		expander(t_main *main);
char		*cut_quote(char *str);
char		*detact_dollar(char *str, t_main *main);
// util_expan
char		*copy_str(char *s, int len);
int			len_quote(char *s);
// util_info
char		**get_envp2();
int			find_envp2(char *str);
char		*find_envp(char *str);
char		**get_path(char **envp);
//handle_quote.c
char		*cut_quote(char *str);
char		*detact_quote(char *str, t_main *main, char *val);
char		*detact_quote2(char *str, t_main *main, char *val);


#endif