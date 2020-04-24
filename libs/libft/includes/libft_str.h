/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:06:13 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 19:16:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

# include <string.h>

# include "libft_macroses.h"

/*
**	Free memory for string and set \param as to NULL.
**	\param as pointer to string.
*/
extern void
ft_strdel(char *restrict *restrict as);

/*
**	Reverse string \param str.
*/
void
ft_strrev(char *restrict str);

/*
**	Replace all \param s symbols in string \param str to \param r.
*/
void
ft_strrepchr(char *str, int s, int r);

/*
**	Compare string \param s1 with \param s2.
**	\return difference of not matching symbols or 0 if strings equal.
*/
int
ft_strcmp(const char *s1, const char *s2);

/*
**	Compare string \param s1 with \param s2 by \param n symbols.
**	\return difference of not matching symbols or 0 if strings equal.
*/
int
ft_strncmp(const char *s1, const char *s2, size_t n);

/*
**	\return length of string \param str.
*/
size_t
ft_strlen(const char *restrict str);
/*
**	\return length of string \param str.
*/
size_t
ft_strnlen(const char *restrict str, size_t max_len);

/*
**	\return converted string \str alphabet symbols to lower case.
*/
char
*ft_strlwr(char *restrict str);

/*
**	\return converted string \str alphabet symbols to upper case.
*/
char
*ft_strupr(char *restrict str);

/*
**	\return new allocated copy string \param src
**	 or NULL if something went wrong.
*/
extern char
*ft_strdup(const char *restrict src);

/*
**	\return new allocated copied \param n symbols from string \param src
**	 or NULL if something went wrong.
*/
extern char
*ft_strndup(const char *restrict s1, size_t n);

/*
**	Copy string \param str to \param dest.
**	\return \param dest.
*/
char
*ft_strcpy(char *restrict dest, const char *restrict str);

/*
**	Copy \param len of string \param src to string \param dest.
**	\return \param dest.
*/
char
*ft_strncpy(char *restrict dest, const char *restrict src, size_t len);

/*
**	Appends string \param src to \param dest.
**	\return \param dest.
*/
char
*ft_strcat(char *restrict dest, const char *restrict src);

/*
**	Appends \param n symbols from string \param src to \param dest.
**	\return \param dest.
*/
char
*ft_strncat(char *restrict dest, const char *restrict src, size_t n);

/*
** \return a pointer to the first occurrence of the character \param c
**	 in the string \param s.
*/
char
*ft_strchr(const char *str, char c);


/*
** \return a pointer to the first occurrence of the character \param c
**	 in the string \param s.
*/
char
*ft_strchrnul(const char *str, char c);


/*
**	\return a pointer to the last occurrence of the character \param c
**	 in the string \param s
*/
char
*ft_strrchr(char *restrict s, int c);

/*
** \return the first occurrence of the substring \param to_find
**  in the string \param str.
*/
char
*ft_strstr(char *restrict str, char *restrict to_find);

/*
** \return the first occurrence of the null-terminated string
**	 \param to_find in the string \param str,
**	 where not more than \param len characters are searched.
*/
char
*ft_strnstr(char *str, const char *restrict to_find, size_t len);

/*
**	\return allocate null-terminated string.
*/
extern char
*ft_strnew(size_t size);

/*
**	\return allocate a “fresh” substring from the string \param s argument.
**	 The substring begins at index \param start and is of size \param len.
**	 If \param start and \param len aren’t refering to a valid substring,
**	 the behavior is undefined. If the allocation fails, returns NULL.
*/
extern char
*ft_strsub(const char *restrict s, size_t start, size_t len);

/*
**	\return allocate a “fresh” string ending with ’\0’,
**	 result of the concatenation of \param s1 and \param s2.
**	 If the allocation fails the function returns NULL.
*/
extern char
*ft_strjoin(const char *restrict s1, const char *restrict s2);

/*
**	\return allocate a copy of the string \param s without whitespaces
**	 at the beginning and at the end of the string.
**	 Will be considered as whitespaces all the ASCII codes from 9 to 13 and 32.
**	 If \param s has no whitespaces at the beginning or at the end,
**	 the function returns a copy of \param s.
**	 If the allocation fails the function returns NULL.
*/
char
*ft_strtrim(const char *restrict s);

/*
**	\return dst with trimmed string \param s without whitespaces
**	 at the beginning and at the end of the string.
**	 Will be considered as whitespaces all the ASCII codes from 9 to 13 and 32.
**	 If \param s has no whitespaces at the beginning or at the end,
**	 the function just copy \param s to \param dst.
**	 If the \paramd dst not allocated undefined behavior exepted.
*/
char
*ft_strtrimcpy(char *dst, const char *s);

/*
** \return allocate an array of “fresh” strings (all ending with ’\0’,
**	 including the array itself) obtained by spliting \param s
**	 using the character \param c as a delimiter.
**	 If the allocation fails the function returns NULL.
*/
char
**ft_strsplit(char *s, int c);

/*
**	Convert string \param str to double type.
**	\return 0.0 if string \param str is invalid,
**	 else - number which contained in string
*/
double
ft_atof(const char *str);

/*
**	Convert string \param str to int type.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string.
*/
int
ft_atoi(const char *restrict str);

/*
**	Convert string \param str to long number.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string.
*/
long
ft_atol(const char *str);

/*
**	Convert string \param str to int number in \param base notation.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string converted in \param base notation.
*/
int
ft_atoi_base(const char *str, int8_t base);

/*
**	\return convert number \param n to string in \param base number system.
*/
char
*ft_ltoa_base(long value, uint8_t base);

/*
**	\return convert number \param n to string.
*/
char
*ft_itoa(int n);

/*
**	\return convert number \param n to string.
*/
char
*ft_ltoa(long n);

/*
**	\return convert number \param num to \param dst string
**	 in \param radix notation.
*/
char
*ft_ultoa(unsigned long num, char *restrict dst, int base);

#endif
