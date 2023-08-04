#include "hell.h"

void	free_all(t_main *main)
{
	del_split(environ);
	del_split(main->envp);
	del_split(main->path);
	del_cmd(&main->cmd);
}
