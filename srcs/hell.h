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
	int				i;
	int				num_pipe;
	int				num_redirect;
	struct s_cmd	*next;
}	t_cmd;

t_int		g_i;
t_cmd	g_num;

// main.c
void		lexer_to_parser(char **str, t_lexer *lexer, t_cmd *cmd, char **envp);
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
char		*copy_str(char *str);
// parser_3.c
int			check_redirect(char *s);
// int			check_redirect(char *s);
// print_sth.c
void		pim_cmd(t_cmd *cmd);
void		pim_split(char **s);
void		pim_list(t_lexer *list);
// signal.c
void		init_signal(void);
void		sig_handler_c(int sig);
// buildin.c
void		print_word(char *str);
void		builtin_echo(t_cmd *cmd);
void		builtin_env(t_cmd *cmd, char **envp);
void		builtin_pwd(t_cmd *cmd);

#endif