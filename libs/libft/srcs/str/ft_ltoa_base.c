/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:07:31 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 21:45:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_aux(long n, long b,
				char *restrict out,
				long *restrict p)
{
	const char	base[24] = "0123456789ABCDEF";

	if (n <= -b || b <= n)
		add_aux(n / b, b, out, p);
	out[(*p)++] = base[ABS(n % b)];
}

char		*ft_ltoa_base(long value, uint8_t base)
{
	char	*out;
	long	p;

	p = 0L;
	if (2 > base || 16 < base)
		return (NULL);
	out = (char*)ft_memalloc(sizeof(char) * 35L);
	if (10 == base && 0L > value)
		out[p++] = '-';
	add_aux(value, base, out, &p);
	out[p] = '\0';
	return (out);
}
