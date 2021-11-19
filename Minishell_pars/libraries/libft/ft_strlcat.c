/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:56:36 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/04 21:12:34 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dest;
	size_t		str;
	size_t		i;
	size_t		j;

	if ((dst == NULL || size == 0) && size == 0)
		return (ft_strlen(src));
	i = 0;
	dest = ft_strlen(dst);
	str = ft_strlen((char*)src);
	if (size <= dest)
		i = str + size;
	else
	{
		i = str + dest;
		j = 0;
		while (src[j] && size > (dest + j + 1))
		{
			dst[dest + j] = src[j];
			j++;
		}
		dst[dest + j] = '\0';
	}
	return (i);
}
