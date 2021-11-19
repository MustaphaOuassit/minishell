/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:54:16 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/02 13:58:50 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_anv(char *s1, char *set)
{
	int		j;
	int		i;

	j = 0;
	while (s1[j] != '\0')
		j++;
	j--;
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1[j])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

char	*setdata(char *s1, int j, int start)
{
	int		index;
	char	*res;

	index = 0;
	if (j < 0)
		return (ft_strdup("\0"));
	if (NULL == (res = (char*)malloc(sizeof(char) * (j - start + 2))))
		return (0);
	while (index < j - start + 1)
	{
		res[index] = *(s1 + start + index);
		index++;
	}
	res[index] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup((char*)s1));
	i = 0;
	start = 0;
	while (*(set + i) != '\0')
	{
		if (set[i] == s1[start])
		{
			start++;
			i = 0;
		}
		else
			i++;
	}
	if (start == (int)ft_strlen((char*)s1))
		return (ft_strdup("\0"));
	return (setdata((char*)s1, ft_anv((char*)s1, (char*)set), start));
}
