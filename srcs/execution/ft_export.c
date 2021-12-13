# include "../includes/minishell.h"

void print_exp(t_envp *head) {
    t_envp *current_node;
    
    current_node = head;

   	while (current_node != NULL)
    {
        ft_putstr_fd("declare -x ", 1);
        ft_putstr_fd(current_node->key, 1);
        if (current_node->equal)
        {
            ft_putstr_fd("=\"", 1);
            if (current_node->value)
                ft_putstr_fd(current_node->value, 1);
            ft_putstr_fd("\"", 1);
        }
        ft_putstr_fd("\n", 1);
        current_node = current_node->next;
    }
}

int		init_envp_node(t_envp **node)
{
	*node = malloc(sizeof(t_envp));
	(*node)->value = 0;
	(*node)->key = 0;
	(*node)->plus = 0;
	(*node)->equal = 0;
	return (0);
}
t_envp*	fill_envp(char *str)
{
	t_envp *node;

	init_envp_node(&node);
	if (ft_strchr(str, '='))
	{
		node->equal = 1;
		if (ft_strchr(str, '=') != str && *(ft_strchr(str, '=') - 1) == '+')
		{
			printf("HNAYA\n");
			node->key = ft_substr(str, 0, ft_indexof(str, '+'));
			node->plus = 1;
		}
		else
			node->key = ft_substr(str, 0, ft_indexof(str, '='));
		if (*(ft_strchr(str,'=') + 1))
			node->value = ft_strdup(ft_strchr(str,'=') + 1);
		else
			node->value = 0;
	}
	else
	{
		node->equal = 0;
		node->key = ft_strdup(str);
		node->value = 0;
		node->plus = 0;
	}
	node->next=NULL;
	return node;
}

int     env_key_error(char *var)
{
    int i;

    i = 1;
    if (!ft_isalpha(var[0]) && var[0] != '_')
        return (1);
    while (var[i])
    {
        if (!ft_isalnum(var[i]) && var[i] != '_')
		{

            return (1);
		}
        i++;
    }
    return(0);
}

void	env_replace(t_envp **tmp1, t_envp **node1)
{
	t_envp *tmp;
	t_envp *node;

	tmp = *tmp1;
	node = *node1;
	if (node->equal && node->plus)
	{
		printf("HAHOWA\n");
		tmp->equal = 1;
		if (node->value)
		{
			tmp->value = ft_free_first(tmp->value, ft_strjoin(tmp->value, node->value));
		}
	}
	else if (node->equal)
	{
		tmp->equal = 1;
		tmp->value = ft_free_first(tmp->value, ft_strdup_null(node->value));
	}
	free_envp(node);	
}

void	add_to_env(t_envp **head, t_envp *node)
{
	t_envp *tmp;

	tmp = (*head);
	if (tmp == NULL)
	{
		*head = node;
		return;
	}
	while (tmp != NULL)
	{
		if (!ft_strcmp(node->key, tmp->key))
		{
			env_replace(&tmp, &node);
			//free_envp(node);
			return ;
		}
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	tmp->next = node;
}

int		ft_export(t_data *data, t_envp **env_list)
{
    int i;
	t_envp *node;
	int		ret;

	ret = 0;
    i = 1;
    if (data->arguments[1] == NULL)
        print_exp(*env_list);
    else
    {
        while (data->arguments[i])
        {
            node = fill_envp(data->arguments[i]);
            if (env_key_error(node->key) || (node->equal == 0 && node->plus == 1))
			{
				// printf("%s\n", node->key);
                printf("bash: export: `%s`: not a valid identifier\n", data->arguments[i]);

				ret = 1;
			}
            else
                add_to_env(env_list, node);
            i++;
        }
    }
	return (ret);
}