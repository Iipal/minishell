/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:40:28 by tmaluh            #+#    #+#             */
/*   Updated: 2020/02/01 01:46:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTERNAL_H
# define LIBFT_INTERNAL_H

# ifndef LIBFT_INTERNAL
#  error "include only libft.h"
# endif

/*
** Internal base function for ft_strtrim and ft_strtrimcpy.
** \return counter of how much bytes to copy from start to end
**  without include whitespaces at the start and at the end of the \param s.
*/
size_t	lfti_strtrim_base(const char *restrict s);

#endif
