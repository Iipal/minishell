/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:04:22 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 18:45:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *restrict ptr, int c, size_t n)
{
	const unsigned char	*out = (const unsigned char*)ptr;
	size_t				i;

	i = ~0UL;
	while (n--)
		if (out[++i] == c)
			return ((void*)(out + i));
	return (NULL);
}
