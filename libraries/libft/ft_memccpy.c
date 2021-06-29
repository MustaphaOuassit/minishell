/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:57:33 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/04 21:10:41 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned const char		*src2;
	unsigned char			*dst2;
	size_t					j;

	i = 0;
	j = 0;
	src2 = src;
	dst2 = dst;
	if ((dst2 == NULL || src2 == NULL) && n == 0)
		return (0);
	while (src2[i] != '\0' && src2[i] != (unsigned char)c && i < n)
		i++;
	if (src2[i] != (unsigned char)c)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	while (j <= i)
	{
		dst2[j] = src2[j];
		j++;
	}
	return (dst + j);
}
