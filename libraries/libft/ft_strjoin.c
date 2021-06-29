/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:19:04 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/02 13:48:57 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size(char *str)
{
	int	i;

	i = 0;
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
