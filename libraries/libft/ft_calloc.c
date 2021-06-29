/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 00:19:04 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/02 14:11:59 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)malloc(count * size);
	if (!tab)
		return (NULL);
	while (i < count * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
