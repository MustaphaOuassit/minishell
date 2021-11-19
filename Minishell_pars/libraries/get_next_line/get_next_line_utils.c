/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:44:55 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/15 15:44:46 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		size(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		ls1;
	int		ls2;
	int		i;

	if ((s1 == 0) || (s2 == 0))
		return (0);
	ls1 = size((char*)s1);
	ls2 = size((char*)s2);
	i = 0;
	if (NULL == (ret = malloc(sizeof(char) * (ls1 + ls2 + 1))))
		return (0);
	while (s1[i])
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		*(ret + i + ls1) = *(s2 + i);
		i++;
	}
	*(ret + i + ls1) = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char*)(s + i));
		}
		i++;
	}
	if (s[i] == c)
		return ((char*)(s + i));
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char		*dst;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	dst = (char*)malloc(sizeof(*dst) * (i + 1));
	if (!dst)
		return (NULL);
	while (s1[j])
	{
		dst[j] = s1[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
