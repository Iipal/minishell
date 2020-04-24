/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntoblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:43:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 20:49:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strntoblank(const char *restrict str)
{
	size_t	i;

	i = ~0UL;
	while (str[++i] && !F_ISBLANK(str[i]))
		;
	return (i);
}
