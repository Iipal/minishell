/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:24:50 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 19:14:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long n)
{
	size_t	n_len;
	char	tmp[24];
	bool	is_neg;

	is_neg = false;
	n_len = ft_digits(n);
	ft_bzero(tmp, sizeof(tmp));
	if (0L > n)
	{
		tmp[is_neg] = '-';
		is_neg = true;
		n = -n;
	}
	while (is_neg != n_len--)
	{
		tmp[n_len] = (n % 10L) + 0x30L;
		if (n)
			n /= 10L;
	}
	ft_putstr(tmp);
}
