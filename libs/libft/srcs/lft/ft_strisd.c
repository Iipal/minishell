/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigits_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:10:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 20:48:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strisd(const char *restrict str)
{
	size_t	i;

	i = ~0UL;
	while (str[++i])
		if (!F_ISDIGIT(str[i]))
			return (false);
	return (true);
}
