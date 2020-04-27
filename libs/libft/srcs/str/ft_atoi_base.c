/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:46:01 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 21:45:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool
	add_is_valid(char const c, int8_t base, char const valid[24])
{
	while (base--)
		if (valid[base] == F_TOLOWER(c))
			return (true);
	return (false);
}

static inline int __attribute__((__always_inline__))
	add_value_of(const char c)
{
	int	out;

	out = 0;
	if (F_ISDIGIT(c))
		out = c - 0x30;
	else if (F_ISLOWER(c))
		out = c - 0x61 + 0xA;
	else if (F_ISUPPER(c))
		out = c - 0x41 + 0xA;
	return (out);
}

int
	ft_atoi_base(const char *str, int8_t base)
{
	int			num;
	int8_t		sign;
	const char	valid_hex[24] = "0123456789abcdef";

	num = 0;
	str += ft_strnblank(str);
	sign = (*str == '-') ? -1 : 1;
	if ('-' == *str || '+' == *str)
		++str;
	while (add_is_valid(*str, base, valid_hex))
		num = num * base + add_value_of(*str++);
	return (num * sign);
}
