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

typedef struct s_int
{
	int	i;
	int	j;
}	t_int;

typedef struct s_lexer
{
	char			*str;
	int				index;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_cmd
{
	char			**str;
	int				num_redirect;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_mini
{
	char	**env;
	t_cmd	*cmd;
}	t_mini;

typedef struct s_main
{
	char	**env;
	char	*input;
	char	**str_cmd;
	int		num_pipe;
	t_cmd	*cmd;
	t_lexer	*lexer;
	char	*pwd;
	char	*old_pwd;
	char	**path;
	struct s_command	*command;
}	t_main;

typedef struct s_command
{
	char					**cmd;
	struct s_command		*next;
}	t_command;

t_int	g_i;
t_main	g_num;

extern char **environ;

// lexer1
void		init_int(void);
int			check_quote(char **s);
char		*my_split(char *s);
char		**cut_cmd(char *s);
// lexer2
int			check_word_2(char *s);
int			count_len_quote(char *s);
int			check_word(char *s, int len);
int			count_letter_split(char *s);
int			count_letter(char *s);
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
int			find_pipe(t_lexer *list, t_cmd *cmd);
int			find_cmd_num(t_lexer *list);
void		next_cmd(t_lexer **list, int index);
t_cmd		*list_cmd(t_lexer *list, t_cmd *cmd);
// parser_2.c
int			stack_lenght(t_lexer **list);
char		**copy_two_stars(t_lexer **list);
void		add_last_cmd(t_cmd **cmd, t_cmd *last);
void		create_list_cmd(t_cmd **cmd, t_lexer *list);
// parser_3.c
int			check_redirect(char *s);
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
// main.c
void		get_cmd(t_main *main);
void		copy_info(t_main *main, char *str);
// expander.c
void		expander(t_main *main);
// char		*cut_quote(char *str, char *new);
char		*cut_quote(char *str);
// util_expan
// char		*copy_str(char *s, int len, char *old);
char		*copy_str(char *s, int len);
int			len_quote(char *s);
// util_info
char		**get_path();
int			find_path2(char *str);
char		*find_path(char *str);

char	**get_envp();

#endif