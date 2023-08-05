#include "hell.h"

void	reset_tool(t_main *main)
{
	// del_split(main->envp);
	// del_split(main->path);
	del_cmd(&main->cmd);
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
