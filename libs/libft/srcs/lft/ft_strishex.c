/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:23:15 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 19:13:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool __attribute__((__overloadable__))
	ft_strishex(const char *restrict s)
{
	size_t		i;
	const char	*str = (const char*)s;
	const char	valid_hex[24] = "0123456789abcdef";

	while (*str)
	{
		i = ~0UL;
		while (valid_hex[++i])
			if (F_TOLOWER(*str) == valid_hex[i])
				break ;
		if (F_TOLOWER(*str) != valid_hex[i])
			return (false);
		++str;
	}
	return (true);
}

bool __attribute__((__overloadable__))
	ft_strishex(const char *restrict s, size_t n)
{
	size_t		i;
	const char	*str = (const char*)s;
	const char	valid_hex[24] = "0123456789abcdef";

	while (n--)
	{
		i = ~0UL;
		while (valid_hex[++i])
			if (F_TOLOWER(*str) == valid_hex[i])
				break ;
		if (F_TOLOWER(*str++) != valid_hex[i])
			return (false);
	}
	return (true);
}
