/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 05:29:09 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/03 20:26:38 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dest;
	const char		*str;

	if (!dst && !src)
		return (0);
	dest = dst;
	str = src;
	i = 0;
	if (ft_memcmp(dst, src, n) == 0)
		return (dst);
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
