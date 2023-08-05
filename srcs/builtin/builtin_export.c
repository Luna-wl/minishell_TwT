
#include "hell.h"

int		builtin_export(t_main *main, t_cmd *cmd);
void	ft_swap(char **s1, char **s2);
size_t	ft_len_trim(char *str, char trm);
size_t	ft_min_len(char *s1, char *s2);
void	print_sorted_env(t_main *main);
void	sort_env(char **env);
int		ft_envcpm(char *s1, char *s2);
char	**ft_strdup2();
char	**add_variable(char *cmd);
void	instead_variable(char *cmd, int row_vrb);
void	print_sorted_env(t_main *main);
char	*ft_strtrim_vrb(char *cmd, char set);

int	builtin_export(t_main *main, t_cmd *cmd)
{
	(void) cmd;
	(void) main;
	int	row_vrb;
	int	i;
	char	*vrb;

	if (!cmd->command[1])
		print_sorted_env(main);
	else
	{
		i = 0;
		while (cmd->command[++i])
		{
			vrb = ft_strtrim_vrb(cmd->command[i], '=');
			// printf("1 cmd->command[i] = |%s| vrb = |%s|\n", cmd->command[i], vrb);
			if (vrb && check_format_variable(vrb))
			{
				// if (ft_strrchr(cmd->command[i], '='))
				// {
					row_vrb = find_variable_inenv(vrb);
					if (row_vrb != -1) //found vrb -> return row that vrb exist
						instead_variable(cmd->command[i], row_vrb);
					else
						environ = add_variable(cmd->command[i]);
				// }
			}
			else
				err_msg_builtin("export", cmd->command[i]); //error but not exit
			if (vrb)
				free(vrb);
		}
	}
	return (0);
}

char	*ft_strtrim_vrb(char *cmd, char set)
{
	char	*str;
	int		i;
	int		check;

	i = 0;
	check = 0;
	str = NULL;

	while (cmd[i] && cmd[i] != set)
		i++;
	if (i > 0)
		check = 1;
	if (check == 1 && i > 0)
	{
		str = malloc(sizeof(char) * (i + 1));
		i = -1;
		while (cmd[++i] && cmd[i] != set)
			str[i] = cmd[i];
		str[i] = 0;
	}
	return (str);
}

char	**add_variable(char *cmd)
{
	int		i;
	char	**new;

	i = 0;
	while (environ[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (environ[++i])
		new[i] = ft_strdup(environ[i]);
	new[i] = ft_strdup(cmd);
	new[i + 1] = NULL;
	free(environ);
	return (new);
}

void	instead_variable(char *cmd, int row_vrb)
{
	unsigned int len;
	len = ft_strlen(cmd) + 1;
	free(environ[row_vrb]);
	environ[row_vrb] = malloc(sizeof(char) * len);
	ft_strlcpy(environ[row_vrb], cmd, len);
}

void	print_sorted_env(t_main *main)
{
	int		i;
	char	**str;
	(void)	main;

	str = ft_strdup2();
	sort_env(str);
	i = -1;
	while(str[++i])
		printf("declare -x %s\n", str[i]);
}

void	sort_env(char **env)
{
	int		i;
	int		j;

	i = -1;
	while (env[++i])
	{
		j = i;
		while (env[++j])
		{
			if (ft_envcpm(env[i], env[j]) > 0)
				ft_swap(&env[i], &env[j]);
		}
	}
}

size_t	ft_min_len(char *s1, char *s2)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (a > b)
		return (b);
	return (a);
}

char	**ft_strdup2(void)
{
	int		i;
	char	**new;

	i = 0;
	while (environ[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (environ[++i])
	{
		new[i] = ft_strdup(environ[i]);
	}
	new[i] = NULL;
	return (new);
}

int	ft_envcpm(char *s1, char *s2)
{
	size_t	a;
	size_t	b;

	if (ft_strncmp(s1, s2, ft_min_len(s1, s2)) != 0)
		return (ft_strncmp(s1, s2, ft_min_len(s1, s2)));
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (ft_strncmp(s1, s2, ft_min_len(s1, s2)) == 0 && a != b)
	{
		if (a > b)
			return ((unsigned char)s1[b] - (unsigned char)'\0');
		else
			return ((unsigned char)s2[a] - (unsigned char)'\0');
	}
	return (0);
}

void free_2d(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
