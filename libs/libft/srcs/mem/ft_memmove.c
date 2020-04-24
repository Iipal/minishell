/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:43:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 20:56:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *restrict dest, const void *restrict src, size_t len)
{
	const __u_char	*sc = (const __u_char*)src;
	__u_char		*dst;
	size_t			i;
	ssize_t			slen;

	i = ~0UL;
	dst = (__u_char*)dest;
	slen = (ssize_t)len;
	if (sc < dst)
		while (0 <= (--slen))
			dst[slen] = sc[slen];
	else
		while (len > ++i)
			dst[i] = sc[i];
	return (dest);
}
