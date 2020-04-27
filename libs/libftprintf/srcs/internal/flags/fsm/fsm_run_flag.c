/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_run_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:17 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 22:17:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
#include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline bool __attribute__((always_inline))
	fsm_strchr(const char *restrict str, char ch)
{
	size_t	i;

	i = ~0UL;
	while (str && str[++i] && str[i] != ch)
		;
	return (str[i] == ch);
}

inline bool __attribute__((always_inline))
	fsm_run_flag(struct s_lpf_buf_ *restrict buf,
		struct s_lpf_flag_ *restrict flag,
		va_list ap)
{
	static const struct s_fsm_cmp	callback_table[8] = {
		[fsm_flag_none] = { NULL, flag_none },
		[fsm_flag_di] = { "di", flag_di },
		[fsm_flag_s] = { "s", flag_s },
		[fsm_flag_c] = { "c%", flag_c },
		[fsm_flag_u] = { "u", flag_u },
		[fsm_flag_p] = { "p", flag_p },
		[fsm_flag_o] = { "o", flag_o },
		[7] = { NULL, NULL }
	};
	enum e_fsm_flag_state			fn_i;
	size_t							i;

	i = 0UL;
	while (callback_table[++i].ch)
		if (fsm_strchr(callback_table[i].ch, flag->symbol))
			break ;
	if (callback_table[i].ch)
		if (!(callback_table[i].fnptr(buf, flag, ap)))
		{
			write(STDERR_FILENO, E_PF_INVALID, sizeof(E_PF_INVALID) - 1);
			return (false);
		}
	return (true);
}
