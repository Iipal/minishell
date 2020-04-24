/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:26:18 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 06:34:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LIBFT_INTERNAL
#include "libft_internal.h"
#undef LIBFT_INTERNAL

char	*ft_strtrim(const char *restrict s)
{
	return (ft_strsub(s, ft_strnblank(s), lfti_strtrim_base(s)));
}
