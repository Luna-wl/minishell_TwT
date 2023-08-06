/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:12:27 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 18:41:40 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**tmp;

	pid_t	*pid;
	char	*cur_path;
	int		heredoc;
	int		cur;
	int		fd_file;
	int		tmp_fd;
	int		found_path;
	int		pfd[2];
	int		status;
	int		exit_status;
	int		do_cmd;
	int		cmd_nbr;
}	t_main;

extern char	**environ;

// into_cmd.c
int			get_cmd(t_main *main, char *str);
char		**get_envp(void);
//del everything
void		free_all(t_main *main);
void		reset_tool(t_main *main, char *str);
void		start_mimi(t_main *main);
// lexer_1
char		*my_split_lexer(char *s);
int			check_error(char *s);
int			check_quote_pair(char **s);
int			find_len_split(char **s);
// lexer2
int			check_word_2(char *s);
int			count_len_quote(char *s);
int			count_letter_split(char *s, int i);
int			count_letter_lexer(char *s);
int			count_letter2(char *s, int i, int j);
// lexer3
void		add_last(t_lexer **list, t_lexer *last);
void		init_list(t_lexer **list, char *str);
void		insert_index(t_lexer **list, int len);
t_lexer		*spilt_to_list(char **str, t_lexer *list);
//lexer4
int			check_word_lexer3_1(char *s, int i);
// handle_problems.c
int			is_space(char c);
int			is_tokens(char c);
int			is_quote(char c);
int			is_pipe(char c);
// error404.c
void		del_split(char **str);
void		print_str(char *s);
void		del_list_lexer(t_lexer **list);
void		del_cmd(t_cmd **cmd);
void		del_sam_dao(char ***s);
// parser_1.c
int			find_cmd_num(t_lexer *list);
t_cmd		*list_cmd(t_main *main, char ***str);
char		**copy_two_stars_new(char **s);
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
int			find_size3(char ***s);
// print_sth.c
void		pim_cmd(t_cmd *cmd);
void		pim_split(char **s);
void		pim_list(t_lexer *list);
// signal.c
void		sighandle(int sig);
void		init_signal(void);
void		sigint_handle(int mode);
void		sigquit_handle(int sig);
void		handel_c(int sig);

// expander.c
void		expander(t_main *main);
char		*cut_quote(char *str);
char		*detact_dollar(char *str, t_main *main);
char		*get_val_quote(char *str, t_main *main, char *val, int i);
// util_expan
char		*copy_str(char *s, int len);
int			len_quote(char *s);
char		*replace_val(char *s1, char *s2);
void		check_val(char **cmd);
// util_info
char		**get_envp2(void);
int			find_envp2(char *str);
char		*find_envp(char *str);
char		**get_path(char **envp);
//handle_quote.c
char		*cut_quote(char *str);
char		*detact_quote(char *str, t_main *main, char *val);
char		*detact_quote2(char *str, t_main *main, char *val);
char		*detact_quote3(char *str, t_main *main, char *val);
//test
char		***cut_test(char **s);
int			count_len_quote2(char *s);
void		pim_sam_dao(char ***s);
void		create_list(t_cmd **cmd, char **s);
void		add_last_new(t_cmd **cmd, t_cmd *last);

//mobile///////////////////////////////////////////////////

// builtin_cd.c
int			builtin_cd(t_cmd *cmd);

// builtin_echo.c
int			builtin_echo(t_cmd *tmp);
void		print_word(char *str);
void		do_echo(t_cmd *tmp, int i, int opt);
void		print_sorted_env(void);

// builtin_env.c
int			builtin_env(t_cmd *cmd);
char		**ft_strdup_env(void);
size_t		ft_min_len(char *s1, char *s2);
int			ft_envcpm(char *s1, char *s2);
void		sort_env(char **env);

// builtin_exit.c
int			builtin_exit(t_main *main, t_cmd *cmd);
void		error_msg_exit(char *msg, int err);
int			check_nbr(char *str);
int			cal_exit_code(char *str);

// builtin_export.c
void		do_export(char *cmd, int row_vrb, char *vrb);
int			builtin_export(t_main *main, t_cmd *cmd);
char		*ft_strtrim_vrb(char *cmd, char set);
char		**add_variable(char *cmd);
void		instead_variable(char *cmd, int row_vrb);

// builtin_pwd.c
int			builtin_pwd(t_main *main, t_cmd *cmd);

// builtin_unset.c
int			builtin_unset(t_cmd *cmd);
char		**delete_variable(int line);

// builtin.c
int			check_builtin(t_cmd *tmp);
int			into_builtin_parent(t_main *main, t_cmd *cmd);
int			into_builtin_child(t_main *main, t_cmd *cmd);
int			builtin_parent_process(t_main *main, t_cmd *tmp);

// utils_builtin.c
void		ft_swap(char **s1, char **s2);
int			find_variable_inenv(char *vrb);
int			check_format_variable(char *cmd);
char		*ft_join(char *s1, char *s2);
void		err_msg_builtin(char *cmd1, char *cmd2);

// utils_cmd.c
int			ft_find_slash(char *str);
void		get_letter_cmd(t_cmd *tmp, char *s, int cnt_word);
void		get_command(t_main *main, t_cmd *tmp);
int			check_redirect(char *s);
void		ft_close_pipe(t_main *main, int pfd);

// ft_dup2.c
void		open_infile(t_main *main, t_cmd *tmp, \
char **file_name, int file_nbr);
void		open_outfile(t_main *main, t_cmd *tmp, \
char **file_name, int file_nbr);
void		dup_infile(t_main *main, t_cmd *tmp, int id);
void		dup_outfile(t_main *main, t_cmd *tmp, int id);

// here_doc.c
void		get_heredoc(t_main	*main);
void		read_heredoc(t_cmd *tmp, size_t len_filename, int i);
int			check_limiter(char *line, char *limiter, size_t n);
int			check_append_file(t_cmd *tmp, char *file_name);
int			check_heredoc_file(t_cmd *tmp, char *file_name);

// process.c
void		start_process(t_main *main);
void		create_process(t_main *main);
void		child_process(t_main *main, t_cmd *tmp, int id);
void		parent_process(t_main *main, t_cmd *tmp);
void		waiting_process(t_main *main);

// utils_cmd .c
int			ft_find_slash(char *str);
void		get_letter_cmd(t_cmd *tmp, char *s, int cnt_word);
void		get_command(t_main *main, t_cmd *tmp);
int			check_redirect(char *s);
void		ft_close_pipe(t_main *main, int pfd);

	// utils_error.c
void		err_file(t_cmd *tmp, char *file);
void		err_cmd(t_main *main, t_cmd *tmp, char *cmd, int err);
int			err_builtin(t_cmd *cmd, int err);
void		err_msg(char *msg);
void		ft_exit(int err);

// utils_free.c
void		free_2d(char **str);

// 	utils_path.c
char		*ft_join_path(char *s1, char *s2);
int			check_access_path(t_main *main, t_cmd *tmp, char *cmd);

// expander.c
char		*detact_dollar(char *str, t_main *main);
char		*expander_handel(t_main *main, char *str);
void		expander(t_main *main);

// find_quote.c
char		check_open_close_quote(char quote, char *str, int *i);
int			strlen_quote(char *str, t_main *main, int i, int j);
char		*get_val_quote(char *str, t_main *main, char *val, int i);
char		*get_val_dollar(char *str, t_main *main, int i);
char		*get_val(char	*vrb, char	*val);

#endif
