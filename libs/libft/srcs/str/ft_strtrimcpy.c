/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:38:01 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 06:33:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LIBFT_INTERNAL
#include "libft_internal.h"
#undef LIBFT_INTERNAL

inline char	*ft_strtrimcpy(char *dst, const char *s)
{
	const size_t	sub_length = lfti_strtrim_base(s);

	ft_strncpy(dst, s, sub_length)[sub_length] = 0;
	return (dst);
}
