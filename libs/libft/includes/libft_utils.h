/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:09:12 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 19:16:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <string.h>
# include <stdint.h>

# include "libft_macroses.h"

/*
**	Reading file line by line. (Get Next Line)
**	\param fd: File descriptor.
**	\param line: pointer to string where will saved each line from file.
**	\return:
**	[0 - End of File.
**	 1 - Successful read 1 line from file.
**	 -1 - Reading error.]
*/
int
ft_gnl(int fd, char *restrict *restrict line);

/*
**	Compare if one of \param n va_list arguments is equal to \param cmp.
**	\param cmp: Value to compare.
**	\param n: va_list arguments counter to compare.
**	\param ...: va_list.
**	\return true if one of argument is equal to \param cmp, else - false.
*/
size_t __attribute__((__overloadable__))
ft_is_one_of_n(char cmp, size_t n, ...);
size_t __attribute__((__overloadable__))
ft_is_one_of_n(int cmp, size_t n, ...);
size_t __attribute__((__overloadable__))
ft_is_one_of_n(long cmp, size_t n, ...);
size_t __attribute__((__overloadable__))
ft_is_one_of_n(char *restrict cmp, size_t n, ...);
size_t __attribute__((__overloadable__))
ft_is_one_of_n(char *restrict cmp, size_t cmp_len, size_t n, ...);

/*
**	\return How many digits in \param n.
*/
# ifdef __x86_64__
size_t __attribute__((__overloadable__))
ft_digits(unsigned int n);
# endif

size_t __attribute__((__overloadable__))
ft_digits(long n);
size_t __attribute__((__overloadable__))
ft_digits(int n);
size_t __attribute__((__overloadable__))
ft_digits(size_t n);

/*
**	\return How many digits in \param str.
**	If in string exist mantissa(data after .(dot) and actually .(dot))
**	 the function will return number of digits including this .(dot).
*/
size_t
ft_strfn(const char *str);

/*
**	\return true is \param str contain only digits or false if not.
*/
bool
ft_strisd(const char *restrict str);

/*
**	\return true is \param str contain only digits and valid float value
**	 or false if not.
*/
bool
ft_strisf(const char *restrict str);

/*
**	\return true is \param str contain only hex digits or false if not.
*/
bool __attribute__((__overloadable__))
ft_strishex(const char *restrict str);
bool __attribute__((__overloadable__))
ft_strishex(const char *restrict str, size_t n);

/*
**	\return true is \param str contain only hex digits or false if not.
*/
bool
ft_strisa(const char *restrict str);

/*
**	\return How many blanks skips in string \param str.
*/
size_t
ft_strnblank(const char *restrict str);

/*
**	\return How many symbols to first blank symbol in string \param str.
*/
size_t
ft_strntoblank(const char *restrict str);

/*
**	Randomize unsigned decimal number.
**	\param limits: Max random number.
**	\return random: number from 0 to \ref limits.
*/
extern size_t
ft_rand(size_t limit);

extern void __attribute__((__overloadable__))
ft_swap(char *restrict a,
		char *restrict b);

extern void __attribute__((__overloadable__))
ft_swap(short *restrict a,
		short *restrict b);

extern void __attribute__((__overloadable__))
ft_swap(int *restrict a,
		int *restrict b);

extern void __attribute__((__overloadable__))
ft_swap(long *restrict a,
		long *restrict b);


extern void __attribute__((__overloadable__))
ft_swap(unsigned char *restrict a,
		unsigned char *restrict b);

extern void __attribute__((__overloadable__))
ft_swap(unsigned short *restrict a,
		unsigned short *restrict b);

extern void __attribute__((__overloadable__))
ft_swap(unsigned int *restrict a,
		unsigned int *restrict b);

extern void __attribute__((__overloadable__))
ft_swap(unsigned long *restrict a,
		unsigned long *restrict b);


#endif
