# include "../includes/minishell.h"

void print_env(t_envp **head)
{
    t_envp *current_node = (*head);
   	while ( current_node != NULL)
    {
        if (current_node->equal)
        {

            ft_putstr_fd(current_node->key, 1);
            ft_putstr_fd("=", 1);
        }
        if (current_node->value)
            ft_putstr_fd(current_node->value, 1);
        ft_putstr_fd("\n", 1);
        current_node = current_node->next;
    }
}

int		ft_env(t_data *data, t_envp **env_list)
{
    (void) data;
    print_env(env_list);
	return (0);
}

int		fetch_fd(t_redirection *red, int *fd)
{
	t_redirection *tmp;


	fd[0] = 0;
	fd[1] = 1;
	tmp = red;
	while (tmp != NULL)
	{
		if (tmp->type == 0)
		{
			exit(0);
			//if (tmp->file_name)
			fd[0] = open(tmp->file_name, O_RDONLY);
			if (fd[0] == -1)
				return (1);
		}
		if (tmp->type == 1)
		{
			//if (tmp->file_name)
			fd[1] = open(tmp->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
			if (fd[1] == -1)
				return (1);
		}

		tmp = tmp->next;
	}
	return (0);
}


char	*fetch_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	return (envp[i]);
}

void	error_command(char	*str)
{
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(" : command not found\n", 2);
	exit(127);
}

char	*fetch_pathname(char	*cmd,	char	**envp)
{
	char	**path;
	char	*pathname;
	int		i;

	i = 0;

	if (!cmd)
		error_command(NULL);
	if (access(cmd, F_OK) == 0 && cmd[0] == '/')
		return (ft_strdup(cmd));
	path = ft_split(fetch_env_path(envp), ':');
	path[0] = ft_free_first(path[0], ft_strdup(ft_strrchr(path[0], '=') + 1));
	while (path[i])
	{
		pathname = ft_strjoin_char(path[i], cmd, '/');
		if (access(pathname, F_OK) == 0)
			break ;
		i++;
		free(pathname);
		if (path[i] == 0)
			error_command(cmd);
	}
	ft_free_split(path);
	return (pathname);
}

void	ft_execute(char **args, int *fd, char **envp)
{
	char *path;


	if (args[0][0] == '/' || !ft_strncmp(args[0], "./", 2))
		path = ft_strdup(args[0]);
	else
		path = fetch_pathname(args[0], envp);
	printf("fd[1]=%d\n", fd[1]);
	if (fd[0] != 0)
		dup2(fd[0], STDIN_FILENO);
	if (fd[1] != 1)
	{
		dup2(fd[1], STDOUT_FILENO);
	}
	execve(path, args, envp);
	perror("");
	exit(127);
}

int		exec_cmd(t_data *data, char **envp)
{

	//int pipe_fd[2];
	int fork_id[2];
	int fd[2];
	fork_id[0] = fork();
	if (fork_id[0] == 0)
	{
		if (fetch_fd(data->redirection, fd) == 1)
			return (1);
		ft_execute(data->arguments, fd, envp);
	}
	else
		wait(NULL);
	return (0);
}
