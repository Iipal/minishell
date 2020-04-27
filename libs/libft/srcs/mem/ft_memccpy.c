/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:45 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 18:45:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest,
			const void *restrict src,
			uint8_t c,
			size_t n)
{
	const unsigned char	*sc = (const unsigned char*)src;
	unsigned char		*dst;
	size_t				i;

	dst = (__u_char*)dest;
	i = ~0UL;
	while (n > ++i)
	{
		dst[i] = sc[i];
		if (sc[i] == c)
			return (dst + i + 1);
	}
	return (NULL);
}
