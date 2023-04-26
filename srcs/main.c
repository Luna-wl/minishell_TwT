/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:26:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/04/07 19:18:33 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

void	into_builtin2(t_cmd *cmd, int i, char **envp)
{
	if (ft_strncmp(cmd->str[i], "echo", 4) == 0)
		builtin_echo(cmd);
	// else if (ft_strncmp(cmd->str[i], "cd", 2) == 0)
	// 	builtin_cd(cmd);
	else if (ft_strncmp(cmd->str[i], "pwd", 3) == 0)
		builtin_pwd(cmd);
	// else if (ft_strncmp(cmd->str[i], "export", 6) == 0)
	// 	builtin_export(cmd);
	// else if (ft_strncmp(cmd->str[i], "unset", 5) == 0)
	// 	builtin_unset(cmd);
	else if (ft_strncmp(cmd->str[i], "env", 3) == 0)
		builtin_env(cmd, envp);
	// else if (ft_strncmp(cmd->str[i], "exit", 4) == 0)
	// 	builtin_exit(cmd);
}

void	into_builtin(t_cmd *cmd, char **envp)
{
	t_cmd	*tmp;
	int		j;

	tmp = cmd;
	while (tmp != NULL)
	{
		j = 0;
		while (tmp->str[j])
		{
			into_builtin2(tmp, j, envp);
			j++;
		}
		tmp = tmp->next;
	}
}

void	lexer_to_cmd(char **str, t_lexer *lexer, t_cmd *cmd, char **envp)
{
	lexer = spilt_to_list(str, lexer);
	cmd = list_cmd(lexer, cmd);
	del_list_lexer(&lexer);
	pim_cmd(cmd);
	into_builtin(cmd, envp);
	// del_cmd(&cmd);
	// printf("cmd pipe = %d\n", g_num.num_pipe);
}

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	char		**new;
	t_lexer		*lexer;
	t_cmd		*cmd;
	(void)argv;

	if (argc > 1)
		print_str(YEL"You put the wrong input\n"RESET);
	lexer = NULL;
	cmd = NULL;
	printf(YEL"====> ~ HELLO WELCOME ~ <====\n"RESET);
	while (1)
	{
		// init_signal();
		str = readline(RED"mini(s)hell >> "RESET);
		add_history(str);
		if (!str)
		{
			printf(BCYN"========= ~Bye Bye~ =========\n"RESET);
			break ;
		}
		new = cut_cmd(str);
		lexer_to_cmd(new, lexer, cmd, envp);
		free(str);
	}
	return (0);
}

// # echo hello world|echo hello| echo ". hello "|ls| echo "'hello'"""
// -> Parser Sent to expander
// # {echo}, {hello}, {world}, NULL,
// # {echo}, {hello}, NULL,
// # {echo}, {". hello "}, NULL,
// # {ls}, NULL,
// # {echo}, {"'hello'"}, {""}, NULL.
// if '' / "" not complete pair ret"urn ERROR in lexer.

//fd inout of redirect