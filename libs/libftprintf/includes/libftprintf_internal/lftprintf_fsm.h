/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_fsm.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:45:43 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 22:15:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_FSM_H
# define LFTPRINTF_FSM_H

# ifndef LIBFTPRINTF_INTERNAL_H
#  error "include only libftprintf.h"
# endif

# include <stdbool.h>

# include "lftprintf_structs.h"

enum	e_fsm_flag_state
{
	fsm_flag_none,
	fsm_flag_di,
	fsm_flag_s,
	fsm_flag_c,
	fsm_flag_u,
	fsm_flag_p,
	fsm_flag_o,
} __attribute__((packed));

struct	s_fsm_cmp
{
	const char *restrict	ch;
	t_fsm_callback			fnptr;
};

typedef bool (*t_fsm_callback)(struct s_lpf_buf_ *restrict,
					struct s_lpf_flag_ *restrict, va_list);

extern bool
fsm_run_flag(struct s_lpf_buf_ *restrict buf,
			struct s_lpf_flag_ *restrict flag,
						va_list ap);

extern bool
flag_none(struct s_lpf_buf_ *restrict __attribute__((unused)) buf,
			struct s_lpf_flag_ *restrict __attribute__((unused)) flag,
						va_list __attribute__((unused)) ap);
extern bool
flag_di(struct s_lpf_buf_ *restrict buf,
	struct s_lpf_flag_ *restrict flag,
	va_list ap);
extern bool
flag_s(struct s_lpf_buf_ *restrict buf,
	struct s_lpf_flag_ *restrict flag,
	va_list ap);
extern bool
flag_c(struct s_lpf_buf_ *restrict buf,
	struct s_lpf_flag_ *restrict flag,
	va_list ap);
extern bool
flag_p(struct s_lpf_buf_ *restrict buf,
	struct s_lpf_flag_ *restrict flag,
	va_list ap);
extern bool
flag_o(struct s_lpf_buf_ *restrict buf,
	struct s_lpf_flag_ *restrict flag,
	va_list ap);
extern bool
flag_u(struct s_lpf_buf_ *restrict buf,
	struct s_lpf_flag_ *restrict flag,
	va_list ap);

#endif
