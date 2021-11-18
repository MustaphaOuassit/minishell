/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_couts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <mouassit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:18:45 by mouassit          #+#    #+#             */
/*   Updated: 2021/09/07 14:09:27 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/parsing.h"

int	check_couts(t_tokens **head, int indice)
{
	if (g_cmd[indice] == '"')
		indice = add_to_string_double(head,indice + 1, "\"'");
		
	else if (g_cmd[indice] == '\'')
		indice = add_to_string(indice + 1, "\"'");
	return (indice);
}

char	*continue_check(int len, int sword)
{
	int		j;
	char	*ptr;

	j = 0;
	ptr = NULL;
	if (len > 0)
	{
		j = 0;
		ptr = (char *)malloc((len + 1) * sizeof(char));
		while (sword != len)
		{
			ptr[j] = g_cmd[sword];
			sword++;
			j++;
		}
		ptr[j] = '\0';
	}
	return (ptr);
}
