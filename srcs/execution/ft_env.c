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

	tmp = red;
	while (tmp != NULL)
	{
		//printf("TEST\n");
		if (tmp->type == REDIRECT_IN)
		{
			//if (tmp->file_name)
			fd[0] = open(tmp->file_name, O_RDONLY);
			if (fd[0] == -1)
				return (1);
		}
		if (tmp->type == REDIRECT_OUT)
		{
			//if (tmp->file_name)
			fd[1] = open(tmp->file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
			if (fd[1] == -1)
				return (1);
		}
		if (tmp->type == APPEND_OUT)
		{
			//if (tmp->file_name)
			fd[1] = open(tmp->file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
			if (fd[1] == -1)
				return (1);
		}
		printf("filename = %s\n", tmp->file_name);
		printf("type = %d\n", tmp->type);
		tmp = tmp->next;
	}
	return (0);
}


int		fetch_env_path(char **path, t_envp **env_list)
{
	t_envp *tmp;

	tmp = *env_list;

	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, "PATH") == 0)
		{
			if (tmp->value == 0)
				return (1);
			*path = ft_strdup_null(tmp->value);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	error_command(char	*str)
{
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(" : command not found\n", 2);
	exit(127);
}

int		fetch_pathname(char **pathname, char	*cmd, t_envp **env_list)
{
	char	*path;
	char **path_tab;
	int		i;

	i = 0;

	// if (!cmd)
	// 	error_command(NULL);
	// if (access(cmd, F_OK) == 0 && cmd[0] == '/')
	// 	return (ft_strdup(cmd));
	if (fetch_env_path(&path, env_list) == 1)
	{
		ft_putstr_fd("bash: ",2);
		ft_putstr_fd(cmd,2);
		ft_putstr_fd(" No such fle or directory\n",2);
		return (127);
	}// no path
	path_tab = ft_split(path, ':');
	//path[0] = ft_free_first(path[0], ft_strdup(ft_strrchr(path[0], '=') + 1));
	while (path_tab[i])
	{
		*pathname = ft_strjoin_char(path_tab[i], cmd, '/');
		if (access(*pathname, F_OK) == 0)
			break ;
		i++;
		free(*pathname);
		if (path[i] == 0)
			error_command(cmd);
	}
	ft_free_split(path_tab);
	return (0);
}
size_t	env_list_len(t_envp **env_list)
{
	size_t i;
	t_envp *tmp;

	i = 0;
	tmp = *env_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char ** convert_list_to_envp(t_envp **env_list)
{
	t_envp *tmp;
	int i;
	char **envp;

	tmp = *env_list;
	i = 0;
	envp = malloc(sizeof(t_envp*) * (env_list_len(env_list) + 1));
	while (tmp)
	{
		if (tmp->equal == 0)
			envp[i] = ft_strdup(tmp->key);
		else
		{
			envp[i] = ft_strjoin(tmp->key, "=");
			if (tmp->value)
			{
				envp[i] = ft_free_first(envp[i], ft_strjoin(envp[i], tmp->value));
			}
			//printf("%s\n", envp[i]);
		}
		i++;
		tmp = tmp->next;
	}
	envp[i] = 0;
	return (envp);
}

void ft_dup(int *fd)
{
	if (fd[0] != 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	if (fd[1] != 1)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}	
}
int		ft_execute(char **args, int *fd, t_envp **env_list)
{
	char *pathname;
	int ret;

	ret = 127;
	ft_dup(fd);
	if (args[0][0] == '/' || !ft_strncmp(args[0], "./", 2))
		pathname = ft_strdup(args[0]);
	else
	{
		ret = fetch_pathname(&pathname, args[0], env_list);
		if (ret != 0)
			return (ret);
	}
	//printf("fd[1]=%d\n", fd[1]);
	
	execve(pathname, args, convert_list_to_envp(env_list));
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(args[0], 2);
	perror(" ");
	return (127);
	//exit(123);
}
int		ft_pipeline(t_data *data, t_envp **env_list)
{

	int pipe_fd[2];
	int pid;
	int fd[2];
	int tmp_fd;
	int status;
	
	tmp_fd = 0;
	while (data)
	{
		fd[0] = 0;
		fd[1] = 1;
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			//child_process function : declare fd inside it
			fd[0] = tmp_fd;
			if (data->next != NULL)
				fd[1] = pipe_fd[1];
			if (fetch_fd(data->redirection, fd) == 1)
				return (1);
			//printf("TEST\n");
			if (is_builtin(data->arguments[0]))
			{
				ft_dup(fd);
				exit(ft_builtins(data, env_list));
			}
			exit(ft_execute(data->arguments, fd, env_list));		
		}
		else
		{

			close(pipe_fd[1]);
			tmp_fd = pipe_fd[0];
		}
		data = data->next;
	}
	waitpid(pid, &status, WUNTRACED | WCONTINUED);
	//while(waitpid(pid, &status, WUNTRACED | WCONTINUED) != -1)
	//;
	// if (WIFEXITED(status)) 
	// 	printf("exited, status=%d\n", WEXITSTATUS(status));
	return (WEXITSTATUS(status));
}
