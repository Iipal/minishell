/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:58:29 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 19:16:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			s_count_words(const char *s, int c)
{
	size_t	words;
	bool	is_in_word;

	words = 0UL;
	is_in_word = *s == c;
	while (*s)
		if (!is_in_word)
		{
			while (*s && *s == c)
				++s;
			is_in_word = true;
			++words;
		}
		else
		{
			while (*s && *s != c)
				++s;
			is_in_word = false;
		}
	return (words);
}

char					**ft_strsplit(char *s, int c)
{
	char	**out;
	char	*tmp;
	size_t	words_count;
	size_t	i;

	words_count = s_count_words(s, c);
	out = (char**)ft_memalloc(sizeof(char*) * (words_count + 1));
	i = ~0UL;
	while (words_count > ++i)
	{
		if (!(tmp = ft_strchr(s, c)))
		{
			if (!(out[i] = ft_strdup(s)))
				return (NULL);
		}
		else if (!(out[i] = ft_strndup(s, tmp - s)))
			return (NULL);
		s = tmp;
		while (s && *s && *s == c)
			++s;
	}
	out[i] = NULL;
	return (out);
}
