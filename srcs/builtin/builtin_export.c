
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
			if (check_format_variable(vrb))
			{
				row_vrb = find_variable_inenv(vrb);
				if (row_vrb != -1) //found vrb -> return row that vrb exist
					instead_variable(cmd->command[i], row_vrb);
				else
					environ = add_variable(cmd->command[i]);
				// printf("--------------------\n");
				// printf("2 vrb = %s %p\n", vrb, &vrb);
			}
			else
				err_msg_builtin("export", cmd->command[i]); //error but not exit
			// exit(0);
			if (vrb)
			{
				printf("--------------------\n");
				printf("3 vrb = %s %p\n", vrb, &vrb);
				free(vrb);
			}
		}
	}
	// char **str = ft_strdup2();
	// sort_env(str);
	// sort_evnv(str);
	// int i = -1;
	// while(str[++i])
	// {
	// 	printf("str[%d] = |%s|\n", i, str[i]);
	// 	printf("env[%d] = |%s|\n", i, environ[i]);
	// 	printf("-----------------------------------------------------------------------\n");
	// }
	// print_sorted_env(main);
	// printf("%d\n",ft_envcpm("0=gh", ""));
	// if (i < )
	// if (environ[i + 1])
	// 	compare = ft_strtrim(environ[i + 1], "=");
	// if (ft_strncmp(first, compare, ft_strlen(first)) < 0)

	return (0);
	// return (exit(0));
}

char	*ft_strtrim_vrb(char *cmd, char set)
{
	char	*str;
	int		i;
	int		check;

	i = -1;
	check = 0;
	str = NULL;
	while (cmd[++i])
	{
		if (cmd[i] == set)
		{
			check = 1;
			break;
		}
	}
	if (check == 1 && i > 0)
	{
		// printf("i = %d\n", i);
		str = malloc(sizeof(char) * i);
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

	// (void) str;
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
	// size_t len;
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

	// i = -1;
	str = ft_strdup2();
	// while(str[++i])
	// 	printf("env[%d] = |%s|\n", i, str[i]);
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
	// while(env[++i])
	// 	printf("env[%d] = |%s|\n", i, env[i]);

	while (env[++i])
	{
		j = i;
		while (env[++j])
		{
			if (ft_envcpm(env[i], env[j]) > 0)
				ft_swap(&env[i], &env[j]);
		}
	}
	// return (env);
}

// int	sort_env(char **str)
// {
// 	int		i;
// 	int		j;

// 	i = -1;
// 	// str[i] = ft_strtrim(str, "=");
// 	while (str[++i])
// 	{
// 		j = -1;
// 		while (str[++j])
// 		{
// 			if (ft_strncmp(str[i], str[j], ft_min_len(str[i], str[j])) > 0)
// 				ft_swap(&str[i], &str[j]);
// 		}
// 	}
// }

// size_t	ft_len_trim(char *str, char trm)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len] != trm && str[len] != 0)
// 		len++;
// 	return (len);
// }

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
	// int		j;
	char	**new;

	// (void) str;
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
	{

		return (ft_strncmp(s1, s2, ft_min_len(s1, s2)));
	}
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

