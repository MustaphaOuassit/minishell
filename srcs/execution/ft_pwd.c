# include "../includes/minishell.h"

int		ft_pwd()
{
	char buf[100];

	printf("%s\n",getcwd(buf, sizeof(buf)));
	return (0);
}
