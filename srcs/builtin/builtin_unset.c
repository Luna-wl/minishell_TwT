#include "hell.h"

int		builtin_unset(t_main *main, t_cmd *cmd);
char	**delete_variable(int line);
void	err_msg_builtin(char *cmd1, char *cmd2);
int		find_variable_inenv(char *vrb);
int		check_format_variable(char *cmd);
char	*ft_join(char *s1, char *s2);

int	builtin_unset(t_main *main, t_cmd *cmd)
{
	int	row_vrb;
	int	i;

	(void) main;
	i = 0;
	while (cmd->command[++i])
	{
		if (check_format_variable(cmd->command[i]))
		{
			row_vrb = find_variable_inenv(cmd->command[i]);
			// printf("row_vrb = %d\n", row_vrb);
			// exit (0);
			if (row_vrb != -1) //found vrb -> return row that vrb exist
			{
				environ = delete_variable(row_vrb);
			}
		}
		else
			err_msg_builtin("unset", cmd->command[i]); //error but not exit
			//bash: unset: `8a': not a valid identifier
	}
	return (0);
}

char	**delete_variable(int line)
{
	int		i;
	int		j;
	char	**new;

	// (void) str;
	i = 0;
	while (environ[i])
		i++;
	new = malloc(sizeof(char *) * i);
	i = -1;
	j = -1;
	while (environ[++i])
	{
		if (i != line)
		{
			new[j] = ft_strdup(environ[i]);
			j++;
		}
	}
	new[j] = NULL;
	free(environ);
	return (new);
}

void	err_msg_builtin(char *cmd1, char *cmd2) //exit code == 1
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, cmd1, ft_strlen(cmd1));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd2, ft_strlen(cmd2));
	write(STDERR_FILENO, ": not a valid identifier\n", 25);
}

int		find_variable_inenv(char *vrb)
{
	int		i;
	char	*find;
	size_t	len1;
	size_t	len2;


	find = ft_join(vrb, "=");
	len1 = ft_strlen(find);
	len2 = ft_strlen(vrb);
	i = -1;
	while (environ[++i])
	{
		// printf("find=%s environ[%d]=%s len=%zu\n",find, i, environ[i], len);
		if (!ft_strncmp(find, environ[i], len1) || !ft_strncmp(vrb, environ[i], len2))
			return (free(find), i);
	}
	return (free(find), -1);
}

int	check_format_variable(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (i == 0)
		{
			if (!ft_isalpha(cmd[i]) && cmd[i] != '_')
				return (0);
		}
		else
		{
			if (!ft_isalpha(cmd[i]) && !ft_isdigit(cmd[i]) && cmd[i] != '_')
				return (0);
		}
	}
	return (1);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len +1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(&str[s1_len], s2, s2_len + 1);
	return (str);
}
