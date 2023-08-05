/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:12:01 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 21:21:13 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

void	reset_tool(t_main *main, char *str)
{
	del_split(main->envp);
	del_split(main->path);
	del_cmd(&main->cmd);
	free(str);
}

void	free_all(t_main *main)
{
	char	**tmp;

	tmp = environ;
	del_split(tmp);
	environ = main->tmp;
	del_split(main->envp);
	del_split(main->path);
	rl_clear_history();
}

void	start_mimi(t_main *main)
{
	expander(main);
	sigint_handle(2);
	start_process(main);
}
