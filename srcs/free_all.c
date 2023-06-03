#include "hell.h"

void	free_all(t_main *main)
{
	free(main->input);
	del_split(environ);
	del_split(main->path);
	del_cmd(&main->cmd);
}