/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:10:45 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/02 13:50:13 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rest;
	int		size;

	if (!s || !f)
		return (0);
	size = 0;
	while (s[size])
		size++;
	if (NULL == (rest = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (size > i)
	{
		rest[i] = f(i, s[i]);
		i++;
	}
	rest[i] = '\0';
	return (rest);
}
