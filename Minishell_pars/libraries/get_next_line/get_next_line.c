/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:49:34 by mouassit          #+#    #+#             */
/*   Updated: 2019/12/29 06:35:05 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free(char **str, int i)
{
	free(*str);
	str = NULL;
	return (i);
}

int		ft_new(char **rus, char **line)
{
	char	*ptr;
	char	*tmp;

	ptr = NULL;
	if (*rus)
	{
		if ((ptr = ft_strchr(*rus, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(*rus);
			tmp = *rus;
			*rus = ft_strdup(++ptr);
			return (ft_free(&tmp, 0));
		}
		else
		{
			*line = ft_strdup(*rus);
			free(*rus);
			*rus = NULL;
			return (1);
		}
	}
	else
		*line = ft_strdup("");
	return (1);
}

int		ft_ret(char **buff, char *rus)
{
	free(*buff);
	if (rus != 0)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	char			*str[2];
	static	char	*rus;
	int				j;
	int				i;

	j = ft_new(&rus, line);
	if (!line || !(buff = (char*)malloc(BUFFER_SIZE + 1)) || fd < 0)
		return (-1);
	while (j && (i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		if ((str[0] = ft_strchr(buff, '\n')))
		{
			*str[0] = '\0';
			str[1] = rus;
			rus = ft_strdup(++str[0]);
			j = ft_free(&str[1], 0);
		}
		str[1] = *line;
		*line = ft_strjoin(*line, buff);
		free(str[1]);
	}
	return (ft_ret(&buff, rus));
}
