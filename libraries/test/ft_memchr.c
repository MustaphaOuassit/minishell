/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:03:54 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/02 18:25:44 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*src;
	size_t		i;

	src = (char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == c)
			return ((char*)(src + i));
		i++;
	}
	return (0);
}
