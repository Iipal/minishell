/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf_ltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:22:22 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 22:23:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
#include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

char	*lpf_ultoap_base(unsigned long num, char *restrict dst, int base)
{
	char	*temp;
	long	digit;
	long	i;
	long	j;
	bool	dowhile_reducer;

	dowhile_reducer = true;
	temp = (char[24]) { 0 };
	i = 0L;
	digit = 0L;
	j = 0L;
	while (num > 0 || dowhile_reducer)
	{
		dowhile_reducer = false;
		digit = num % base;
		if (digit < 10L)
			temp[i++] = digit + '0';
		else
			temp[i++] = digit - 10 + 'A';
		num /= (unsigned long)base;
	}
	--i;
	while (i >= 0L)
		dst[j++] = temp[i--];
	return (dst);
}
