/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 00:27:43 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/01 21:30:42 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
