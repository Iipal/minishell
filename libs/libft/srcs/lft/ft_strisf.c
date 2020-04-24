/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:02:20 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 20:50:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strisf(const char *restrict str)
{
	size_t	i;
	bool	dot;

	i = ~0UL;
	dot = false;
	while (str[++i])
	{
		if (!dot && '.' == str[i++])
			dot = true;
		if (!F_ISDIGIT(str[i]))
			return (false);
	}
	return (true);
}
