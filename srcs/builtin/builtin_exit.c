// void builtin_exit(t_main *main, t_cmd *cmd)
// {
// 	if (!cmd->command[1])
// 		exit(0);
// 	else
// 	{
// 		if (check_nbr(cmd->command[1]))
// 		{
// 			if (!cmd->command[2])
// 				exit(cal_exit_code(cmd->command[1]));
// 			else
// 				error_msg_exit(cmd->command[2]);
// 		}
// 		else
// 		{
// 			error_msg_exit(cmd->command[1], 1);
// 			exit(255);
// 		}

// }

// void error_msg_exit(char *msg, int err)
// {
// 	if (err == 1)
// 	{
// 		write(STDERR_FILENO, "mini(s)hell: exit: ", 19);
// 		write(STDERR_FILENO, msg, ft_strlen(msg));
// 		write(STDERR_FILENO, ": numeric argument required", 27);
// 	}
// 	if (err == 2)
// 		write(STDERR_FILENO, "mini(s)hell: exit: too many arguments", 19);
// }

// int	check_nbr(char *str)
// {
// 	int		i;
// 	int		nbr;

// 	nbr = 0;
// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		nbr = 1;
// 		i++;
// 	}
// 	if (nbr == 1 && str[i] == '\0')
// 		return (1);
// 	return (0);
// }
