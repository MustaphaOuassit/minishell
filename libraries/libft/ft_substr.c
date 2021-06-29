/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:47:39 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/04 20:24:34 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		l;

	if (!s || start > ft_strlen((char*)s))
	{
		ret = (char*)malloc(sizeof(1));
		*ret = '\0';
		return (ret);
	}
	l = 0;
	if (NULL == (ret = (char*)malloc(len + 1)))
		return (0);
	while (l < (int)(len))
	{
		ret[l] = s[start];
		l++;
		start++;
	}
	ret[l] = '\0';
	return (ret);
}
