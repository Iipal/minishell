/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfti_strtrim_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:42:02 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 02:47:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LIBFT_INTERNAL
#include "libft_internal.h"
#undef LIBFT_INTERNAL

size_t	lfti_strtrim_base(const char *restrict s)
{
	size_t	start;
	size_t	len;

	start = ft_strnblank(s);
	if (!s[start])
		return (0UL);
	len = ft_strlen(s) - 1UL;
	while (--len > 0UL && F_ISBLANK(s[len]))
		;
	return (len - start + 1UL);
}
