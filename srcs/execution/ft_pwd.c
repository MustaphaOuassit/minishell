# include "../includes/minishell.h"

int		ft_pwd()
{
	char cwd[PATH_MAX];

	printf("%s\n",getcwd(cwd, sizeof(cwd)));
	return (0);
}
