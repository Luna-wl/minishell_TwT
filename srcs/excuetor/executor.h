/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:00:59 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/06/02 01:16:48 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <sys/wait.h>
# include "hell.h"
# include "./get_next_line_bonus.h"

//	ft_dup2.c
void	ft_dup2(t_main *main, char **argv, int id);
void	dup_first_child(t_main *main, char *infile);
void	dup_last_child(t_main *main, char *outfile);

void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strstr(char *str, char *find);

//	here_doc.c
void	read_heredoc(t_main *main, char **argv);
int		check_limiter(char *line, char *limiter, size_t n);

//	pipex_bonus.c
void	init_value(t_main *main, int argc);

//	process.c
void	start_process(t_main *main);
void	create_process(t_main *main);
void	child_process(t_main *main, int id);
void	parent_process(t_main *main);
void	waiting_process(t_main *main);

//	utils_cmd.c
int		ft_find_slash(char *str);
void	count_cmd(t_main *main);
void	free_cmd(t_main *main);

//	utils_error.c
void	err_file(t_main *main, char *file);
void	err_cmd(t_main *main, char *cmd, int err);
void	err_msg_free(t_main *main, char *msg);
void	err_msg(char *msg);
void	ft_exit(int err);

//	utils_path.c
int		find_path();
int		check_access_path(t_main *main, char *cmd);
void	free_path(t_main *main);

#endif
