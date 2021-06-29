/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:51:19 by mouassit          #+#    #+#             */
/*   Updated: 2019/11/06 11:25:00 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_separator(char str, char c)
{
	return (str != c && str != '\n' && str != '\t');
}

int		ft_count_words(char *str, char c)
{
	int		i;
	int		in_word;
	int		count;

	i = 0;
	in_word = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == c || *str == '\n' || *str == '\t')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int		ft_word_length(char *str, int i, char c)
{
	int		length;

	length = 0;
	while (ft_separator(str[i], c) && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

void	*fr_ee(char **words, int j)
{
	while (j)
		free(words[j--]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(words = (char**)malloc(sizeof(char*) *
					(ft_count_words((char*)s, c) + 1))) || !s)
		return (0);
	while (s[i] != '\0' && j < ft_count_words((char*)s, c))
	{
		k = 0;
		while (s[i] == c || s[i] == '\n' || s[i] == '\t')
			i++;
		if (!(words[j] = (char*)malloc(sizeof(char) *
						ft_word_length((char*)s, i, c) + 1)))
			return (fr_ee(words, j));
		while (ft_separator(s[i], c) && s[i] != '\0')
			words[j][k++] = s[i++];
		words[j++][k] = '\0';
	}
	words[j] = 0;
	return (words);
}
