/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:17:58 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 18:46:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *restrict dest, int c, size_t len)
{
	unsigned char	*out;

	out = (unsigned char*)dest;
	while (len--)
		*out++ = (unsigned char)c;
	return (dest);
}
