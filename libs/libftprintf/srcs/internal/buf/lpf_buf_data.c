/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf_buf_data_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:55:40 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 21:55:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
#include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline void __attribute__((__overloadable__))
	lpf_buf_data_(struct s_lpf_buf_ *restrict buf,
		struct s_lpf_data_ *restrict data)
{
	size_t	i;

	i = ~((size_t)0);
	while (data->len > ++i)
		lpf_buf_ch_(buf, data->ptr[i]);
}

inline void __attribute__((__overloadable__))
	lpf_buf_data_(struct s_lpf_buf_ *restrict buf,
		struct s_lpf_data_ *restrict data,
		size_t len)
{
	size_t	i;

	i = ~((size_t)0);
	if (len > data->len)
		len = data->len;
	while (len > ++i)
		lpf_buf_ch_(buf, data->ptr[i]);
}

inline void __attribute__((__overloadable__))
	lpf_buf_data_(struct s_lpf_buf_ *restrict buf,
		const char *restrict str,
		size_t len)
{
	size_t	i;

	i = ~((size_t)0);
	while (len > ++i)
		lpf_buf_ch_(buf, str[i]);
}
