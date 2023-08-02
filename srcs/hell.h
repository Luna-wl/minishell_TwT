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
# include <limits.h>
# include <errno.h>

typedef struct s_lexer
{
	char			*str;
	int				index;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_cmd
{
	char			**str;
	char			**command;
	int				all_infile;
	int				all_outfile;
	int				cnt_infile;
	int				cnt_heredoc;
	int				cnt_outfile;
	int				cnt_append;
	int				cnt_cmd;
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
	char	*cur_path;
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
int		get_cmd(t_main *main, char *str);
char		**get_envp();
//del everything
void		free_all(t_main *main);
void		reset_tool(t_main *main);
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
void		sigint_handle(int mode);
void		sighandle(int sig);
void		handel_c(int sig);
// builtin.c
// void		into_builtin(t_main *main);
// void		into_builtin2(t_main *main, t_cmd *cmd, int i);

int			check_builtin(t_cmd *tmp);
int			into_builtin_parent(t_main *main, t_cmd *cmd);
int			into_builtin_child(t_main *main, t_cmd *cmd);
// buildin.c
void		print_word(char *str);
int			builtin_echo(t_main *main, t_cmd *cmd);
int			builtin_env(t_main *main, t_cmd *cmd);
int			builtin_pwd(t_main *main, t_cmd *cmd);
int			builtin_export(t_main *main, t_cmd *cmd);
int			builtin_unset(t_main *main, t_cmd *cmd);
int			builtin_exit(t_main *main, t_cmd *cmd);
int			builtin_cd(t_main *main, t_cmd *cmd);
// expander.c
void		expander(t_main *main);
char		*cut_quote(char *str);
char		*detact_dollar(char *str, t_main *main);
char	*get_val_quote(char *str, t_main *main, char *val);
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

//mobile///////////////////////////////////////////////////


//	ft_dup2.c
// void	ft_dup2(t_main *main, t_cmd *tmp, int id);
// void	dup_first_child(t_main *main, t_cmd *tmp);
// void	dup_last_child(t_main *main, t_cmd *tmp);
void	open_infile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr);
void	open_outfile(t_main *main, t_cmd *tmp, char **file_name, int file_nbr);
void	dup_infile(t_main *main, t_cmd *tmp, int id);
void	dup_outfile(t_main *main, t_cmd *tmp, int id);

// void	ft_putstr_fd(char *str, int fd);
// char	**ft_split(char const *s, char c);
// char	*ft_strdup(char *str);
// char	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
// size_t	ft_strlen(char *str);
// int		ft_strncmp(char *s1, char *s2, size_t n);
// int		ft_strstr(char *str, char *find);

//	here_doc.c
void	get_heredoc(t_main *main);
void	read_heredoc(t_main *main, t_cmd *tmp, size_t len_filename, int i);
int		check_limiter(char *line, char *limiter, size_t n);
int		check_append_file(t_cmd *tmp, char *file_name);
int		check_heredoc_file(t_cmd *tmp, char *file_name);

//	pipex_bonus.c
// void	init_value(t_main *main, int argc);

//	process.c
void	start_process(t_main *main);
void	create_process(t_main *main);
void	child_process(t_main *main, t_cmd *tmp, int id);
void	parent_process(t_main *main, t_cmd *tmp, int id);
void	waiting_process(t_main *main);
int		check_redirect(char *s);

	// utils_cmd .c
int		ft_find_slash(char *str);
// void	count_cmd(t_main *main, char *filename);
// void	free_cmd(t_main *main);

	// utils_error.c
void	err_file(t_main *main, char *file);
void	err_cmd(t_main *main, char *cmd, int err);
void	err_msg_free(t_main *main, char *msg);
void	err_msg(char *msg);
void	ft_exit(int err);
int		err_builtin(t_main *main, t_cmd *cmd);
// 	utils_path.c
// int		find_path(char **env);
int		check_access_path(t_main *main, char *cmd);
// void	free_path(t_main *main);

void	err_msg_builtin(char *cmd1, char *cmd2);
int		find_variable_inenv(char *vrb);
int		check_format_variable(char *cmd);

#endif
