#include "hell.h"

void	reset_tool(t_main *main)
{
	del_split(main->envp);
	del_split(main->path);
	del_cmd(&main->cmd);

	main->lexer = NULL;
	main->cmd = NULL;
	main->num_pipe = 0;
	main->envp = get_envp2(); // word that before '=' in env to check sth. as USER PWD
	main->path = get_path(main->envp); // value after that spilt with ':' PATH=
}

void	free_all(t_main *main)
{
	char	**tmp;

	tmp = environ;
	del_split(tmp);
	environ = main->tmp;
	del_split(environ);
	del_split(main->envp);
	del_split(main->path);
	rl_clear_history();
}
