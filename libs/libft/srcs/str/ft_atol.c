/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 19:12:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	num;
	long	sign;

	num = 0L;
	str += ft_strnblank(str);
	sign = ('-' == *str) ? -1L : 1L;
	if ('-' == *str || '+' == *str)
		++str;
	while (F_ISDIGIT(*str))
		num = num * 0xAL + *(str++) - 0x30L;
	return (num * sign);
}
