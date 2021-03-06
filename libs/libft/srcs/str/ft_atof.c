/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:03:55 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 19:15:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	add_mnt_delimeter(size_t mnt_digits)
{
	double	out;

	out = 1.0;
	while (mnt_digits--)
		out *= 10.0;
	return (out);
}

double			ft_atof(const char *str)
{
	const long	exp = ft_atol(str);
	long		mnt;
	size_t		mnt_digits;
	size_t		i;
	double		s;

	i = ~0UL;
	mnt = 0UL;
	mnt_digits = 0UL;
	s = ('-' == *str) ? -1.0 : 1.0;
	((!exp) && (0.0 > s)) ? ++str : str;
	str += ft_digits(exp);
	if ('.' == *str++)
	{
		while (str[++i] && F_ISDIGIT(str[i]))
			++mnt_digits;
		mnt = ft_atol(str);
		if (ft_digits(mnt) > mnt_digits)
			mnt_digits = 0UL;
		else
			mnt_digits -= ft_digits(mnt);
	}
	return (exp + (mnt / add_mnt_delimeter(ft_digits(mnt) + mnt_digits) * s));
}
